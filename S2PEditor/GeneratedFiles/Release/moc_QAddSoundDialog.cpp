/****************************************************************************
** Meta object code from reading C++ file 'QAddSoundDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QAddSoundDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QAddSoundDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QAddSoundDialog_t {
    QByteArrayData data[8];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAddSoundDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAddSoundDialog_t qt_meta_stringdata_QAddSoundDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QAddSoundDialog"
QT_MOC_LITERAL(1, 16, 9), // "getValues"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "QString&"
QT_MOC_LITERAL(4, 36, 2), // "id"
QT_MOC_LITERAL(5, 39, 6), // "source"
QT_MOC_LITERAL(6, 46, 23), // "on_browseButton_clicked"
QT_MOC_LITERAL(7, 70, 14) // "checkLineEdits"

    },
    "QAddSoundDialog\0getValues\0\0QString&\0"
    "id\0source\0on_browseButton_clicked\0"
    "checkLineEdits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAddSoundDialog[] = {

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

void QAddSoundDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QAddSoundDialog *_t = static_cast<QAddSoundDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->on_browseButton_clicked(); break;
        case 2: _t->checkLineEdits(); break;
        default: ;
        }
    }
}

const QMetaObject QAddSoundDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QAddSoundDialog.data,
      qt_meta_data_QAddSoundDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QAddSoundDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAddSoundDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QAddSoundDialog.stringdata0))
        return static_cast<void*>(const_cast< QAddSoundDialog*>(this));
    if (!strcmp(_clname, "Ui::QAddSoundDialog"))
        return static_cast< Ui::QAddSoundDialog*>(const_cast< QAddSoundDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QAddSoundDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
