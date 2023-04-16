#ifndef NOTED_H
#define NOTED_H

#include <QMainWindow>

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

    void on_open_triggered();

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
};
#endif // NOTED_H
