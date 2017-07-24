/****************************************************************************
** Meta object code from reading C++ file 'QNewSpriteDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QNewSpriteDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QNewSpriteDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QNewSpriteDialog_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNewSpriteDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNewSpriteDialog_t qt_meta_stringdata_QNewSpriteDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QNewSpriteDialog"
QT_MOC_LITERAL(1, 17, 9), // "getValues"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "QString&"
QT_MOC_LITERAL(4, 37, 2), // "id"
QT_MOC_LITERAL(5, 40, 6), // "source"
QT_MOC_LITERAL(6, 47, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(7, 71, 14) // "checkLineEdits"

    },
    "QNewSpriteDialog\0getValues\0\0QString&\0"
    "id\0source\0on_browseButton_clicked\0"
    "checkLineEdits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNewSpriteDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       6,    0,   34,    2, 0x08 /* Private */,
       7,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QNewSpriteDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNewSpriteDialog *_t = static_cast<QNewSpriteDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_browseButton_clicked(); break;
        case 2: _t->checkLineEdits(); break;
        default: ;
        }
    }
}

const QMetaObject QNewSpriteDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QNewSpriteDialog.data,
      qt_meta_data_QNewSpriteDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QNewSpriteDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNewSpriteDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QNewSpriteDialog.stringdata0))
        return static_cast<void*>(const_cast< QNewSpriteDialog*>(this));
    if (!strcmp(_clname, "Ui::QNewSpriteDialog"))
        return static_cast< Ui::QNewSpriteDialog*>(const_cast< QNewSpriteDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QNewSpriteDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
