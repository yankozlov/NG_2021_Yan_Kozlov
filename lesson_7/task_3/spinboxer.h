#ifndef SPINBOXER_H
#define SPINBOXER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpinBoxer; }
QT_END_NAMESPACE

class SpinBoxer : public QMainWindow
{
    Q_OBJECT

public:
    SpinBoxer(QWidget *parent = nullptr);
    ~SpinBoxer();

private slots:
    void sum();

private:
    Ui::SpinBoxer *ui;
};
#endif // SPINBOXER_H
