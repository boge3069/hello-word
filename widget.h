#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QListWidget>
#include <QPoint>

using namespace std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    static bool state;
    static int speed;
    static int now_time;
    static int total_time;
    static int voice;
    static bool bool_voice;
    static int song_num;
    static char now_song_name[128];
    static char* song_name[64];
    static int circulation_mode;
    static QPoint dPos;
    static int back_picture_num;

    void paintEvent(QPaintEvent *event);//绘画
    void myList();
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *event);


public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_verticalSlider_valueChanged(int value);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
