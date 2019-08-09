 #include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMinimumSize(1000,600);
    setAutoFillBackground(true);
   // this->setStyleSheet("Widget{border-image:url(://pic/背景.png)}");
        QPalette pal = this->palette();
    //    pal.setColor(QPalette::Background, QColor(19, 54, 118));
        QPixmap pixmap("://pic/背景.png");
        QSize size(1000,600);
        pal.setBrush(QPalette::Window, QBrush(pixmap.scaled(size, Qt::IgnoreAspectRatio,
                              Qt::SmoothTransformation)));
        setPalette(pal);
        this->setWindowOpacity(0.9);


    //进度条
    slider=new QSlider(Qt::Horizontal,this);
    slider->setValue(0);
    slider->setMaximum(100);


    slider->setStyleSheet("QSlider::groove:horizontal {border: 0px solid #bbb; }QSlider::sub-page:horizontal {background: rgb(235,97,0);border-radius: 0px;margin-top:8px;margin-bottom:8px;}QSlider::add-page:horizontal {background: rgb(255,255, 255);border: 0px solid #777;border-radius: 2px;margin-top:8px;margin-bottom:8px;}QSlider::handle:horizontal {background: rgb(255,153,102);border: 1px solid rgb(255,153,102);width: 14px;height:10px;border-radius: 7px;margin-top:2px;margin-bottom:2px;}QSlider::handle:horizontal:hover {background: rgb(255,128,6); border: 1px solid rgba(102,102,102,102); border-radius: 7px; }QSlider::sub-page:horizontal:disabled {background: #bbb;border-color: #999;}QSlider::add-page:horizontal:disabled {background: #eee;border-color: #999;}QSlider::handle:horizontal:disabled {background: #eee;border: 1px solid #aaa;border-radius: 4px;}");
    //播放键
    playBtn=new QPushButton(QString(""),this);
    playBtn->setFixedSize(50,50);
    playBtn->setFlat(true);

    playBtn->setStyleSheet("border-image:url(://pic/播放.png)");
    //关机按钮
    closeBtn=new QPushButton(QString(""),this);
    closeBtn->setFixedSize(45,45);
    closeBtn->setFlat(true);

    closeBtn->setStyleSheet("border-image:url(://pic/关闭.png)");
    //查找文件
    addmusicBtn=new QPushButton(QString(""),this);
    addmusicBtn->setFixedSize(45,45);
    addmusicBtn->setFlat(true);

    addmusicBtn->setStyleSheet("border-image:url(://pic/导入.png)");
    //停止播放
    stopBtn=new QPushButton(QString(""),this);
    stopBtn->setFixedSize(50,50);
    stopBtn->setFlat(true);

    stopBtn->setStyleSheet("border-image:url(://pic/暂停 (1).png)");
    //下一首
    nextBtn=new QPushButton(QString(""),this);
    nextBtn->setFixedSize(45,45);
    nextBtn->setFlat(true);

    nextBtn->setStyleSheet("border-image:url(://pic/下一首.png)");
    //上一首
    lastBtn=new QPushButton(QString(""),this);
    lastBtn->setFixedSize(45,45);
    lastBtn->setFlat(true);

    lastBtn->setStyleSheet("border-image:url(://pic/上一首.png)");
    //查找背景图片
    imageBtn=new QPushButton(QString(""),this);
    imageBtn->setFixedSize(45,45);
    imageBtn->setFlat(true);

    imageBtn->setStyleSheet("border-image:url(://pic/图片.png)");
    //最小化到托盘
    windowminBtn=new QPushButton(QString(""),this);
    windowminBtn->setFixedSize(40,40);
    windowminBtn->setFlat(true);

    windowminBtn->setStyleSheet("border-image:url(://pic/2-最小化.png)");

    //歌曲列表
    tablewidget=new QTableWidget(this);
    tablewidget->setColumnCount(2);             //设置为2列
    tablewidget->setFrameShape(QFrame::NoFrame );
    tablewidget->setSelectionMode(QAbstractItemView::SingleSelection); //  设置选择的模式为单选择
    tablewidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置每次选一行
    tablewidget->horizontalHeader()->setStretchLastSection(true);//自动延长
    QStringList stringlist;
    stringlist<<"歌名"<<"歌手";


    tablewidget->setHorizontalHeaderLabels(stringlist);
    tablewidget->verticalHeader()->setVisible(false);
    tablewidget->resize(900,400);
    tablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablewidget->setColumnWidth(0,450);
    tablewidget->setColumnWidth(1,450);
    tablewidget->setRowHeight(3,60);
    tablewidget->setStyleSheet("QHeaderView::section { background-color: darkorange;}");
    //tablewidget->setStyleSheet("background-color:rgba(0,0,0,0)");
    QPalette pll = tablewidget->palette();
    pll.setBrush(QPalette::Base,QBrush(QColor(255,255,255,0)));
    tablewidget->setPalette(pll);

    //播放模式
    playstylecombox=new QComboBox(this);
    playstylecombox->addItem(QString("列表播放"));
    playstylecombox->addItem(QString("随机播放"));
    playstylecombox->addItem(QString("单曲循环"));
    playstylecombox->setMaximumSize(100,30);
    playstylecombox->setStyleSheet("QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position: top right;width: 20px;border-left-width: 1px;border-left-color: darkgray;border-left-style: solid; /* just a single line */border-top-right-radius: 3px; /* same radius as the QComboBox */border-bottom-right-radius: 3px;}QComboBox::down-arrow {image: url(:/misc/down_arrow_2);}");

    //trayicon=new QSystemTrayIcon(QIcon(":images/icon.png"));

    timelabel=new QLabel(this);

namelabel=new QLabel(this);
    //布局
    QHBoxLayout* layout1=new QHBoxLayout;
    layout1->addWidget(lastBtn);
    layout1->addWidget(playBtn);
    layout1->addWidget(stopBtn);
    layout1->addWidget(nextBtn);
    layout1->addWidget(addmusicBtn);
    layout1->addWidget(imageBtn);
    layout1->addWidget(windowminBtn);
    layout1->addWidget(closeBtn);
    layout1->addWidget(playstylecombox);

    QHBoxLayout* layout2=new QHBoxLayout;
    layout2->addWidget(slider);
    layout2->addWidget(timelabel);

    QVBoxLayout* v=new QVBoxLayout(this);
    v->addWidget(tablewidget);
    v->addWidget(namelabel);
    v->addLayout(layout2);
    v->addLayout(layout1);


    playlist=new QMediaPlaylist;
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(70);

    timer=new QTimer;
    timer->setSingleShot(false);
    timer->setInterval(500);


    connect(lastBtn,&QPushButton::clicked,
            [=]()
    {
        tablewidget->clearSelection();
        for(int i=0;i<tablewidget->rowCount();i++)
        {
            for(int j=0;j<tablewidget->columnCount();j++)
            {
                tablewidget->item(i,j)->setBackgroundColor(QColor(Qt::white));
            }
        }

        int index=playlist->previousIndex();
        playlist->setCurrentIndex(index);
        player->play();
        timer->start();
        for(int i=0;i<tablewidget->columnCount();i++)
        {
            tablewidget->item(index,i)->setBackgroundColor(QColor(0,0,255));
        }
    }
    );

    connect(playBtn,&QPushButton::clicked,
            [=]()
    {
        tablewidget->clearSelection();
        for(int i=0;i<tablewidget->rowCount();i++)
        {
            for(int j=0;j<tablewidget->columnCount();j++)
            {
                tablewidget->item(i,j)->setBackgroundColor(QColor(Qt::white));
            }
        }

        player->play();
        timer->start();
        int index=playlist->currentIndex();
        for(int i=0;i<tablewidget->columnCount();i++)
        {
            tablewidget->item(index,i)->setBackgroundColor(QColor(0,0,255));
        }
    }
    );

    connect(stopBtn,&QPushButton::clicked,
            [=]()
    {
        player->pause();
        timer->stop();
    }
    );

    connect(nextBtn,&QPushButton::clicked,
            [=]()
    {
        tablewidget->clearSelection();
        for(int i=0;i<tablewidget->rowCount();i++)
        {
            for(int j=0;j<tablewidget->columnCount();j++)
            {
                tablewidget->item(i,j)->setBackgroundColor(QColor(Qt::white));
            }
        }

        int index=playlist->nextIndex();
        playlist->setCurrentIndex(index);
        player->play();
        timer->start();
        for(int i=0;i<tablewidget->columnCount();i++)
        {
            tablewidget->item(index,i)->setBackgroundColor(QColor(0,0,255));
        }
    }
    );

    connect(addmusicBtn,&QPushButton::clicked,
            [=]()
    {
        QStringList musiclist=QFileDialog::getOpenFileNames(this,tr("选择文件"),tr("/"),tr("music file(*.mp3)"));
        for(int i=0;i<musiclist.count();i++)
        {
           QString path=musiclist.at(i);
            if(path.isEmpty()==false)
            {
                playlist->addMedia(QUrl::fromLocalFile(path));

                QString filename=changfilename(path);
                QString singer_str;
                QString song_str;
                QString form_str;
                if(filename.contains("-",Qt::CaseSensitive)==false)
                {
                    singer_str="Unknow";
                    song_str=filename.split(".").front();
                    form_str=filename.split(".").last();
                }
                else
                {
                    singer_str=filename.split("-").front();
                    QString str=filename.split("-").last();
                    song_str=str.split(".").front();
                    form_str=str.split(".").last();
                }

                int rownum=tablewidget->rowCount();
                tablewidget->insertRow(rownum);
                tablewidget->setItem(rownum,0,new QTableWidgetItem(song_str));
                tablewidget->setItem(rownum,1,new QTableWidgetItem(singer_str));
            }
        }
    }
    );

    connect(imageBtn,&QPushButton::clicked,
            [=]()
    {
        QString imagepath=QFileDialog::getOpenFileName(this,QString("选择图片"),QString("/"),QString("image file(*.png)"));
        QPixmap pix2(imagepath);
        pix2=pix2.scaled(this->width(),this->height());
        this->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(pix2)));
        this->setPalette(palette);
    }
    );

    connect(windowminBtn,&QPushButton::clicked,
            [=]()
    {
        this->showMinimized();
    }
    );

    connect(closeBtn,&QPushButton::clicked,
            [=]()
    {
      this->close();
    }
    );

    connect(player,&QMediaPlayer::positionChanged,
            [=](qint64 position)
    {
            slider->setValue(position);
            timelabel->setText(Time(position)+"/"+Time(player->duration()));
    }
    );

    connect(slider,&QSlider::sliderMoved,
            [=](int value)
    {
      player->setPosition(value);
    }
    );

    connect(player,&QMediaPlayer::durationChanged,
            [=](qint64 duration)
    {
        slider->setRange(0,duration);
        slider->setEnabled(duration>0);
        slider->setPageStep(duration/10);
    }
    );

    connect(tablewidget,&QTableWidget::cellDoubleClicked,
            [=](int index,int)
    {
        tablewidget->clearSelection();
        for(int i=0;i<tablewidget->rowCount();i++)
        {
            for(int j=0;j<tablewidget->columnCount();j++)
            {
                tablewidget->item(i,j)->setBackgroundColor(QColor(Qt::white));
            }
        }

        playlist->setCurrentIndex(index);
        for(int i=0;i<tablewidget->columnCount();i++)
        {
            tablewidget->item(index,i)->setBackgroundColor(QColor(0,0,255));
        }
        player->play();
        timer ->start();
    }
    );

    connect(playlist,&QMediaPlaylist::currentIndexChanged,
            [=]()
    {
            slider->setValue(0);
    }
    );

    connect(playlist,&QMediaPlaylist::currentIndexChanged,
            [=](int index)
    {
            namelabel->setText(tablewidget->item(index,0)->text());
    }
    );

    connect(playstylecombox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged) ,
            [=](int index)
       {
           //qDebug()<<index;
           //0  "列表播放"
           //1  "随机播放"
           //2  "单曲循环"
           switch (index)
           {
               case 0:
                   playlist->setPlaybackMode(QMediaPlaylist::Loop);
                   break;
               case 1:
                   playlist->setPlaybackMode(QMediaPlaylist::Random);
                   break;
               case 2:
                   playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
                   break;
               default:
                   break;
          }
       }
    );

}

Widget::~Widget()
{

}

QString Widget::changfilename(QString filepath)
{
    QString tmp;
    tmp.clear();
    if(!filepath.isEmpty())
    {
       for(int i=0;i<filepath.count();i++)
       {
           if(filepath[i]=='/')
           {
               for(int j=0;j<=i;j++)
               {
                   filepath[j]=' ';
               }
           }
           tmp=filepath;
       }
      return tmp;
    }
}

QString Widget::Time(qint64 time)
{
    int sec=time/1000;
    int min=sec/60;
    sec-=min*60;
    return QStringLiteral("%1:%2")
            .arg(min, 2, 10, QLatin1Char('0'))
            .arg(sec, 2, 10, QLatin1Char('0'));
}
