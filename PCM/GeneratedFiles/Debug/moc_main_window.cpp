/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../main_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_main_window_t {
    QByteArrayData data[26];
    char stringdata[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_window_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_window_t qt_meta_stringdata_main_window = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 8),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 9),
QT_MOC_LITERAL(4, 32, 9),
QT_MOC_LITERAL(5, 42, 21),
QT_MOC_LITERAL(6, 64, 16),
QT_MOC_LITERAL(7, 81, 4),
QT_MOC_LITERAL(8, 86, 6),
QT_MOC_LITERAL(9, 93, 16),
QT_MOC_LITERAL(10, 110, 18),
QT_MOC_LITERAL(11, 129, 20),
QT_MOC_LITERAL(12, 150, 16),
QT_MOC_LITERAL(13, 167, 16),
QT_MOC_LITERAL(14, 184, 11),
QT_MOC_LITERAL(15, 196, 12),
QT_MOC_LITERAL(16, 209, 18),
QT_MOC_LITERAL(17, 228, 18),
QT_MOC_LITERAL(18, 247, 17),
QT_MOC_LITERAL(19, 265, 17),
QT_MOC_LITERAL(20, 283, 16),
QT_MOC_LITERAL(21, 300, 17),
QT_MOC_LITERAL(22, 318, 10),
QT_MOC_LITERAL(23, 329, 11),
QT_MOC_LITERAL(24, 341, 22),
QT_MOC_LITERAL(25, 364, 19)
    },
    "main_window\0openFile\0\0openFiles\0"
    "saveFiles\0selectedSampleChanged\0"
    "QTreeWidgetItem*\0item\0column\0"
    "setSampleVisible\0setSampleInvisible\0"
    "doSpectralClustering\0finishClustering\0"
    "doTrajClustering\0openScanner\0closeScanner\0"
    "setObjectColorMode\0setVertexColorMode\0"
    "setLabelColorMode\0setSelectToolMode\0"
    "setSceneToolMode\0setNormalToolMode\0"
    "showTracer\0clearTracer\0showSelectedTrajectory\0"
    "computeSampleNormal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x0a /* Public */,
       3,    0,  120,    2, 0x0a /* Public */,
       4,    0,  121,    2, 0x0a /* Public */,
       5,    2,  122,    2, 0x0a /* Public */,
       9,    0,  127,    2, 0x0a /* Public */,
      10,    0,  128,    2, 0x0a /* Public */,
      11,    0,  129,    2, 0x0a /* Public */,
      12,    0,  130,    2, 0x0a /* Public */,
      13,    0,  131,    2, 0x0a /* Public */,
      14,    0,  132,    2, 0x0a /* Public */,
      15,    0,  133,    2, 0x0a /* Public */,
      16,    0,  134,    2, 0x0a /* Public */,
      17,    0,  135,    2, 0x0a /* Public */,
      18,    0,  136,    2, 0x0a /* Public */,
      19,    0,  137,    2, 0x0a /* Public */,
      20,    0,  138,    2, 0x0a /* Public */,
      21,    0,  139,    2, 0x0a /* Public */,
      22,    0,  140,    2, 0x0a /* Public */,
      23,    0,  141,    2, 0x0a /* Public */,
      24,    0,  142,    2, 0x0a /* Public */,
      25,    0,  143,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Bool,
    QMetaType::Bool,
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
    QMetaType::Void,

       0        // eod
};

void main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        main_window *_t = static_cast<main_window *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->openFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->openFiles();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->saveFiles();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->selectedSampleChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: { bool _r = _t->setSampleVisible();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->setSampleInvisible();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->doSpectralClustering(); break;
        case 7: _t->finishClustering(); break;
        case 8: _t->doTrajClustering(); break;
        case 9: _t->openScanner(); break;
        case 10: _t->closeScanner(); break;
        case 11: _t->setObjectColorMode(); break;
        case 12: _t->setVertexColorMode(); break;
        case 13: _t->setLabelColorMode(); break;
        case 14: _t->setSelectToolMode(); break;
        case 15: _t->setSceneToolMode(); break;
        case 16: _t->setNormalToolMode(); break;
        case 17: _t->showTracer(); break;
        case 18: _t->clearTracer(); break;
        case 19: _t->showSelectedTrajectory(); break;
        case 20: _t->computeSampleNormal(); break;
        default: ;
        }
    }
}

const QMetaObject main_window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_main_window.data,
      qt_meta_data_main_window,  qt_static_metacall, 0, 0}
};


const QMetaObject *main_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_main_window.stringdata))
        return static_cast<void*>(const_cast< main_window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int main_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
