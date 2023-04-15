#include "noted.h"
#include "ui_noted.h"

Noted::Noted(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noted)
{
    ui->setupUi(this);
}

Noted::~Noted()
{
    delete ui;
}

