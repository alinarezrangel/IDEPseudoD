/****************************************************************************
** Meta object code from reading C++ file 'pseudodsyntaxhighlighter.h'
**
** Created: Tue Mar 15 21:24:03 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IDEPseudoD/pseudodsyntaxhighlighter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pseudodsyntaxhighlighter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PseudoDSyntaxHighlighter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PseudoDSyntaxHighlighter[] = {
    "PseudoDSyntaxHighlighter\0\0clearAllLists()\0"
};

void PseudoDSyntaxHighlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PseudoDSyntaxHighlighter *_t = static_cast<PseudoDSyntaxHighlighter *>(_o);
        switch (_id) {
        case 0: _t->clearAllLists(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PseudoDSyntaxHighlighter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PseudoDSyntaxHighlighter::staticMetaObject = {
    { &QSyntaxHighlighter::staticMetaObject, qt_meta_stringdata_PseudoDSyntaxHighlighter,
      qt_meta_data_PseudoDSyntaxHighlighter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PseudoDSyntaxHighlighter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PseudoDSyntaxHighlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PseudoDSyntaxHighlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PseudoDSyntaxHighlighter))
        return static_cast<void*>(const_cast< PseudoDSyntaxHighlighter*>(this));
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int PseudoDSyntaxHighlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
