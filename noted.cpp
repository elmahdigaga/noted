#include "noted.h"
#include "ui_noted.h"

Noted::Noted(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Noted)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);


}

Noted::~Noted()
{
    delete ui;
}

void Noted::on_newFile_triggered()
{

}


void Noted::on_open_triggered()
{

}


void Noted::on_save_triggered()
{

}


void Noted::on_saveAs_triggered()
{

}


void Noted::on_print_triggered()
{

}


void Noted::on_copy_triggered()
{

}


void Noted::on_cut_triggered()
{

}


void Noted::on_paste_triggered()
{

}


void Noted::on_undo_triggered()
{

}


void Noted::on_redo_triggered()
{

}

