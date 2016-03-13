/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Mar 13 15:18:36 2016
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Nuevo;
    QAction *actionA_brir;
    QAction *action_Guardar;
    QAction *action_Ejecutar;
    QAction *action_Mostrar_sobe_el_archivo;
    QAction *actionCon_vertir_a_HTML;
    QAction *actionA_cerca_de;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QMenu *menuC_orrector_Automatico;
    QMenu *menuO_pciones;
    QMenu *menuA_yuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(568, 391);
        action_Nuevo = new QAction(MainWindow);
        action_Nuevo->setObjectName(QString::fromUtf8("action_Nuevo"));
        actionA_brir = new QAction(MainWindow);
        actionA_brir->setObjectName(QString::fromUtf8("actionA_brir"));
        action_Guardar = new QAction(MainWindow);
        action_Guardar->setObjectName(QString::fromUtf8("action_Guardar"));
        action_Ejecutar = new QAction(MainWindow);
        action_Ejecutar->setObjectName(QString::fromUtf8("action_Ejecutar"));
        action_Mostrar_sobe_el_archivo = new QAction(MainWindow);
        action_Mostrar_sobe_el_archivo->setObjectName(QString::fromUtf8("action_Mostrar_sobe_el_archivo"));
        actionCon_vertir_a_HTML = new QAction(MainWindow);
        actionCon_vertir_a_HTML->setObjectName(QString::fromUtf8("actionCon_vertir_a_HTML"));
        actionA_cerca_de = new QAction(MainWindow);
        actionA_cerca_de->setObjectName(QString::fromUtf8("actionA_cerca_de"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 568, 29));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        menuC_orrector_Automatico = new QMenu(menuBar);
        menuC_orrector_Automatico->setObjectName(QString::fromUtf8("menuC_orrector_Automatico"));
        menuO_pciones = new QMenu(menuBar);
        menuO_pciones->setObjectName(QString::fromUtf8("menuO_pciones"));
        menuA_yuda = new QMenu(menuBar);
        menuA_yuda->setObjectName(QString::fromUtf8("menuA_yuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Archivo->menuAction());
        menuBar->addAction(menuC_orrector_Automatico->menuAction());
        menuBar->addAction(menuO_pciones->menuAction());
        menuBar->addAction(menuA_yuda->menuAction());
        menu_Archivo->addAction(action_Nuevo);
        menu_Archivo->addAction(actionA_brir);
        menu_Archivo->addAction(action_Guardar);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(action_Ejecutar);
        menuC_orrector_Automatico->addAction(action_Mostrar_sobe_el_archivo);
        menuO_pciones->addAction(actionCon_vertir_a_HTML);
        menuA_yuda->addAction(actionA_cerca_de);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IDE PseudoD", 0, QApplication::UnicodeUTF8));
        action_Nuevo->setText(QApplication::translate("MainWindow", "&Nuevo", 0, QApplication::UnicodeUTF8));
        actionA_brir->setText(QApplication::translate("MainWindow", "A&brir", 0, QApplication::UnicodeUTF8));
        action_Guardar->setText(QApplication::translate("MainWindow", "&Guardar", 0, QApplication::UnicodeUTF8));
        action_Ejecutar->setText(QApplication::translate("MainWindow", "&Ejecutar", 0, QApplication::UnicodeUTF8));
        action_Mostrar_sobe_el_archivo->setText(QApplication::translate("MainWindow", "&Mostrar sobre el archivo", 0, QApplication::UnicodeUTF8));
        actionCon_vertir_a_HTML->setText(QApplication::translate("MainWindow", "Con&vertir a HTML", 0, QApplication::UnicodeUTF8));
        actionA_cerca_de->setText(QApplication::translate("MainWindow", "A&cerca de", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindow", "&Archivo", 0, QApplication::UnicodeUTF8));
        menuC_orrector_Automatico->setTitle(QApplication::translate("MainWindow", "C&orrector Automatico", 0, QApplication::UnicodeUTF8));
        menuO_pciones->setTitle(QApplication::translate("MainWindow", "O&pciones", 0, QApplication::UnicodeUTF8));
        menuA_yuda->setTitle(QApplication::translate("MainWindow", "A&yuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
