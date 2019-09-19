/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSlider *horizontalSlider;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QSlider *verticalSlider;
    QListWidget *listWidget;
    QPushButton *pushButton_11;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_9;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        QFont font;
        font.setPointSize(14);
        Widget->setFont(font);
        Widget->setMouseTracking(false);
        Widget->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 460, 51, 51));
        pushButton->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/picture/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 460, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/picture/13.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 460, 51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/picture/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(50, 50));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 460, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/picture/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(50, 50));
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 460, 51, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/picture/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(50, 50));
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(450, 460, 51, 51));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/picture/7.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(50, 50));
        pushButton_6->setFlat(true);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 400, 401, 41));
        horizontalSlider->setMaximum(99);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 390, 71, 31));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(520, 390, 61, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(16);
        label_2->setFont(font2);
        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(520, 460, 51, 51));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/picture/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(50, 50));
        pushButton_8->setFlat(true);
        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(590, 460, 51, 51));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/picture/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon7);
        pushButton_9->setIconSize(QSize(50, 50));
        pushButton_9->setFlat(true);
        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 10, 31, 31));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/picture/11.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon8);
        pushButton_10->setIconSize(QSize(30, 30));
        pushButton_10->setFlat(true);
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(590, 270, 20, 111));
        verticalSlider->setOrientation(Qt::Vertical);
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(770, 60, 256, 311));
        listWidget->setAutoFillBackground(false);
        listWidget->setStyleSheet(QStringLiteral("background-color: rgba(191, 64, 64, 0);"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(0);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setIconSize(QSize(90, 90));
        listWidget->setMovement(QListView::Free);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setProperty("isWrapping", QVariant(false));
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setWordWrap(false);
        listWidget->setSortingEnabled(false);
        pushButton_11 = new QPushButton(Widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(380, 460, 51, 51));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/picture/16.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon9);
        pushButton_11->setIconSize(QSize(50, 50));
        pushButton_11->setFlat(true);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 160, 541, 20));
        QPalette palette;
        QBrush brush(QColor(136, 138, 133, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette);
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 230, 541, 41));
        QPalette palette1;
        QBrush brush2(QColor(164, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_6->setPalette(palette1);
        QFont font3;
        font3.setPointSize(20);
        label_6->setFont(font3);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAutoFillBackground(false);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 280, 541, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_7->setPalette(palette2);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 320, 541, 20));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_8->setPalette(palette3);
        label_8->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 190, 541, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette4);
        label_5->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 60, 421, 41));
        QPalette palette5;
        QBrush brush3(QColor(191, 64, 64, 0));
        brush3.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        label_3->setPalette(palette5);
        QFont font4;
        font4.setPointSize(30);
        font4.setKerning(true);
        label_3->setFont(font4);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QLatin1String("\n"
"background-color: rgba(191, 64, 64, 0);"));
        label_3->setLineWidth(0);
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(50, 10, 31, 31));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/picture/23.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon10);
        pushButton_7->setIconSize(QSize(30, 30));
        pushButton_7->setFlat(true);
        pushButton_12 = new QPushButton(Widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(450, 520, 51, 51));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/picture/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon11);
        pushButton_12->setIconSize(QSize(50, 50));
        pushButton_12->setFlat(true);
        pushButton_13 = new QPushButton(Widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(170, 520, 51, 51));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/picture/19.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon12);
        pushButton_13->setIconSize(QSize(50, 50));
        pushButton_13->setFlat(true);
        pushButton_14 = new QPushButton(Widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(310, 520, 51, 51));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/picture/20.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon13);
        pushButton_14->setIconSize(QSize(50, 50));
        pushButton_14->setFlat(true);
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 0, 1024, 600));
        label_9->setScaledContents(true);
        label_9->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_11->raise();
        pushButton_6->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_12->raise();
        horizontalSlider->raise();
        label_8->raise();
        label_7->raise();
        label_6->raise();
        verticalSlider->raise();
        label_5->raise();
        label_4->raise();
        label_3->raise();
        pushButton_10->raise();
        pushButton_7->raise();
        listWidget->raise();

        retranslateUi(Widget);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
        label_4->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_5->setText(QString());
        label_3->setText(QString());
        pushButton_7->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
