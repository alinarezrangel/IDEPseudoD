#ifndef INTABTEXTEDIT_H
#define INTABTEXTEDIT_H

#include <QWidget>
#include "pseudodsyntaxhighlighter.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "maineventfilter.h"

namespace Ui {
class InTabTextEdit;
}

class InTabTextEdit : public QWidget
{
    Q_OBJECT
    
public:
    explicit InTabTextEdit(QWidget *parent = 0);
    ~InTabTextEdit();
    bool hasChanged;
    QString fileName;
    void saveFile();
    void openFile();
    struct fileStatus
    {
        bool goodSave;
        bool goodOpen;
    } myFileStatus;
    void setAllText(QString str);
    QString getAllText(void);
    PseudoDSyntaxHighlighter* getHighlighter(void);
    QString getHTMLSource(void);
private slots:
    void on_textEdit_textChanged();

private:
    Ui::InTabTextEdit *ui;
    //PseudoDSyntaxHighlighter* highlight;
    bool editable;
    MainEventFilter *filter;
};

#endif // INTABTEXTEDIT_H
