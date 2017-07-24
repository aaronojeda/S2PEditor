/****************************************************************************
** Meta object code from reading C++ file 'QObjectsDock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QObjectsDock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QObjectsDock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QObjectsDock_t {
    QByteArrayData data[18];
    char stringdata0[419];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QObjectsDock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QObjectsDock_t qt_meta_stringdata_QObjectsDock = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QObjectsDock"
QT_MOC_LITERAL(1, 13, 32), // "on_nameCombo_currentIndexChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 4), // "text"
QT_MOC_LITERAL(4, 52, 21), // "on_editButton_clicked"
QT_MOC_LITERAL(5, 74, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(6, 98, 23), // "on_playerButton_clicked"
QT_MOC_LITERAL(7, 122, 26), // "on_leftRightButton_clicked"
QT_MOC_LITERAL(8, 149, 23), // "on_flyingButton_clicked"
QT_MOC_LITERAL(9, 173, 23), // "on_chaserButton_clicked"
QT_MOC_LITERAL(10, 197, 29), // "on_flyingChaserButton_clicked"
QT_MOC_LITERAL(11, 227, 26), // "on_scoreItemButton_clicked"
QT_MOC_LITERAL(12, 254, 27), // "on_healthItemButton_clicked"
QT_MOC_LITERAL(13, 282, 26), // "on_livesItemButton_clicked"
QT_MOC_LITERAL(14, 309, 24), // "on_keyItemButton_clicked"
QT_MOC_LITERAL(15, 334, 27), // "on_lockedDoorButton_clicked"
QT_MOC_LITERAL(16, 362, 28), // "on_levelFinishButton_clicked"
QT_MOC_LITERAL(17, 391, 27) // "on_checkPointButton_clicked"

    },
    "QObjectsDock\0on_nameCombo_currentIndexChanged\0"
    "\0text\0on_editButton_clicked\0"
    "on_deleteButton_clicked\0on_playerButton_clicked\0"
    "on_leftRightButton_clicked\0"
    "on_flyingButton_clicked\0on_chaserButton_clicked\0"
    "on_flyingChaserButton_clicked\0"
    "on_scoreItemButton_clicked\0"
    "on_healthItemButton_clicked\0"
    "on_livesItemButton_clicked\0"
    "on_keyItemButton_clicked\0"
    "on_lockedDoorButton_clicked\0"
    "on_levelFinishButton_clicked\0"
    "on_checkPointButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QObjectsDock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    0,   93,    2, 0x08 /* Private */,
       6,    0,   94,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QObjectsDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QObjectsDock *_t = static_cast<QObjectsDock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_nameCombo_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_editButton_clicked(); break;
        case 2: _t->on_deleteButton_clicked(); break;
        case 3: _t->on_playerButton_clicked(); break;
        case 4: _t->on_leftRightButton_clicked(); break;
        case 5: _t->on_flyingButton_clicked(); break;
        case 6: _t->on_chaserButton_clicked(); break;
        case 7: _t->on_flyingChaserButton_clicked(); break;
        case 8: _t->on_scoreItemButton_clicked(); break;
        case 9: _t->on_healthItemButton_clicked(); break;
        case 10: _t->on_livesItemButton_clicked(); break;
        case 11: _t->on_keyItemButton_clicked(); break;
        case 12: _t->on_lockedDoorButton_clicked(); break;
        case 13: _t->on_levelFinishButton_clicked(); break;
        case 14: _t->on_checkPointButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QObjectsDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QObjectsDock.data,
      qt_meta_data_QObjectsDock,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QObjectsDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QObjectsDock::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QObjectsDock.stringdata0))
        return static_cast<void*>(const_cast< QObjectsDock*>(this));
    if (!strcmp(_clname, "Ui::QObjectsDock"))
        return static_cast< Ui::QObjectsDock*>(const_cast< QObjectsDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int QObjectsDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
