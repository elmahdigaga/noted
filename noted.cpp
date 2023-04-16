#include "noted.h"
#include "ui_noted.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

Noted::Noted(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noted)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    #if !QT_CONFIG(clipboard)
        ui->copy->setEnabled(false);
        ui->cut->setEnabled(false);
        ui->paste->setEnabled(false);
    #endif

}

Noted::~Noted()
{
    delete ui;
}

void Noted::on_newFile_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
    setWindowTitle("Noted");
}


void Noted::on_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void Noted::on_save_triggered()
{
    QString fileName;
    if(currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void Noted::on_saveAs_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannont save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void Noted::on_copy_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}


void Noted::on_cut_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->cut();
#endif
}


void Noted::on_paste_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}


void Noted::on_undo_triggered()
{
    ui->textEdit->undo();
}


void Noted::on_redo_triggered()
{
    ui->textEdit->redo();
}
