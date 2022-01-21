#include "spinboxer.h"
#include "ui_spinboxer.h"

SpinBoxer::SpinBoxer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpinBoxer)
{
    ui->setupUi(this);

    connect(ui->sb_1, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpinBoxer::sum);
    connect(ui->sb_2, QOverload<int>::of(&QSpinBox::valueChanged), this, &SpinBoxer::sum);
}

SpinBoxer::~SpinBoxer()
{
    delete ui;
}

void SpinBoxer::sum()
{
    int sb_1_value = ui->sb_1->value();
    int sb_2_value = ui->sb_2->value();
    int sb_result_value = sb_1_value+sb_2_value;
    ui->sb_result->setValue(sb_result_value);
}
