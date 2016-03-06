#include "idetextedit.h"

IDETextEdit::IDETextEdit(QObject *parent) :
    QTextEdit(parent)
{
}

void IDETextEdit::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Return)
    {

    }
}
