#include "murmur.h"
#include "ui_murmur.h"

Murmur::Murmur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Murmur)
{
    ui->setupUi(this);

    Murmur::setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    m_player = new QMediaPlayer();

    connect(ui->b_close, &QPushButton::clicked, this, &Murmur::close);
    connect(ui->b_find, &QPushButton::clicked, this, &Murmur::onFindClicked);

    connect(ui->b_playPause, &QPushButton::clicked, this, &Murmur::onPlayClicked);
    connect(ui->b_forward, &QPushButton::clicked, this, &Murmur::onForwardClicked);
    connect(ui->b_backward, &QPushButton::clicked, this, &Murmur::onBackwardClicked);

    connect(ui->vs_volume, &QSlider::valueChanged, m_player, &QMediaPlayer::setVolume);
    connect(m_player, &QMediaPlayer::volumeChanged, this, &Murmur::changeVolume);

    connect(m_player, &QMediaPlayer::positionChanged, this, &Murmur::changePosition);
    connect(m_player, &QMediaPlayer::durationChanged, this, &Murmur::changeDuration);

    ui->vs_volume->setValue(50);
}

void Murmur::onPlayClicked()
{
    m_player->play();

    if (m_player->mediaStatus() == QMediaPlayer::NoMedia) return;

    ui->b_playPause->setText("||");
    disconnect(ui->b_playPause, &QPushButton::clicked, this, &Murmur::onPlayClicked);
    connect(ui->b_playPause, &QPushButton::clicked, this, &Murmur::onPauseClicked);
}

void Murmur::onPauseClicked()
{
    m_player->pause();
    ui->b_playPause->setText(">");
    disconnect(ui->b_playPause, &QPushButton::clicked, this, &Murmur::onPauseClicked);
    connect(ui->b_playPause, &QPushButton::clicked, this, &Murmur::onPlayClicked);
}

void Murmur::onFindClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Play music"),
                                                          QDir::homePath(),
                                                          tr("Music (*.mp3)"));
    m_player->setMedia(QUrl::fromLocalFile(filePath));
    ui->e_path->setText(filePath.remove(0, filePath.lastIndexOf("/")+1).remove(".mp3"));

    onPlayClicked();
}

void Murmur::onForwardClicked()
{
    if (m_player->position()+5*1000 <= m_player->duration())
        m_player->setPosition(m_player->position()+5*1000);
    else
        m_player->setPosition(m_player->duration());
}

void Murmur::onBackwardClicked()
{
    if (m_player->position()-5*1000 >= 0)
        m_player->setPosition(m_player->position()-5*1000);
    else
        m_player->setPosition(0);
}

void Murmur::changeVolume()
{
    ui->l_volume->setNum(m_player->volume());
}

void Murmur::changePosition()
{
    int position = m_player->position()/1000;
    int h, m, s;

    s = position%60;
    m = position/60%60;
    h = position/3600;

    QString positionText = "";

    if (h > 0) {
        positionText.append(QString::number(h));
        positionText.append(":");

        if (m < 10) positionText.append("0");
    }

    positionText.append(QString::number(m)).append(":");

    if (s < 10) positionText.append("0");

    positionText.append(QString::number(s));

    ui->l_position->setText(positionText);

    ui->pb_position->setValue(position);
}

void Murmur::changeDuration()
{
    int duration = m_player->duration()/1000;
    int h, m, s;

    s = duration%60;
    m = duration/60%60;
    h = duration/3600;

    QString durationText = "";

    if (h > 0) {
        durationText.append(QString::number(h));
        durationText.append(":");

        if (m < 10) durationText.append("0");
    }

    durationText.append(QString::number(m)).append(":");

    if (s < 10) durationText.append("0");

    durationText.append(QString::number(s));

    ui->l_duration->setText(durationText);

    ui->pb_position->setMaximum(duration);
}

Murmur::~Murmur()
{
    delete ui;
}
