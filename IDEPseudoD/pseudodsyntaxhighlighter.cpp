#include "pseudodsyntaxhighlighter.h"

PseudoDSyntaxHighlighter::PseudoDSyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    this->colors.strings = Qt::darkGreen;
    this->colors.keywords = Qt::darkBlue;
    this->colors.functions = Qt::darkCyan;
    this->colors.types = Qt::darkCyan;
    this->colors.instanciators = Qt::blue;
    this->colors.comments = Qt::gray;
    this->colors.errors = Qt::darkRed;
    this->colors.constants = Qt::darkYellow;
    this->colors.classes = Qt::darkCyan;
    this->updateColorRules();
    this->myTimer = new QTimer(this);
    connect(this->myTimer,SIGNAL(timeout()),this,SLOT(clearAllLists()));
    this->timerAct = false;
    //this->myTimer->start(500);
}

PseudoDSyntaxHighlighter::~PseudoDSyntaxHighlighter()
{
    delete myTimer;
}

void PseudoDSyntaxHighlighter::clearAllLists(void)
{
    this->functionsLst.clear();
    this->rehighlight();
}

void PseudoDSyntaxHighlighter::highlightBlock(const QString &text)
{
    // Gracias a http://doc.qt.io/qt-5/qtwidgets-richtext-syntaxhighlighter-example.html por parte de el codigo
    /*qDebug() << currentBlock().firstLineNumber();
    if(currentBlock().firstLineNumber() == 0)
        this->functionsLst.clear();*/
    foreach(const HighlightRule& rule, highlightTable) // const HighlightRule &rule, highlightTable
    {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            /*if(rule.format == this->functionFmt)
            {
                std::string str = text.toStdString().substr(index + 8,length);
                functionsLst.append(QString(str.c_str()));
            }*/
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    foreach(const QString& fnc, functionsLst)
    {
        QRegExp expression(tr("\\b(") + fnc + tr(")\\b"));
        int index = expression.indexIn(text);
        while (index >= 0)
        {
            int length = expression.matchedLength();
            setFormat(index, length, this->functionFmt);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);
    while (startIndex >= 0)
    {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1)
        {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        }
        else
        {
            commentLength = endIndex - startIndex + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, commentFmt);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

void PseudoDSyntaxHighlighter::asHTML(QString &html)
{
    QTextCursor cursor(document());
    cursor.select(QTextCursor::Document);
    QTextDocument* tempDocument(new QTextDocument);
    Q_ASSERT(tempDocument);
    QTextCursor tempCursor(tempDocument);

    tempCursor.insertFragment(cursor.selection());
    tempCursor.select(QTextCursor::Document);
    // Set the default foreground for the inserted characters.
    QTextCharFormat textfmt = tempCursor.charFormat();
    textfmt.setForeground(Qt::black);
    tempCursor.setCharFormat(textfmt);

    // Apply the additional formats set by the syntax highlighter
    QTextBlock start = document()->findBlock(cursor.selectionStart());
    QTextBlock end = document()->findBlock(cursor.selectionEnd());
    end = end.next();
    const int selectionStart = cursor.selectionStart();
    const int endOfDocument = tempDocument->characterCount() - 1;
    for(QTextBlock current = start; current.isValid() and current not_eq end; current = current.next()) {
        const QTextLayout* layout(current.layout());

        foreach(const QTextLayout::FormatRange &range, layout->additionalFormats()) {
            const int start = current.position() + range.start - selectionStart;
            const int end = start + range.length;
            if(end <= 0 or start >= endOfDocument)
                continue;
            tempCursor.setPosition(qMax(start, 0));
            tempCursor.setPosition(qMin(end, endOfDocument), QTextCursor::KeepAnchor);
            tempCursor.setCharFormat(range.format);
        }
    }

    // Reset the user states since they are not interesting
    for(QTextBlock block = tempDocument->begin(); block.isValid(); block = block.next())
        block.setUserState(-1);

    // Make sure the text appears pre-formatted, and set the background we want.
    tempCursor.select(QTextCursor::Document);
    QTextBlockFormat blockFormat = tempCursor.blockFormat();
    blockFormat.setNonBreakableLines(true);
    blockFormat.setBackground(Qt::white);
    tempCursor.setBlockFormat(blockFormat);

    // Finally retreive the syntax higlighted and formatted html.
    html = tempCursor.selection().toHtml();
    delete tempDocument;
}

void PseudoDSyntaxHighlighter::updateColorRules(void)
{
    this->stringFmt.setForeground(this->colors.strings);
    this->keywordFmt.setFontWeight(QFont::Bold);
    this->keywordFmt.setForeground(this->colors.keywords);
    this->functionFmt.setFontItalic(true);
    this->functionFmt.setForeground(this->colors.functions);
    this->typesFmt.setFontWeight(QFont::Bold);
    this->typesFmt.setForeground(this->colors.types);
    this->instanciatorsFmt.setForeground(this->colors.instanciators);
    this->commentFmt.setForeground(this->colors.comments);
    this->errorFmt.setForeground(this->colors.errors);
    this->constantsFmt.setForeground(this->colors.constants);
    this->constantsFmt.setFontWeight(QFont::Bold);
    this->clasesFmt.setForeground(this->colors.classes);
    this->highlightTable.clear();
    HighlightRule rule;
    rule.pattern = "\\b([A-Z0-9_-+]+)\\b";
    rule.format = this->constantsFmt;
    this->highlightTable.append(rule);
    rule.pattern = "funcion .+";
    rule.format = this->functionFmt;
    this->highlightTable.append(rule);
    rule.pattern = "clase .+";
    rule.format = this->clasesFmt;
    this->highlightTable.append(rule);
    rule.pattern = "utilizar .+";
    rule.format = this->stringFmt;
    this->highlightTable.append(rule);
    rule.pattern = "\\b(fijar|oper(ador)?|escribir(_esp)?|n(l|o)|funcion|sistema|llamar|clase|estructura|(in|de)crementar_p(untero)?|utilizar|sal(ir)?|ejecutar|leer|comparar(_i)?|son(_iguales)?|iguales|diferentes|sean|fin(fun|bucle)?|si((_)?no)?|heredar|mientras|redireccionar|empujar|sacar|recibir_(parametro|resultado)|enviar_parametro|crear_pila|es|devolver|Importar\\.[^ ]+)\\b";
    rule.format = this->keywordFmt;
    this->highlightTable.append(rule);
    rule.pattern = "(\\b(Objeto|PseudoVariable|PseudoFuncion|PunteroInteligente|Referencia|Programa|Fraccion|Numero|Decimal|Boole|BufferTexto|BibliotecaDinamica|Iterador|IteradorDel|IteradorTra|IteradorBi|Par|Arreglo|IteradorArreglo|#[a-zA-ZñÑ0-9_-\\(\\)\\[\\]!?]+)\\b|#\\(Final\\)\\.)";
    rule.format = this->typesFmt;
    this->highlightTable.append(rule);
    rule.pattern = "\\b(adquirir|puntero|liberar|instancia)\\b";
    rule.format = this->instanciatorsFmt;
    this->highlightTable.append(rule);
    rule.pattern = "\\b(estoEsUnHuevoDePascuaEnIDEPseudoD|si_no|oper(ador)?|estructura|contiene)\\b";
    rule.format = this->errorFmt;
    this->highlightTable.append(rule);
    rule.pattern = " \\=\\* .+$";
    rule.format = this->stringFmt;
    this->highlightTable.append(rule);
    this->commentStartExpression.setPattern("\\[");
    this->commentEndExpression.setPattern("\\]");
}
