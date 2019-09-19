/********************************************************************************
** Form generated from reading UI file 'mini_lyric.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINI_LYRIC_H
#define UI_MINI_LYRIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mini_lyric
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Mini_lyric)
    {
        if (Mini_lyric->objectName().isEmpty())
            Mini_lyric->setObjectName(QStringLiteral("Mini_lyric"));
        Mini_lyric->resize(800, 100);
        label = new QLabel(Mini_lyric);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 5, 600, 40));
        label_2 = new QLabel(Mini_lyric);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 55, 600, 40));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(Mini_lyric);

        QMetaObject::connectSlotsByName(Mini_lyric);
    } // setupUi

    void retranslateUi(QWidget *Mini_lyric)
    {
        Mini_lyric->setWindowTitle(QApplication::translate("Mini_lyric", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mini_lyric: public Ui_Mini_lyric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINI_LYRIC_H
