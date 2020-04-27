/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[20];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 18), // "on_connect_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "on_download_clicked"
QT_MOC_LITERAL(4, 47, 7), // "getdata"
QT_MOC_LITERAL(5, 55, 9), // "checkself"
QT_MOC_LITERAL(6, 65, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 82, 4), // "item"
QT_MOC_LITERAL(8, 87, 8), // "add2list"
QT_MOC_LITERAL(9, 96, 2), // "fn"
QT_MOC_LITERAL(10, 99, 2), // "sz"
QT_MOC_LITERAL(11, 102, 7), // "sendack"
QT_MOC_LITERAL(12, 110, 3), // "fid"
QT_MOC_LITERAL(13, 114, 3), // "num"
QT_MOC_LITERAL(14, 118, 11), // "datahandler"
QT_MOC_LITERAL(15, 130, 4), // "data"
QT_MOC_LITERAL(16, 135, 6), // "fndeal"
QT_MOC_LITERAL(17, 142, 6), // "resend"
QT_MOC_LITERAL(18, 149, 1), // "i"
QT_MOC_LITERAL(19, 151, 7) // "ackdeal"

    },
    "Dialog\0on_connect_clicked\0\0"
    "on_download_clicked\0getdata\0checkself\0"
    "QTreeWidgetItem*\0item\0add2list\0fn\0sz\0"
    "sendack\0fid\0num\0datahandler\0data\0"
    "fndeal\0resend\0i\0ackdeal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       8,    2,   70,    2, 0x08 /* Private */,
      11,    2,   75,    2, 0x08 /* Private */,
      14,    1,   80,    2, 0x08 /* Private */,
      16,    1,   83,    2, 0x08 /* Private */,
      17,    1,   86,    2, 0x08 /* Private */,
      19,    1,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::QByteArray,   15,
    QMetaType::Void, QMetaType::QByteArray,   15,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QByteArray,   15,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_connect_clicked(); break;
        case 1: _t->on_download_clicked(); break;
        case 2: _t->getdata(); break;
        case 3: _t->checkself((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->add2list((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->sendack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->datahandler((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->fndeal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->resend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ackdeal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
