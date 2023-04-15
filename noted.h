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
    Ui::Noted *ui;
};
#endif // NOTED_H
