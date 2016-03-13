#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "intabtextedit.h"
#include "pseudodsyntaxhighlighter.h"
#include <QMessageBox>
#include <QDebug>
#include <QKeySequence>
#include "ejecutor.h"
#include <QProcess>
#include "viewhtml.h"
#include <QThread>
#include "aboutwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_action_Nuevo_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionA_brir_triggered();

    void on_action_Guardar_triggered();

    void on_action_Ejecutar_triggered();

    void on_action_Mostrar_sobe_el_archivo_triggered();

    void on_actionCon_vertir_a_HTML_triggered();

    void on_actionA_cerca_de_triggered();

private:
    /*struct HighlighterTabs
    {
        int tabIndex;
        PseudoDSyntaxHighlighter* highlight;
    };*/

    Ui::MainWindow *ui;
    int iVentanaN;
    QAction* actNewFile;
    QAction* actOpenFile;
    QAction* actSaveFile;
    QAction* actExportHTML;
    //QVector<HighlighterTabs> highlighter;
};

#endif // MAINWINDOW_H
