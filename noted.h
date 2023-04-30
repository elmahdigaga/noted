#ifndef NOTED_H
#define NOTED_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Noted; }
QT_END_NAMESPACE

class Noted : public QMainWindow
{
    Q_OBJECT

public:
    Noted(QWidget *parent = nullptr);
    ~Noted();

private slots:
    void on_newFile_triggered();
    void on_openFile_triggered();
    void on_openFolder_triggered();
    void on_save_triggered();
    void on_saveAs_triggered();
    void on_copy_triggered();
    void on_cut_triggered();
    void on_paste_triggered();
    void on_undo_triggered();
    void on_redo_triggered();
    void on_treeView_clicked(const QModelIndex &index);
    void on_textEdit_textChanged();
    void on_newFilePushButton_clicked();
    void on_openFilePushButton_clicked();
    void on_openFolderPushButton_clicked();

private:
    Ui::Noted *ui;
    QString currentFilePath;
    QString currentFolderPath;
    QFileSystemModel *model;

    void setRootFolder();
    void loadFile(const QString filePath);
};
#endif // NOTED_H
