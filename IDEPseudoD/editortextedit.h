#ifndef EDITORTEXTEDIT_H
#define EDITORTEXTEDIT_H

#include <QTextEdit>
#include <QFont>
#include <QEvent>
#include <QKeyEvent>
#include <QTextCursor>
#include <QPalette>
#include <QFontMetrics>
#include "pseudodsyntaxhighlighter.h"

class EditorTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    struct ConfigEditor
    {
        QTextOption::WrapMode wrapMode;
        QString               font_family;
        int                   font_size;
        Qt::GlobalColor       line_highlight_color;
        Qt::GlobalColor       background_color;
    } defaultConfig;
    explicit EditorTextEdit(QWidget *parent = 0);
    virtual ~EditorTextEdit(void);
    void updateConfig(void);
    PseudoDSyntaxHighlighter* getHighlighter(void);
signals:
    
public slots:
    void highlightCurrentLine(void);
protected:
    virtual void keyPressEvent(QKeyEvent *e);
private:
    PseudoDSyntaxHighlighter* highlighter;
};

#endif // EDITORTEXTEDIT_H
