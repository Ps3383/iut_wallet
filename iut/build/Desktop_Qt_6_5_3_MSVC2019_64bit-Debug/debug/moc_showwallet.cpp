/****************************************************************************
** Meta object code from reading C++ file 'showwallet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../showwallet.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showwallet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSshowwalletENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSshowwalletENDCLASS = QtMocHelpers::stringData(
    "showwallet",
    "on_pushButton_clicked",
    "",
    "on_shw_clicked",
    "on_buy_clicked",
    "on_sell_clicked",
    "on_increase_clicked",
    "on_decrease_clicked",
    "on_trade_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSshowwalletENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[16];
    char stringdata6[20];
    char stringdata7[20];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSshowwalletENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSshowwalletENDCLASS_t qt_meta_stringdata_CLASSshowwalletENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "showwallet"
        QT_MOC_LITERAL(11, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 14),  // "on_shw_clicked"
        QT_MOC_LITERAL(49, 14),  // "on_buy_clicked"
        QT_MOC_LITERAL(64, 15),  // "on_sell_clicked"
        QT_MOC_LITERAL(80, 19),  // "on_increase_clicked"
        QT_MOC_LITERAL(100, 19),  // "on_decrease_clicked"
        QT_MOC_LITERAL(120, 16)   // "on_trade_clicked"
    },
    "showwallet",
    "on_pushButton_clicked",
    "",
    "on_shw_clicked",
    "on_buy_clicked",
    "on_sell_clicked",
    "on_increase_clicked",
    "on_decrease_clicked",
    "on_trade_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSshowwalletENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject showwallet::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSshowwalletENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSshowwalletENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSshowwalletENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<showwallet, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_shw_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sell_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_increase_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_decrease_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_trade_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void showwallet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<showwallet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_shw_clicked(); break;
        case 2: _t->on_buy_clicked(); break;
        case 3: _t->on_sell_clicked(); break;
        case 4: _t->on_increase_clicked(); break;
        case 5: _t->on_decrease_clicked(); break;
        case 6: _t->on_trade_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *showwallet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showwallet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSshowwalletENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int showwallet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
