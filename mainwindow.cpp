#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    msgBox = new QMessageBox(this);
    msgBox->setText("Invalid input. Your input must only contains at most 8 characters consist of 0s and 1s");
    msgBox->setEscapeButton(QMessageBox::Ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isValid(QString s)
{
    size_t length = 0;
    for (QChar c : s){
        length++;
        if (c != '0' && c != '1'){
            return false;
        }
    }
    if (length > 8 || length == 0){
        return false;
    }

    return true;

}

qint8 MainWindow::toDecimal(QVariant num)
{
    QString s = num.toString();
    qint8 prev = 0;

    for (QChar c : s){
        prev =  prev*2 + c.digitValue();
    }

    return prev;
}



void MainWindow::on_btn_Convert_clicked()
{
    QString input = ui->line_input->text();
    if (!isValid(input)){
        msgBox->exec();
    }
    else {
        qint8 res = toDecimal(input);
        ui->txt_output->setPlainText(QString::number(res));
    }
}

