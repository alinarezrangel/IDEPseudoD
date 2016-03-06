// Sacado de http://www.qtforum.org/article/22763/inserting-bash-in-qt.html
#include "terminal.h"

#include <QProcess>
#include <QtGui>
#include <X11/Xlib.h>

#define XTERM_CMD "/usr/bin/xterm"



Terminal::Terminal(QWidget *parent):
    QWidget(parent), cols(80), rows(30), termProcess(0)
{}


Terminal::~Terminal()
{
    close();
}


bool Terminal::tryTerminate()
{
    if(termProcess && termProcess->state() == QProcess::Running) {
        termProcess->terminate();
        return termProcess->waitForFinished();
    }

    return true;
}


void Terminal::closeEvent(QCloseEvent *e)
{
    if (!tryTerminate())
        qDebug() << "Warning: cannot terminate process";
    else
        qDebug() << "Process terminated";

    e->accept();
}


void Terminal::resizeEvent(QResizeEvent *re)
{
    QWidget::resizeEvent(re);

    if (!termProcess) return;

    // Search for xterm window and update its size
    Display *dsp = XOpenDisplay(NULL);
    Window wnd = winId();

    bool childFound = false;
    while(!childFound && termProcess->state() == QProcess::Running) {
        Window root, parent, *children;
        uint numwin;
        XQueryTree(dsp, wnd, &root, &parent, &children, &numwin);
        childFound = (children != NULL);

        if(childFound) {
            XResizeWindow(dsp, *children, width(), height());
            XFree(children);
        }
    }

    XCloseDisplay(dsp);
}


bool Terminal::isRunning()
{
    return termProcess && termProcess->state() == QProcess::Running;
}


bool Terminal::start()
{
    if(!termProcess)
        termProcess = new QProcess;

    connect(termProcess, SIGNAL(finished(int, QProcess::ExitStatus)), SLOT(termProcessExited()));

    QStringList args;
    args << "-sb" << "-geometry" << QString("%1x%2").arg(cols).arg(rows) << "-j" << "-into" << QString::number(winId());

    qDebug() << "Starting terminal with arguments '" << args.join(" ") << "'";
    termProcess->start(XTERM_CMD, args);


    int success;
    if (termProcess->waitForStarted()) {
        success = 0;
        qDebug() << "process started";
    } else
        success = -1;


    if(success == 0) {
        /* Wait for the xterm window to be opened and resize it
         * to our own widget size.
         */
        Display *dsp = XOpenDisplay(NULL);
        Window wnd = winId();

        bool childFound = false;
        while(!childFound && termProcess->state() == QProcess::Running) {
            Window root, parent, *children;
            uint numwin;
            XQueryTree(dsp, wnd, &root, &parent, &children, &numwin);
            childFound = (children != NULL);

            if(childFound) {
                XResizeWindow(dsp, *children, width(), height());
                XFree(children);
            }
        }

        XCloseDisplay(dsp);

        if(!childFound)
            success = -2;
    }


    if (success < 0) {
        qDebug() << (success == -1 ? "Starting the process failed"
                                   : "Process started, but exited before opening a terminal");

        if (success < -1)
            tryTerminate();
    }

    return success == 0;
}


void Terminal::termProcessExited()
{
    qDebug() << "termProcessExited";

    if (!termProcess) return; // ?

    delete termProcess;
    termProcess = 0;

    emit exited();
}
