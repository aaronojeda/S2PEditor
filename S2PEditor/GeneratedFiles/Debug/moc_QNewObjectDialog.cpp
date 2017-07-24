/****************************************************************************
** Meta object code from reading C++ file 'QNewObjectDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QNewObjectDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QNewObjectDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QNewObjectDialog_t {
    QByteArrayData data[11];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNewObjectDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNewObjectDialog_t qt_meta_stringdata_QNewObjectDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QNewObjectDialog"
QT_MOC_LITERAL(1, 17, 9), // "getValues"
QT_MOC_LITERAL(2, 27, 10), // "GameObjCfg"
QT_MOC_LITERAL(3, 38, 0), // ""
QT_MOC_LITERAL(4, 39, 9), // "setValues"
QT_MOC_LITERAL(5, 49, 3), // "cfg"
QT_MOC_LITERAL(6, 53, 34), // "on_spriteCombo_currentIndexCh..."
QT_MOC_LITERAL(7, 88, 21), // "on_drawButton_clicked"
QT_MOC_LITERAL(8, 110, 26), // "on_newSpriteButton_clicked"
QT_MOC_LITERAL(9, 137, 16), // "checkEmptyFields"
QT_MOC_LITERAL(10, 154, 25) // "on_newSoundButton_clicked"

    },
    "QNewObjectDialog\0getValues\0GameObjCfg\0"
    "\0setValues\0cfg\0on_spriteCombo_currentIndexChanged\0"
    "on_drawButton_clicked\0on_newSpriteButton_clicked\0"
    "checkEmptyFields\0on_newSoundButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNewObjectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    3, 0x0a /* Public */,
       4,    1,   50,    3, 0x0a /* Public */,
       6,    1,   53,    3, 0x08 /* Private */,
       7,    0,   56,    3, 0x08 /* Private */,
       8,    0,   57,    3, 0x08 /* Private */,
       9,    0,   58,    3, 0x08 /* Private */,
      10,    0,   59,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, 0x80000000 | 2,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QNewObjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QNewObjectDialog *_t = static_cast<QNewObjectDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { GameObjCfg _r = _t->getValues();
            if (_a[0]) *reinterpret_cast< GameObjCfg*>(_a[0]) = _r; }  break;
        case 1: _t->setValues((*reinterpret_cast< GameObjCfg(*)>(_a[1]))); break;
        case 2: _t->on_spriteCombo_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_drawButton_clicked(); break;
        case 4: _t->on_newSpriteButton_clicked(); break;
        case 5: _t->checkEmptyFields(); break;
        case 6: _t->on_newSoundButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QNewObjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QNewObjectDialog.data,
      qt_meta_data_QNewObjectDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QNewObjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNewObjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QNewObjectDialog.stringdata0))
        return static_cast<void*>(const_cast< QNewObjectDialog*>(this));
    if (!strcmp(_clname, "Ui::QNewObjectDialog"))
        return static_cast< Ui::QNewObjectDialog*>(const_cast< QNewObjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QNewObjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
