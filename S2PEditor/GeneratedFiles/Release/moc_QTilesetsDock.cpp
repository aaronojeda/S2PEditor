/****************************************************************************
** Meta object code from reading C++ file 'QTilesetsDock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QTilesetsDock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTilesetsDock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTilesetsDock_t {
    QByteArrayData data[18];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTilesetsDock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTilesetsDock_t qt_meta_stringdata_QTilesetsDock = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QTilesetsDock"
QT_MOC_LITERAL(1, 14, 13), // "tilesetClosed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "index"
QT_MOC_LITERAL(4, 35, 20), // "on_newButton_clicked"
QT_MOC_LITERAL(5, 56, 23), // "on_zoomInButton_clicked"
QT_MOC_LITERAL(6, 80, 24), // "on_zoomOutButton_clicked"
QT_MOC_LITERAL(7, 105, 33), // "on_collisionCheckBox_stateCha..."
QT_MOC_LITERAL(8, 139, 5), // "state"
QT_MOC_LITERAL(9, 145, 28), // "on_tilePicker_currentChanged"
QT_MOC_LITERAL(10, 174, 7), // "current"
QT_MOC_LITERAL(11, 182, 31), // "on_tilePicker_tabCloseRequested"
QT_MOC_LITERAL(12, 214, 8), // "tabIndex"
QT_MOC_LITERAL(13, 223, 13), // "updateZoomBox"
QT_MOC_LITERAL(14, 237, 5), // "value"
QT_MOC_LITERAL(15, 243, 17), // "setCurrentTileset"
QT_MOC_LITERAL(16, 261, 12), // "setLabelZoom"
QT_MOC_LITERAL(17, 274, 4) // "zoom"

    },
    "QTilesetsDock\0tilesetClosed\0\0index\0"
    "on_newButton_clicked\0on_zoomInButton_clicked\0"
    "on_zoomOutButton_clicked\0"
    "on_collisionCheckBox_stateChanged\0"
    "state\0on_tilePicker_currentChanged\0"
    "current\0on_tilePicker_tabCloseRequested\0"
    "tabIndex\0updateZoomBox\0value\0"
    "setCurrentTileset\0setLabelZoom\0zoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTilesetsDock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       9,    1,   73,    2, 0x08 /* Private */,
      11,    1,   76,    2, 0x08 /* Private */,
      13,    1,   79,    2, 0x08 /* Private */,
      15,    1,   82,    2, 0x08 /* Private */,
      16,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void QTilesetsDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTilesetsDock *_t = static_cast<QTilesetsDock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tilesetClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_newButton_clicked(); break;
        case 2: _t->on_zoomInButton_clicked(); break;
        case 3: _t->on_zoomOutButton_clicked(); break;
        case 4: _t->on_collisionCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_tilePicker_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_tilePicker_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateZoomBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCurrentTileset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setLabelZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QTilesetsDock::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTilesetsDock::tilesetClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QTilesetsDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_QTilesetsDock.data,
      qt_meta_data_QTilesetsDock,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTilesetsDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTilesetsDock::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTilesetsDock.stringdata0))
        return static_cast<void*>(const_cast< QTilesetsDock*>(this));
    if (!strcmp(_clname, "Ui::QTilesetsDock"))
        return static_cast< Ui::QTilesetsDock*>(const_cast< QTilesetsDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int QTilesetsDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QTilesetsDock::tilesetClosed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
