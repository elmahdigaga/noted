#include "noted.h"
#include "ui_noted.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFileSystemModel>

Noted::Noted(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noted)
{
    ui->setupUi(this);

    #if !QT_CONFIG(clipboard)
        ui->copy->setEnabled(false);
        ui->cut->setEnabled(false);
        ui->paste->setEnabled(false);
    #endif

    model = new QFileSystemModel(this);
    model->setReadOnly(false);
    model->setFilter(QDir::AllEntries | QDir::Hidden | QDir::System);
    ui->treeView->setModel(model);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
}

Noted::~Noted()
{
    delete ui;
    delete model;
}

void Noted::on_newFile_triggered()
{
    currentFilePath.clear();
    ui->textEdit->setText(QString());
    setWindowTitle("Noted");
}

void Noted::on_openFile_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open a file");
    loadFile(filePath);
}

void Noted::on_openFolder_triggered()
{
    currentFolderPath = QFileDialog::getExistingDirectory(this, "Open a folder");
    setRootFolder();
}

void Noted::on_save_triggered()
{
    QString filePath;
    if(currentFilePath.isEmpty()) {
        filePath = QFileDialog::getSaveFileName(this, "Save");
        currentFilePath = filePath;
    } else {
        filePath = currentFilePath;
    }
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(filePath);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void Noted::on_saveAs_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannont save file: " + file.errorString());
        return;
    }
    currentFilePath = filePath;
    setWindowTitle(filePath);
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

void Noted::on_treeView_clicked(const QModelIndex &index)
{
    // Check if the index is valid and it represents a file (not a directory)
    if (!index.isValid() || model->isDir(index))
        return;

    // Get the file path from the index
    QString filePath = model->filePath(index);

    // load the contents of the file onto the text edit
    loadFile(filePath);
}


void Noted::on_textEdit_textChanged()
{
    QString title = currentFilePath + " *";
    setWindowTitle(title);
}

void Noted::setRootFolder()
{
    if(currentFolderPath.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Cannot open folder");
        return;
    }
    model->setRootPath(currentFolderPath);
    ui->treeView->setRootIndex(model->index(currentFolderPath));
}

void Noted::loadFile(const QString filePath) {
    QFile file(filePath);
    currentFilePath = filePath;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(filePath);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);

    QFileInfo fileInfo(file);
    currentFolderPath = fileInfo.dir().path();
    setRootFolder();

    file.close();
}
