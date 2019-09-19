#include "widget.h"
#include <QApplication>

#include<stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

struct MyType
{
    int fd[2];
    int fifo_fd;
}Mytype;


int main(int argc, char *argv[])
{

    //创建一个无名管道 获取mplayer回应
    Mytype.fd[2];
    pipe(Mytype.fd);

    pid_t pid = fork();
    if(pid == 0)//子进程
    {
        //创建一个管道
        mkfifo("fifo_cmd",0666);
        //将1设备重定向到fd[1]
        dup2(Mytype.fd[1], 1);

        //使用execlp启动mplayer
        //char buf[128] ="";
        //sprintf(buf,"../myplayer/songs/%s.mp3",Widget::song_name[0]);
        execlp("mplayer","mplayer","-idle","-slave","-quiet",\
        "-input","file=./fifo_cmd", "../myplayer/songs/小相思.mp3",NULL);
    }
    else//父进程
    {
        //创建一个管道
        mkfifo("fifo_cmd",0666);
        Mytype.fifo_fd = open("fifo_cmd",O_WRONLY);

        //ui设计
        QApplication a(argc, argv);
        Widget w;
        w.show();

        system("rm fifo_cmd");
        return a.exec();

    }
    return 0;
}
