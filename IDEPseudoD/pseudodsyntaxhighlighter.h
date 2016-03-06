#ifndef PSEUDODSYNTAXHIGHLIGHTER_H
#define PSEUDODSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QDebug>
#include <QTimer>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextDocumentFragment>
#include <QTextLayout>

class PseudoDSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    PseudoDSyntaxHighlighter(QTextDocument* parent);
    ~PseudoDSyntaxHighlighter(void);
    QStringList getFncs(void){return this->functionsLst;}
    void asHTML(QString& html);
protected:
    void highlightBlock(const QString &text);
public slots:
    void clearAllLists(void);
public:
    bool timerAct;
    QTimer* myTimer;
    QStringList functionsLst; // Crear algo que itere sobre el textedit, al encontrar un {funcion algo} almacena {algo} en una lista
    // temporal, para despues agregarlo a functionsLst, claro que despues de hacerle clear.
private:
    struct HighlightRule
    {
        QString pattern;
        QTextCharFormat format;
    };
    QVector<HighlightRule> highlightTable;
    QTextCharFormat keywordFmt;
    QTextCharFormat stringFmt;
    QTextCharFormat typesFmt;
    QTextCharFormat instanciatorsFmt;
    QTextCharFormat functionFmt;
    QTextCharFormat commentFmt;
    QTextCharFormat errorFmt;
    QTextCharFormat clasesFmt;
    QTextCharFormat constantsFmt;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
};

#endif // PSEUDODSYNTAXHIGHLIGHTER_H
