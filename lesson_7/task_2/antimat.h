#ifndef ANTIMAT_H
#define ANTIMAT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Antimat; }
QT_END_NAMESPACE

class Antimat : public QMainWindow
{
    Q_OBJECT

public:
    Antimat(QWidget *parent = nullptr);
    ~Antimat();

private slots:
    void filterText();

private:
    Ui::Antimat *ui;
};
#endif // ANTIMAT_H
