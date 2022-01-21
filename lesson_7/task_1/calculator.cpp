#include "calculator.h"
#include "ui_calculator.h"
#include <mathparser.h>
#include <strings.h>
#include <QDebug>
//fix comma
//string calculate();

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->b_0, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_1, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_2, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_3, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_4, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_5, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_6, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_7, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_8, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_9, &QPushButton::clicked, this, &Calculator::inputButtonClicked);

    connect(ui->b_comma,    &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_divide,   &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_multiply, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_plus,     &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_minus,    &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_bracketL, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_bracketR, &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_sqRoot,   &QPushButton::clicked, this, &Calculator::inputButtonClicked);
    connect(ui->b_power,    &QPushButton::clicked, this, &Calculator::inputButtonClicked);

    connect(ui->b_clear, &QPushButton::clicked, ui->e_text, &QLineEdit::clear);
    connect(ui->b_backspace, &QPushButton::clicked, this, &Calculator::b_backspace_clicked);

    connect(ui->b_result, &QPushButton::clicked, this, &Calculator::showResult);

    connect(ui->e_text, &QLineEdit::textChanged, this, &Calculator::formatInput);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::inputButtonClicked()
{
    QPushButton *button = (QPushButton *)sender();
    ui->e_text->setText(ui->e_text->text()+button->text());
}

void Calculator::b_backspace_clicked()
{
    QString text = ui->e_text->text();

    if (text.isEmpty() == false) ui->e_text->setText(text.remove(text.size()-1, 1));
}

void Calculator::formatInput()
{
    QString text = ui->e_text->text();

    if (text.lastIndexOf("**") != -1) ui->e_text->setText(text.replace("**", "^"));

    if (text.lastIndexOf(",,") != -1) ui->e_text->setText(text.replace(",,", ","));

    text = ui->e_text->text();
}


void Calculator::showResult()
{
    QString qsequation = ui->e_text->text();
    //ui->e_text->clear();
    ui->e_text->setText("result");

    string sequation = qsequation.toStdString();
    char* res = equationResult(sequation);


    qDebug() << qsequation;

    qDebug() << res;
/*
    string resultString = equation;

    qDebug() << QString::fromStdString(resultString);



    QString result = QString::fromStdString(resultString);

    ui->e_text->setText(ui->e_text->text()+"="+result);
*/
}
