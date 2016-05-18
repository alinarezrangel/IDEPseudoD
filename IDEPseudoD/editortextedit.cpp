#include "editortextedit.h"

EditorTextEdit::EditorTextEdit(QWidget *parent) :
    QTextEdit(parent)
{
    this->defaultConfig.background_color = Qt::white;
    this->defaultConfig.font_family = "Monospace";
    this->defaultConfig.font_size = 11;
    this->defaultConfig.line_highlight_color = Qt::yellow;
    this->defaultConfig.wrapMode = QTextOption::NoWrap;
    this->updateConfig();
    this->connect(this,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(highlightCurrentLine()));
    this->highlightCurrentLine();
    this->highlighter = new PseudoDSyntaxHighlighter(this->document());
    this->setTabStopWidth(4 * QFontMetrics(this->font()).width(' '));
}

EditorTextEdit::~EditorTextEdit(void)
{
    delete this->highlighter;
}

void EditorTextEdit::keyPressEvent(QKeyEvent *e)
{
    QTextEdit::keyPressEvent(e);
}

void EditorTextEdit::updateConfig(void)
{
    this->setFont(QFont(this->defaultConfig.font_family,this->defaultConfig.font_size));
    this->setWordWrapMode(this->defaultConfig.wrapMode);
    QPalette p = this->palette();
    p.setColor(QPalette::Base,QColor(this->defaultConfig.background_color));
    this->setPalette(p);
}

void EditorTextEdit::highlightCurrentLine(void)
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    if (!this->isReadOnly())
    {
        QTextEdit::ExtraSelection selection;
        QColor lineColor = QColor(this->defaultConfig.line_highlight_color).lighter(160);
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = this->textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }
    this->setExtraSelections(extraSelections);
}

PseudoDSyntaxHighlighter* EditorTextEdit::getHighlighter(void)
{
    return this->highlighter;
}
