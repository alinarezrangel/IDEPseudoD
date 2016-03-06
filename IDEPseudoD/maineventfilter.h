#ifndef MAINEVENTFILTER_H
#define MAINEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QTextEdit>
#include <QDebug>

class MainEventFilter : public QObject
{
    Q_OBJECT
public:
    MainEventFilter();
protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINEVENTFILTER_H
