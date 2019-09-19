#include "widget.h"
#include "ui_widget.h"
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include<QPushButton>
#include <QString>
#include <vector>
extern struct MyType
{
    int fd[2];
    int fifo_fd;
}Mytype;
typedef struct lrc
{
    int time;
    char song_lrc_row[128];
    //int num;
    struct lrc *next;
}LRC;
bool Widget::state = true;
int Widget::speed = 0;
int Widget::now_time = 0;
int Widget::total_time = 0;
int Widget::voice = 50;
bool Widget::bool_voice =true;
char* Widget::song_name[64]={NULL};
int Widget::song_num=1;
char Widget::now_song_name[128]="";
int Widget::circulation_mode = 0;
QPoint Widget::dPos;
int Widget::back_picture_num = 0;

void *deal_fun2(void *);
void *deal_fun1(void *arg);
void *deal_fun3(void *arg);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏状态栏

    pthread_t tid1;
    pthread_create(&tid1,NULL,deal_fun1,(void *)ui);
    pthread_detach(tid1);
    pthread_t tid2;
    pthread_create(&tid2,NULL,deal_fun2,NULL);
    pthread_detach(tid2);
    pthread_t tid3;
    pthread_create(&tid3,NULL,deal_fun3,(void *)ui);
    pthread_detach(tid3);

    myList();
    usleep(50*1000);
    ui->verticalSlider->setValue(Widget::voice);


}

Widget::~Widget()
{
    delete ui;
}

LRC *insert(LRC *head,LRC tmp)
{
    LRC *pi = (LRC *)calloc(1,sizeof(LRC));//1.为插入的节点申请堆区空间
    *pi =tmp;//2.将tmp的数据 赋值到 *pi 中
    pi->next = NULL;//将pi->next 赋值为 NULL
    if (head == NULL)//为空
    {
        head = pi;
        return head;
    }
    else// 不为空
    {
        LRC *pf = head,*pb = head;//寻找插入点的位置
        while ((pb->time < pi->time) && (pb->next != NULL))
        {
            pf = pb;//pf记录pb移动之前的位置
            pb = pb->next ;//pb往下一个节点移动
        }
        if (pb->time >= pi->time)//前中     //判断插入点的位置（前 中 尾）
        {
            if (pb == head)
            {
                pi->next = head;//保存旧链表的的头地址
                head = pi;
            }
            else
            {
                pf->next = pi;
                pi->next = pb;
            }
        }
        else if (pb->next == NULL)//尾部
        {
            pb->next = pi;
        }
    }
    return head;
}

void *deal_fun2(void *)
{
    while (1)
    {
        while(Widget::state)
        {
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_percent_pos\n",strlen("get_percent_pos\n"));//speed
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_time_pos\n",strlen("get_time_pos\n"));//now_time
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_time_length\n",strlen("get_time_length\n"));//total_time
            usleep(10*1000);
            write(Mytype.fifo_fd,"get_file_name\n",strlen("get_file_name\n"));//file_name

        }
        usleep(10);
    }
}

void *deal_fun1(void *arg)
{
    Ui::Widget *ui = (Ui::Widget *)arg;
    while(1)
    {
        char buf[128]="";
        read(Mytype.fd[0],buf,sizeof(buf));
        char cmd[128] = "";
        sscanf(buf,"%[^=]",cmd);
        if(strcmp(cmd,"ANS_PERCENT_POSITION") == 0)//进度条
        {
            float num = 0.0f;
            sscanf(buf,"%[^=]=%f",cmd,&num);
            Widget::speed = (int)(num+0.5);
            ui->horizontalSlider->setValue(Widget::speed);
        }
        else if(strcmp(cmd,"ANS_TIME_POSITION") == 0 )//当前时间
        {
            float num = 0.0f;
            sscanf(buf,"%[^=]=%f",cmd,&num);
            Widget::now_time = (int)(num*10);
            char buf[128] = "";
            sprintf(buf,"%02d:%02d.%d",Widget::now_time/10/60,Widget::now_time/10%60,Widget::now_time%10);
            ui->label->setText(QString(buf));

            if(Widget::now_time >= Widget::total_time*10-10 && Widget::now_time >10 )//循环方式
            {
                if(Widget::circulation_mode == 0)
                {
                    int n = 0;
                    while (Widget::song_name[n++] != NULL);
                    if(Widget::song_num == n-2)
                    {
                        Widget::song_num = 0;
                    }
                    else {

                        Widget::song_num++;
                    };
                    char buf[128]="";
                    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",Widget::song_name[Widget::song_num]);
                    write(Mytype.fifo_fd,buf,strlen(buf));
                    Widget::state = true;
                    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
                    ui->pushButton_3->setIconSize(QSize(50,50));
                }
                else if(Widget::circulation_mode == 1)
                {
                    int n = 0;
                    while (Widget::song_name[n++] != NULL);
                    srand(time(NULL));
                    Widget::song_num = rand()%(n-1);
                    char buf[128]="";
                    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",Widget::song_name[Widget::song_num]);
                    write(Mytype.fifo_fd,buf,strlen(buf));
                    Widget::state = true;
                    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
                    ui->pushButton_3->setIconSize(QSize(50,50));

                }
                else if(Widget::circulation_mode == 2)
                {
                    char buf[128]="";
                    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",Widget::song_name[Widget::song_num]);
                    write(Mytype.fifo_fd,buf,strlen(buf));
                    Widget::state = true;
                    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
                    ui->pushButton_3->setIconSize(QSize(50,50));
                }
            }
        }
        else if(strcmp(cmd,"ANS_LENGTH") == 0)//总时间
        {
            float num = 0.0f;
            sscanf(buf,"%[^=]=%f",cmd,&num);
            Widget::total_time = (int)(num+0.5);
            char buf[128]="";
            sprintf(buf,"%02d:%02d",Widget::total_time/60,Widget::total_time%60);
            ui->label_2->setText(QString(buf));
        }
        else if(strcmp(cmd,"ANS_FILENAME") == 0 )//歌名
        {
            char buf1[128]="";
            sscanf(buf,"%[^=]='%[^.].mp3",cmd,buf1);
            ui->label_3->setText(QString(buf1));
            strcpy(Widget::now_song_name,buf1);
            //printf("%s\n",Widget::now_song_name);
        }

    }
}

void *deal_fun3(void *arg)//歌词读取与显示
{
    Ui::Widget *ui = (Ui::Widget *)arg;
    while (1)
    {
        usleep(500*1000);
        //  1、歌词读取
        FILE *fp = NULL;
        char buf[128]="";
        sprintf(buf,"%s%s%s","../myplayer/lyric/",Widget::now_song_name,".lrc");
        char now_song_name2[128]="";
        strcpy(now_song_name2,Widget::now_song_name);
        printf("%s  %s\n",now_song_name2,Widget::now_song_name);
        fp = fopen(buf,"r");
        if (fp == NULL )
        {
            usleep(100*1000);
            ui->label_4->setText(QString("  "));
            ui->label_5->setText(QString("  "));
            ui->label_6->setText(QString("此歌曲暂无歌词"));
            ui->label_7->setText(QString("  "));
            ui->label_8->setText(QString("  "));
            continue;
        }
        fseek(fp,0,2);//将流指针定位至文件尾部
        long len = ftell(fp);//获取文件总大小
        rewind(fp);//复位流指针
        char *song_lrc = (char *)calloc(1,len+1);//申请空间
        fread(song_lrc,len,1,fp);//读取文件数据
        fclose(fp);

        //printf("%s\n",song_lrc);
        //fflush(stdout);


        //  2、将歌词song_lrc按行切割，放入指针中
        char *lrc_row[128] = {0};
        int row = 0;
        lrc_row[row] = strtok(song_lrc,"\n");
        while ( lrc_row[row] != NULL )
        {
            row++;
            lrc_row[row] = strtok(NULL,"\n");
        }
        row--;

        //   3、逐行分析歌词:时间、歌词拆分放入链表
        LRC *head = NULL;
        int i = 0;
        for(i=4;i<row;i++)
        {
            char *p_i = lrc_row[i];
            char *p_lrc = lrc_row[i];
            while (*p_lrc == '[')
            {
                p_lrc += 10;
            }
            while (*p_i == '[')
            {
                int m=0,s=0;
                sscanf(p_i,"[%d:%d",&m,&s);
                LRC tmp;
                tmp.time = m*60+s;
                strcpy(tmp.song_lrc_row,p_lrc);
                head = insert(head,tmp);
                p_i += 10;
            }
        }
#if 1
        if (head == NULL)//不存在
        {
            ui->label_6->setText(QString("此歌曲暂无歌词"));
        }
        else//存在
        {
            const LRC *pa = head;//定义
            while (pa != NULL)
            {
                printf("%d  %s \n",pa->time,pa->song_lrc_row);
                fflush(stdout);
                pa = pa->next;
            }
        }
#endif

        //     4.显示歌词
        for (int  i = 0; i < 2; i++)//在链表头部插入2个空节点
        {
            LRC tmp;
            tmp.time = 0;
            strcpy(tmp.song_lrc_row,"  ");
            head = insert(head,tmp);
        }

        for (int  i = 999; i < 1001; i++)//在链表尾部插入两个空节点
        {
            LRC tmp;
            tmp.time = i;
            strcpy(tmp.song_lrc_row,"  ");
            head = insert(head,tmp);
        }

        while (1)
        {
            LRC *pb = head;
            LRC *pc = head;
            LRC *pd = head;
            pc = pb->next;
            pd = pc->next;
            while((pd->next->time < Widget::now_time/10)  &&(pd->next != NULL) )
            {
                pb = pc;
                pc = pd;
                pd = pd->next;
            }
            if((pd->time < Widget::now_time/10) && (pd->next->time >= Widget::now_time/10))
            {
                usleep(50*1000);
                ui->label_4->setText(QString(pb->song_lrc_row).toUtf8().data());
                ui->label_5->setText(QString(pc->song_lrc_row).toUtf8().data());
                ui->label_6->setText(QString(pd->song_lrc_row).toUtf8().data());
                ui->label_7->setText(QString(pd->next->song_lrc_row).toUtf8().data());
                ui->label_8->setText(QString(pd->next->next->song_lrc_row).toUtf8().data());
            }
            if(strcmp(now_song_name2,Widget::now_song_name) != 0 )
            {
                ui->label_4->setText(QString("  "));
                ui->label_5->setText(QString("  "));
                ui->label_6->setText(QString("  "));
                ui->label_7->setText(QString("  "));
                ui->label_8->setText(QString("  "));
                break;
            }
        }
    }
}

void Widget::paintEvent(QPaintEvent *event)//绘画
{
    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/picture/108.jpg");//添加界面背景图片
    painter->drawPixmap(0,0,1024,600,pix);
}

void Widget::myList()//添加歌曲列表
{
    DIR *dir = opendir("../myplayer/songs");
    int j = 0;
    while (1)
    {
        struct dirent *ent = readdir(dir);
        if(ent == NULL)
        {
            break;
        }
        else if(ent->d_type == DT_REG)
        {
            char buf[128]="";
            sscanf(ent->d_name,"%*[^.].%s",buf);
            if(strcmp(buf,"mp3") == 0)
            {
                ui->listWidget->addItem(QString(ent->d_name));
                Widget::song_name[j] = new char[strlen(ent->d_name)+1];
                strcpy(Widget::song_name[j++],ent->d_name);
            }
        }
    }
}

void Widget::on_pushButton_4_clicked()//快进
{
    if(Widget::now_time/10 > Widget::total_time-7)
    {
        Widget::state = true;
        ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
        ui->pushButton_3->setIconSize(QSize(50,50));
    }
    else
    {
        write(Mytype.fifo_fd,"seek 5\n", strlen("seek 5\n"));
        Widget::state = true;
        ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
        ui->pushButton_3->setIconSize(QSize(50,50));
    }
}

void Widget::on_pushButton_2_clicked()//快退
{
    write(Mytype.fifo_fd,"seek -5\n", strlen("seek -5\n"));
    Widget::state = true;
    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
    ui->pushButton_3->setIconSize(QSize(50,50));
}

void Widget::on_horizontalSlider_sliderPressed()//进度条 滑块按下
{
    usleep(50*1000);
    write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    Widget::state = false;
}

void Widget::on_horizontalSlider_sliderReleased()//进度条 滑块释放
{
    usleep(50*1000);
    write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    Widget::state = true;
    if(ui->horizontalSlider->value() != Widget::speed)
    {
        usleep(1000);
        int i = ((ui->horizontalSlider->value()-Widget::speed)*(Widget::total_time)/100);
        char buf[128]="";
        sprintf(buf,"%s %d","seek",i);
        write(Mytype.fifo_fd,buf,strlen(buf));
        if(!Widget::state )
        {
            Widget::state = true;
            usleep(1000*50);
            ui->pushButton_3->setIcon(QIcon(":/picture/1.png"));
            ui->pushButton_3->setIconSize(QSize(60,60));
            write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
        }
    }
}

void Widget::on_pushButton_3_clicked()//暂停 播放
{
    if(Widget::state)
    {
        Widget::state = false;
        usleep(1000*50);
        ui->pushButton_3->setIcon(QIcon(":/picture/1.png"));
        ui->pushButton_3->setIconSize(QSize(50,50));
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    }
    else if(!Widget::state )
    {
        Widget::state = true;
        usleep(1000*10);
        ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
        ui->pushButton_3->setIconSize(QSize(50,50));
        write(Mytype.fifo_fd,"pause\n",strlen("pause\n"));
    }
}

void Widget::on_pushButton_5_clicked()//下一曲
{
    int n = 0;
    while (song_name[n++] != NULL);
    if(song_num == n-2)
    {
        song_num = 0;
    }
    else {

        song_num++;
    };
    char buf[128]="";
    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",Widget::song_name[song_num]);
    write(Mytype.fifo_fd,buf,strlen(buf));
    Widget::state = true;
    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
    ui->pushButton_3->setIconSize(QSize(50,50));
}

void Widget::on_pushButton_clicked()//上一曲
{
    int n = 0;
    while (song_name[n++] != NULL);
    if(song_num == 0)
    {
        song_num = n-2;
    }
    else {

        song_num--;
    }
    char buf[128]="";
    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",Widget::song_name[song_num]);
    write(Mytype.fifo_fd,buf,strlen(buf));
    Widget::state = true;
    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
    ui->pushButton_3->setIconSize(QSize(50,50));
}

void Widget::on_listWidget_itemClicked(QListWidgetItem *item)//单击歌曲列表切歌
{
    char buf[128]="";
    sprintf(buf,"%s%s\n","loadfile ../myplayer/songs/",item->text().toUtf8().data());
    write(Mytype.fifo_fd,buf,strlen(buf));
    Widget::state = true;
    ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
    ui->pushButton_3->setIconSize(QSize(50,50));
    int i=0;
    for(i=0;i<65;i++)
    {
        if(strcmp(Widget::song_name[i],item->text().toUtf8().data()) == 0 )
        {
            break;
        }
    }
    Widget::song_num = i;
    ui->listWidget->clear();
    myList();
}

void Widget::on_pushButton_6_clicked()//音量增大
{
#if 1
    if(Widget::voice > 90)
    {
        Widget::voice = 100;
    }
    else
    {
        Widget::voice += 10;
    }
#endif
    char buf[64] = "";
    sprintf(buf,"%s %d 1","volume",Widget::voice);
    usleep(50*1000);
    write(Mytype.fifo_fd,buf,strlen(buf));
    ui->verticalSlider->setValue(Widget::voice);
    Widget::bool_voice = true;
}

void Widget::on_pushButton_8_clicked()//音量减小
{
    #if 1
    if(Widget::voice < 10)
    {
        Widget::voice = 0;
    }
    else
    {
        Widget::voice -= 10;
    }
    #endif

    char buf[64] = "";
    sprintf(buf,"%s %d 1","volume",Widget::voice);
    usleep(50*1000);
    write(Mytype.fifo_fd,buf,strlen(buf));
    ui->verticalSlider->setValue(Widget::voice);
    Widget::bool_voice = true;
}

void Widget::on_verticalSlider_valueChanged(int value)//音量条滑动
{
    if(value != Widget::voice)
    {
        usleep(50*1000);
        Widget::voice = value;
        char buf[128]="";
        sprintf(buf,"%s %d 1","volume",Widget::voice);
        write(Mytype.fifo_fd,buf,strlen(buf));
    }
}

void Widget::on_pushButton_9_clicked()//静音
{
    if( Widget::bool_voice)
    {
        Widget::bool_voice = false;
        usleep(1000*50);
        ui->pushButton_9->setIcon(QIcon(":/picture/9.png"));
        ui->pushButton_9->setIconSize(QSize(50,50));
        write(Mytype.fifo_fd,"mute 1\n",strlen("mute 1\n"));
    }
    else if( !Widget::bool_voice)
    {
        Widget::bool_voice = true;
        usleep(1000*50);
        ui->pushButton_9->setIcon(QIcon(":/picture/6.png"));
        ui->pushButton_9->setIconSize(QSize(50,50));
        write(Mytype.fifo_fd,"mute 0\n",strlen("mute 0\n"));
        Widget::state = true;
        ui->pushButton_3->setIcon(QIcon(":/picture/4.png"));
        ui->pushButton_3->setIconSize(QSize(50,50));
    }
}

void Widget::on_pushButton_10_clicked()//退出
{
    write(Mytype.fifo_fd,"quit\n",strlen("quit\n"));
    this->close();
}

void Widget::on_pushButton_11_clicked()//循环方式
{
    if(Widget::circulation_mode == 0)
    {
        Widget::circulation_mode = 1;
        ui->pushButton_11->setIcon(QIcon(":/picture/17.png"));//  随机播放
        ui->pushButton_11->setIconSize(QSize(50,50));
    }
    else if(Widget::circulation_mode == 1)
    {
        Widget::circulation_mode =2;
        ui->pushButton_11->setIcon(QIcon(":/picture/12.png"));// 单曲循环
        ui->pushButton_11->setIconSize(QSize(50,50));
    }
    else if(Widget::circulation_mode == 2)
    {
        Widget::circulation_mode = 0;
        ui->pushButton_11->setIcon(QIcon(":/picture/16.png"));// 循环播放
        ui->pushButton_11->setIconSize(QSize(50,50));
    }
}

void Widget::mouseMoveEvent(QMouseEvent *ev)//界面拖动
{
    if( ev->buttons() & Qt::LeftButton){
        move(ev->globalPos() - this->dPos);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)// 移动后部件所在的位置
{

    this->dPos = event->globalPos() - this->pos();
}

void Widget::on_pushButton_7_clicked()//窗口最小化
{
    this->showMinimized();
}

void Widget::on_pushButton_13_clicked()//刷新歌曲列表
{
    ui->listWidget->clear();
    myList();
}

void Widget::on_pushButton_14_clicked()//更换背景
{
    if(Widget::back_picture_num == 14)
    {
        Widget::back_picture_num = 0;
    }
    else
    {
        Widget::back_picture_num++;
    }
    char buf[128] = "";
    int num = Widget::back_picture_num +108;
    sprintf(buf,":/picture/%d.jpg",num);
    printf("%d  %s\n",num,buf);
    ui->label_9->setPixmap(QPixmap(buf));
    ui->label_9->setGeometry(0,0,1024,600);
}








