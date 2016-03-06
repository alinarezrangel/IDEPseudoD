#ifndef IDETEXTEDIT_H
#define IDETEXTEDIT_H

#include <QTextEdit>

class IDETextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit IDETextEdit(QObject *parent = 0);
    
signals:
    
public slots:
    virtual void keyPressEvent(QKeyEvent *e);
};

#endif // IDETEXTEDIT_H
