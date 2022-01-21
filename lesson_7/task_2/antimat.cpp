#include "antimat.h"
#include "ui_antimat.h"

Antimat::Antimat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Antimat)
{
    ui->setupUi(this);

    connect (ui->e_input, &QLineEdit::textChanged, this, &Antimat::filterText);
}

Antimat::~Antimat()
{
    delete ui;
}

void Antimat::filterText()
{
    QString text = ui->e_input->text();
    if (text.lastIndexOf("fuck", -1, Qt::CaseInsensitive) != -1) {
        ui->e_input->setText(text.replace(text.lastIndexOf("fuck", -1, Qt::CaseInsensitive), 4, "****"));
        ui->statusbar->showMessage("АСУ!");
    }
    else {
        ui->statusbar->clearMessage();
    }
}
