#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QFileDialog>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFrame>
#include<QTableWidget>
#include<QTableView>
#include<QByteArray>
#include<QMouseEvent>
#include<QPoint>
#include<QTreeWidgetItem>
#include<QSystemTrayIcon>
#include<QComboBox>
#include<QTimer>
#include<QSlider>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QPixmap>
#include<QPalette>
#include<QPainter>
#include<QColor>
#include<QHeaderView>
#include<QToolBar>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QString changfilename(QString);
    QString Time(qint64 time);
protected:

public slots:
private:
    QTimer* timer;
    QSlider* slider;
    QComboBox* playstylecombox;

    QSystemTrayIcon* trayicon;

    QPushButton* imageBtn;
    QPushButton* windowminBtn;
    QPushButton* playBtn;
    QPushButton* closeBtn;
    QByteArray actionlist;
    QTableWidget* tablewidget;

    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QVideoWidget* videoWidget;
    QLabel *namelabel;
    QLabel *timelabel;
    QPushButton* stopBtn;
    QPushButton* nextBtn;
    QPushButton* lastBtn;
    QPushButton* addmusicBtn;
};

#endif // WIDGET_H
