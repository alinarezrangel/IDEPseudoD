#ifndef VIEWHTML_H
#define VIEWHTML_H

#include <QDialog>
#include <QDebug>
#include <QClipboard>

namespace Ui {
class ViewHTML;
}

class ViewHTML : public QDialog
{
    Q_OBJECT
    
public:
    explicit ViewHTML(QWidget *parent = 0);
    ~ViewHTML();
    void setHTML(QString &);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewHTML *ui;
};

#endif // VIEWHTML_H
