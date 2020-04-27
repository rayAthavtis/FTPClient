#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QtNetwork>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_connect_clicked();
    void on_download_clicked();
    void getdata();
    void checkself(QTreeWidgetItem *item);
    void add2list(QString fn, QString sz);
    void sendack(int fid, int num);
    void datahandler(QByteArray data);
    void fndeal(QByteArray data);
    void resend(int i);
    void ackdeal(QByteArray data);

private:
    Ui::Dialog *ui;
    QUdpSocket *clientsock;
    int curnum[5];  //接收到第几块
    QString filename[5];  //下载文件名
    int curfile;
    QTimer *timer[3];  //定时器
    int timernum[3];  //定时器id对应，触发超时重传
    int newt;  //当前定时器
    quint16 pt;
    QHostAddress severip;
    quint16 severpt;  //服务器给分的端口号，默认为服务器公共端口
    int filesize;
    int step;
    int curstep;
    QByteArray buff;
};
#endif // DIALOG_H
