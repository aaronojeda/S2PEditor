/****************************************************************************
** Meta object code from reading C++ file 'QLevelsDock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QLevelsDock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QLevelsDock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QLevelsDock_t {
    QByteArrayData data[15];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLevelsDock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLevelsDock_t qt_meta_stringdata_QLevelsDock = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QLevelsDock"
QT_MOC_LITERAL(1, 12, 9), // "loadLevel"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 2), // "id"
QT_MOC_LITERAL(4, 26, 6), // "source"
QT_MOC_LITERAL(5, 33, 11), // "deleteLevel"
QT_MOC_LITERAL(6, 45, 11), // "saveAndLoad"
QT_MOC_LITERAL(7, 57, 28), // "on_deleteLevelButton_clicked"
QT_MOC_LITERAL(8, 86, 24), // "on_levelUpButton_clicked"
QT_MOC_LITERAL(9, 111, 26), // "on_levelDownButton_clicked"
QT_MOC_LITERAL(10, 138, 31), // "on_levelList_currentItemChanged"
QT_MOC_LITERAL(11, 170, 30), // "on_levelList_itemDoubleClicked"
QT_MOC_LITERAL(12, 201, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(13, 218, 4), // "item"
QT_MOC_LITERAL(14, 223, 21) // "on_loadButton_clicked"

    },
    "QLevelsDock\0loadLevel\0\0id\0source\0"
    "deleteLevel\0saveAndLoad\0"
    "on_deleteLevelButton_clicked\0"
    "on_levelUpButton_clicked\0"
    "on_levelDownButton_clicked\0"
    "on_levelList_currentItemChanged\0"
    "on_levelList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_loadButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLevelsDock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    2,   64,    2, 0x06 /* Public */,
       6,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void QLevelsDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QLevelsDock *_t = static_cast<QLevelsDock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadLevel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->deleteLevel((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->saveAndLoad((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_deleteLevelButton_clicked(); break;
        case 4: _t->on_levelUpButton_clicked(); break;
        case 5: _t->on_levelDownButton_clicked(); break;
        case 6: _t->on_levelList_currentItemChanged(); break;
        case 7: _t->on_levelList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_loadButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QLevelsDock::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QLevelsDock::loadLevel)) {
                *result = 0;
            }
        }
        {
            typedef void (QLevelsDock::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QLevelsDock::deleteLevel)) {
                *result = 1;
            }
        }
        {
            typedef void (QLevelsDock::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QLevelsDock::saveAndLoad)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject QLevelsDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QLevelsDock.data,
      qt_meta_data_QLevelsDock,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QLevelsDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLevelsDock::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QLevelsDock.stringdata0))
        return static_cast<void*>(const_cast< QLevelsDock*>(this));
    if (!strcmp(_clname, "Ui::QLevelsDock"))
        return static_cast< Ui::QLevelsDock*>(const_cast< QLevelsDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int QLevelsDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QLevelsDock::loadLevel(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLevelsDock::deleteLevel(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QLevelsDock::saveAndLoad(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
