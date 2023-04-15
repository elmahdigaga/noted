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

private:
    void newFile();
    void open();
    void save();
    void saveAs();
    void print();
    void exit();
    void copy();
    void paste();
    void cut();
    void undo();
    void redo();
    void about();

private:
    Ui::Noted *ui;
    QString currentFile;
};
#endif // NOTED_H
