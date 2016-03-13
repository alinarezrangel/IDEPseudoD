#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->iVentanaN = 1;
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);
    actSaveFile = new QAction(QIcon("/usr/share/idepseudod/Iconos/guardar.svg"),"&Guardar",this);
    actSaveFile->setShortcuts(QKeySequence::Save);
    actSaveFile->setStatusTip("Save the actual file");
    ui->mainToolBar->addAction(actSaveFile);
    connect(actSaveFile, SIGNAL(triggered()), this, SLOT(on_action_Guardar_triggered()));
    actNewFile = new QAction(QIcon("/usr/share/idepseudod/Iconos/nuevo.svg"),"&Nuevo",this);
    actNewFile->setShortcuts(QKeySequence::New);
    actNewFile->setStatusTip("Create a new file");
    ui->mainToolBar->addAction(actNewFile);
    connect(actNewFile, SIGNAL(triggered()), this, SLOT(on_action_Nuevo_triggered()));
    actOpenFile = new QAction(QIcon("/usr/share/idepseudod/Iconos/abrir.svg"),"&Abrir",this);
    actOpenFile->setShortcuts(QKeySequence::Open);
    actOpenFile->setStatusTip("Open a file");
    ui->mainToolBar->addAction(actOpenFile);
    connect(actOpenFile, SIGNAL(triggered()), this, SLOT(on_actionA_brir_triggered()));
    ui->mainToolBar->addSeparator();
    actExportHTML = new QAction(QIcon("/usr/share/idepseudod/Iconos/exportar_html.svg"),"&Exportar",this);
    actExportHTML->setStatusTip("Export as HTML file");
    ui->mainToolBar->addAction(actExportHTML);
    connect(actExportHTML, SIGNAL(triggered()), this, SLOT(on_actionCon_vertir_a_HTML_triggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete actSaveFile;
}

void MainWindow::on_action_Nuevo_triggered()
{
    InTabTextEdit* textEdit = new InTabTextEdit(this);
    //HighlighterTabs hltabs;
    //hltabs.highlight = new PseudoDSyntaxHighlighter(textEdit);
    /*hltabs.tabIndex = */ ui->tabWidget->addTab(textEdit,"Sin titulo " + QString::number(this->iVentanaN++));
    //highlighter.append(hltabs);
    //qDebug() << "Added a highlighter in tab " << hltabs.tabIndex;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if((ui->tabWidget->currentWidget() != 0)&&(((InTabTextEdit)ui->tabWidget->currentWidget()).hasChanged))
    {
        if(QMessageBox::question(this,"Guardar antes de salir","Este documento no ha sido guardado, ¿seguro que quieres cerrarlo?(perderas tus cambios)",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Cancel)
        {
            ((InTabTextEdit*)ui->tabWidget->currentWidget())->saveFile();
        }
    }
    ui->tabWidget->removeTab(index);
    /*int buff = 0;
    for(int i = 0;i < highlighter.size();i++)
    {
        if(highlighter[i].tabIndex == index)
        {
            qDebug() << "Deleted a highlighter in tab " << highlighter[i].tabIndex;
            delete highlighter[i].highlight;
            highlighter.remove(i);
            buff = i;
            break;
        }
    }
    for(int i = buff;i < highlighter.size();i++)
    {
        highlighter[i].tabIndex--;
        qDebug() << "Decremented the tab " << highlighter[i].tabIndex + 1;
    }*/
}

void MainWindow::on_actionA_brir_triggered()
{
    on_action_Nuevo_triggered();
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    qDebug() << "Abrir triggered";
    if(ui->tabWidget->currentWidget() == 0)
        return;
    if(ui->tabWidget->currentIndex() == -1)
        return;
    qDebug() << "Executed";
    ((InTabTextEdit*)ui->tabWidget->currentWidget())->openFile();
    if(!((InTabTextEdit*)ui->tabWidget->currentWidget())->myFileStatus.goodOpen)
        return;
    qDebug() << "Nice11";
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),((InTabTextEdit*)ui->tabWidget->currentWidget())->fileName);
    qDebug() << "Nice22";
}

void MainWindow::on_action_Guardar_triggered()
{
    if(ui->tabWidget->currentWidget() == 0)
        return;
    if(ui->tabWidget->currentIndex() == -1)
        return;
    ((InTabTextEdit*)ui->tabWidget->currentWidget())->saveFile();
    if(!((InTabTextEdit*)ui->tabWidget->currentWidget())->myFileStatus.goodSave)
        return;
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),((InTabTextEdit*)ui->tabWidget->currentWidget())->fileName);
}

void MainWindow::on_action_Ejecutar_triggered()
{
    if(ui->tabWidget->currentWidget() == 0)
        return;
    if(ui->tabWidget->currentIndex() == -1)
        return;
    ejecutor* exec = new ejecutor(((InTabTextEdit*)ui->tabWidget->currentWidget())->fileName,this);
    exec->exec();
    delete exec;
}

void MainWindow::on_action_Mostrar_sobe_el_archivo_triggered()
{
    if(ui->tabWidget->currentWidget() == 0)
        return;
    if(ui->tabWidget->currentIndex() == -1)
        return;
    InTabTextEdit* tabEdit = (InTabTextEdit*)ui->tabWidget->currentWidget();
}

void MainWindow::on_actionCon_vertir_a_HTML_triggered()
{
    if(ui->tabWidget->currentWidget() == 0)
        return;
    if(ui->tabWidget->currentIndex() == -1)
        return;
    InTabTextEdit* tabEdit = (InTabTextEdit*)ui->tabWidget->currentWidget();
    ViewHTML* viewer = new ViewHTML(this);
    QString html;
    tabEdit->getHighlighter()->asHTML(html);
    viewer->setHTML(html);
    viewer->exec();
    delete viewer;
}

void MainWindow::on_actionA_cerca_de_triggered()
{
    AboutWindow about;
    about.exec();
}
