/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QTreeWidget *filelist;
    QTextBrowser *logshow;
    QLabel *label_2;
    QPushButton *connect;
    QPushButton *download;
    QPushButton *cancel;
    QProgressBar *progressBar;
    QLabel *label_3;
    QLineEdit *fileselect;
    QLabel *label_4;
    QLineEdit *portselect;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(695, 516);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 71, 31));
        filelist = new QTreeWidget(Dialog);
        filelist->setObjectName(QString::fromUtf8("filelist"));
        filelist->setGeometry(QRect(20, 230, 651, 181));
        logshow = new QTextBrowser(Dialog);
        logshow->setObjectName(QString::fromUtf8("logshow"));
        logshow->setGeometry(QRect(20, 70, 651, 121));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 200, 81, 31));
        connect = new QPushButton(Dialog);
        connect->setObjectName(QString::fromUtf8("connect"));
        connect->setGeometry(QRect(560, 200, 112, 32));
        download = new QPushButton(Dialog);
        download->setObjectName(QString::fromUtf8("download"));
        download->setGeometry(QRect(440, 450, 112, 31));
        cancel = new QPushButton(Dialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(560, 450, 112, 31));
        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 420, 651, 23));
        progressBar->setValue(24);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 450, 91, 31));
        fileselect = new QLineEdit(Dialog);
        fileselect->setObjectName(QString::fromUtf8("fileselect"));
        fileselect->setGeometry(QRect(90, 450, 341, 31));
        fileselect->setReadOnly(true);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 71, 16));
        portselect = new QLineEdit(Dialog);
        portselect->setObjectName(QString::fromUtf8("portselect"));
        portselect->setGeometry(QRect(90, 20, 113, 21));

        retranslateUi(Dialog);
        QObject::connect(cancel, SIGNAL(clicked()), Dialog, SLOT(close()));
        QObject::connect(progressBar, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "FTP\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\346\227\245\345\277\227", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = filelist->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Dialog", "\345\244\247\345\260\217", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Dialog", "\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\346\226\207\344\273\266\345\210\227\350\241\250", nullptr));
        connect->setText(QCoreApplication::translate("Dialog", "\350\277\236\346\216\245", nullptr));
        download->setText(QCoreApplication::translate("Dialog", "\344\270\213\350\275\275", nullptr));
        cancel->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\351\200\211\344\270\255\346\226\207\344\273\266\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\347\253\257\345\217\243\351\200\211\346\213\251\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
