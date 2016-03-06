#include "maineventfilter.h"

MainEventFilter::MainEventFilter()
{
}

bool MainEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* e = static_cast<QKeyEvent*>(event);
        qDebug("Key pressed %s",e->key());
        return true;
    }
    else
    {
        return QObject::eventFilter(obj,event);
    }
}
