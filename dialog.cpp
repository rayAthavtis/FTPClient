#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //初始化
    clientsock = new QUdpSocket(this);
    for(int i = 0; i<5; i++)
        curnum[i] = 0;
    for(int i = 0; i < 3; i++)
    {
        timer[i] = new QTimer;
        timer[i]->setInterval(1000);  //设置时限
        timer[i]->setSingleShot(true);
        timernum[i] = -1;
        connect(timer[i],&QTimer::timeout,this,[=]{resend(i);});
    }
    curfile = 0;
    newt = 0;
    filesize = 0;
    step = 0;
    curstep = 0;
    severip = QHostAddress::Broadcast;
    severpt = 11005;  //默认服务器端口
    ui->logshow->append("****** 客户端就绪 ******");
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(1);
    connect(clientsock,SIGNAL(readyRead()),this,SLOT(getdata()));  //读取数据
    connect(ui->filelist,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,
            SLOT(checkself(QTreeWidgetItem*)));
}

Dialog::~Dialog()
{
    delete ui;
}

//连接，请求获取文件目录
void Dialog::on_connect_clicked()  //发送自己的端口好并获取文件目录请求
{
    QString port = ui->portselect->text();
    if(port.isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("请选择客户端端口！"));
        return ;
    }
    pt = port.toUShort();
    //绑定到端口，需与服务器端口一致才能保证接收到数据报，ShareAddress为绑定模式
    clientsock->bind(pt,QUdpSocket::ShareAddress);
    QByteArray data = "0\r\nhello server. ";
    //四个参数分别是数据报的内容，数据报的大小，主机地址和端口号
    clientsock->writeDatagram(data.data(),data.size(),QHostAddress::Broadcast,severpt);  //广播
    ui->logshow->append("请求文件列表。");
    timer[0]->start();  //开始计时
}

void Dialog::resend(int i)
{
    ui->logshow->append("请求超时。");
    if(i == 0)
    {
        ui->logshow->append("重新申请文件列表。");
        QByteArray data = "0\r\nhello server. ";
        clientsock->writeDatagram(data.data(),data.size(),severip,severpt);  //广播
        ui->logshow->append("重新请求文件列表。");
        timer[0]->start();  //开始计时
    }
    else if(i == 1)
        ui->logshow->append("请重新下载。");
    else if(i == 2)
        ui->logshow->append("重传请求失败。");
}

//开始下载
void Dialog::on_download_clicked()  //下载文件请求
{
    for(int i = 0; i < 5; i++)
        curnum[i] = 0;
    curstep = 0;
    int stp = filesize%512;
    step = filesize/512;
    if(stp != 0)
        step += 1;
    if(100%step != 0)
        step = 100/step + 1;
    else
        step = 100/step;
    ui->progressBar->reset();  //重置
    //获取文件信息
    QString tmp = ui->fileselect->text();
    if(tmp.isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("请选择下载文件名！"));
        return ;
    }
    QString qs = "2\r\n" + tmp;
    QByteArray data = qs.toLocal8Bit();
    //四个参数分别是数据报的内容，数据报的大小，主机地址和端口号
    clientsock->writeDatagram(data.data(),data.size(),severip,severpt);
    ui->logshow->append("请求下载文件。");
    timer[1]->start();  //可复用,为区分这里不复用
}

void Dialog::sendack(int fid, int num)
{
    QString tmp = "4\r\n" + QString::number(fid) + "\r\n" + QString::number(num);
    QByteArray sp = tmp.toLocal8Bit();
    clientsock->writeDatagram(sp.data(),sp.size(),severip,severpt);
}

void Dialog::ackdeal(QByteArray data)
{
    QString tmp = data;
    QStringList tp = tmp.split("\r\n");
    if(tp.at(1) == "-1" && tp.at(2) == "0")  //文件列表请求信息ack
    {
        ui->logshow->append("服务器成功接收文件列表请求。");
        timer[0]->stop();  //关闭计时
    }
    else if(tp.at(1) == "-1" && tp.at(2) == "1")  //文件下载请求ack
    {
        ui->logshow->append("服务器成功接收下载请求。");
        timer[1]->stop();  //关闭计时
    }
    else if(tp.at(1) == "-1" && tp.at(2) == "2")  //文件重传请求ack
    {
        ui->logshow->append("服务器成功接收重传请求。");
        timer[2]->stop();  //关闭计时
    }
}

void Dialog::datahandler(QByteArray data)  //op+fid+num+len+data
{
    QString dt = data;
    QStringList datalist = dt.split("\r\n");
    int fid = datalist.at(1).toInt();  //文件id
    int num = datalist.at(2).toInt();  //文件块号
    int len = datalist.at(3).toInt();  //数据长度
    sendack(fid, num);  //通告num块已接收以通知服务器关闭计时器，收到多余的也做相同处理
    QString cont = datalist.at(4);  //数据
    for(int i = 5; i < datalist.size(); i++)
        cont += "\r\n" + datalist.at(i);
    if(num == curnum[fid])  //收到正确块
    {
        QString fn = filename[fid];
        ui->logshow->append("成功接收：" + fn + "-" + QString::number(curnum[fid]));
        QString asfn = "/Users/renlei/Qt-workspace/saves/" + QString::number(pt%3)
                + "/" + fn;
        curnum[fid] += 1;
        if(fn.right(3) == "txt")
        {
            QFile file(asfn);
            if(file.exists() && num == 0)
                file.remove();
            if(!file.open(QIODevice::ReadWrite))
            {
                ui->logshow->append("文件打开失败！");
                return ;
            }
            QTextStream out(&file);
            out.seek(file.size());
            //写入文件
            out<<cont.toLocal8Bit();
            curstep += step;
            ui->progressBar->setValue(curstep);
            if(len < 512)  //最后一块
                ui->progressBar->setValue(100);
            file.close();
        }
        else if(fn.right(3) == "jpg" || fn.right(3) == "png")
        {
            QByteArray con = data.right(len);
            QFile file(asfn);
            if(file.exists() && num == 0)
                file.remove();
            if(!file.open(QIODevice::ReadWrite))
            {
                ui->logshow->append("文件打开失败！");
                return ;
            }
            QDataStream in(&file);
            in.skipRawData(file.size());
            in.writeRawData(con,len);
            file.close();
        }
    }
    else  //乱序
    {
        //请求从当前块开始重发之后所有报文
        QString tmp = "6\r\n" + QString::number(fid) + "\r\n" +
                QString::number(curnum[fid]);
        QByteArray pack = tmp.toLocal8Bit();
        clientsock->writeDatagram(data.data(),data.size(),severip,severpt);
        ui->logshow->append("请求重发：" + filename[fid] + "-" +
                            QString::number(curnum[fid]));
        timer[2]->start();
    }
}

void Dialog::fndeal(QByteArray data)  //op+fn+sz
{
    QString tmp = data;
    QStringList tp = tmp.split("\r\n");
    add2list(tp.at(1), tp.at(2));
}

void Dialog::getdata()  //接收数据统一处理
{
    while(clientsock->hasPendingDatagrams())  //拥有等待的数据
    {
        QByteArray data;  //用于存放接收的数据
        qint64 size = clientsock->pendingDatagramSize();
        data.resize(size);
        clientsock->readDatagram(data.data(),size,&severip,&severpt);
        if(data.at(0) == '1')  //文件信息回复
        {
            fndeal(data);
            ui->connect->setEnabled(false);  //连接按钮设置为不可用
        }
        else if(data.at(0) == '3')  //收到文件数据
            datahandler(data);
        else if(data.at(0) == '5')  //收到ack
            ackdeal(data);
    }
}

void Dialog::add2list(QString fn, QString sz)
{
    sendack(-1,2);
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, fn);
    item->setText(1, sz);
    QPixmap pixmap(":/new/prefix1/apple.png");
    item->setIcon(0, pixmap);
    ui->filelist->addTopLevelItem(item);
    filename[curfile] = fn;
    curfile += 1;
}

void Dialog::checkself(QTreeWidgetItem *item)
{
    ui->fileselect->clear();  //清空文本
    QStringList filepath;
    QStringList fs;
    QTreeWidgetItem *itemfile = item;  //获取点击选择的文件
    while(itemfile != nullptr)
    {
        filepath<<itemfile->text(0);  //获取点击文件
        fs<<itemfile->text(1);
        itemfile = itemfile->parent();  //父节点
    }
    //其实没用上，因为都是一个目录下的文件
    QString path;
    for(int i = (filepath.size()-1); i >= 0; i--)
    {
        path += filepath.at(i);
        if(i != 0)
            path += "/";
    }
    filesize = fs.at(0).toInt();
    ui->fileselect->insert(path);  //显示选择的文件
}
