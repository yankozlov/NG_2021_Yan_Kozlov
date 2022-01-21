#ifndef calculator_H
#define calculator_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:

    void inputButtonClicked();

    void b_backspace_clicked();

    void formatInput();

    void showResult();

private:
    bool enableComma = true;
    bool commaTyped = false;

    Ui::Calculator *ui;
};
#endif // calculator_H
