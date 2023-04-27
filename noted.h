#ifndef NOTED_H
#define NOTED_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Noted; }
QT_END_NAMESPACE
/*
class FileSystemModel : public QFileSystemModel {
public:
    FileSystemModel(QObject *parent = nullptr) : QFileSystemModel(parent) {}

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        return QFileSystemModel::flags(index) | Qt::ItemIsEditable;
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if(role == Qt::DisplayRole && index.column() == 0) {
            return QFileInfo(QFileSystemModel::data(index, role).toString()).fileName();
        }
        return QFileSystemModel::data(index, role);
    }
};
*/
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

private:
    Ui::Noted *ui;
    QString currentFile;
    QString currentFolderPath;
    QFileSystemModel *model;

    void setRootFolder();
};
#endif // NOTED_H
