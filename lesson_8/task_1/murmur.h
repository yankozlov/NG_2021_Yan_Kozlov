#ifndef MURMUR_H
#define MURMUR_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QDir>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Murmur; }
QT_END_NAMESPACE

class Murmur : public QMainWindow
{
    Q_OBJECT

public:
    Murmur(QWidget *parent = nullptr);
    ~Murmur();


private slots:
    void onPlayClicked();
    void onPauseClicked();
    void onFindClicked();

    void onForwardClicked();
    void onBackwardClicked();

    void changeVolume();
    void changePosition();
    void changeDuration();

private:
    Ui::Murmur *ui;
    QMediaPlayer *m_player;
};
#endif // MURMUR_H
