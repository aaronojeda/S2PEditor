/********************************************************************************
** Form generated from reading UI file 'QObjectsDock.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QOBJECTSDOCK_H
#define UI_QOBJECTSDOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QObjectsDock
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nameLabel;
    QComboBox *nameCombo;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QLabel *prevLabel;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *typeBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *enemiesBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *leftRightButton;
    QPushButton *flyingButton;
    QPushButton *chaserButton;
    QPushButton *flyingChaserButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *itemsBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *healthItemButton;
    QPushButton *livesItemButton;
    QPushButton *scoreItemButton;
    QPushButton *keyItemButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *othersBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playerButton;
    QPushButton *lockedDoorButton;
    QPushButton *checkPointButton;
    QPushButton *levelFinishButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDockWidget *QObjectsDock)
    {
        if (QObjectsDock->objectName().isEmpty())
            QObjectsDock->setObjectName(QStringLiteral("QObjectsDock"));
        QObjectsDock->resize(292, 350);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QObjectsDock->sizePolicy().hasHeightForWidth());
        QObjectsDock->setSizePolicy(sizePolicy);
        QObjectsDock->setMinimumSize(QSize(292, 350));
        QObjectsDock->setMaximumSize(QSize(10000, 10000));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        nameLabel = new QLabel(widget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout_5->addWidget(nameLabel);

        nameCombo = new QComboBox(widget);
        nameCombo->setObjectName(QStringLiteral("nameCombo"));
        nameCombo->setMinimumSize(QSize(120, 0));
        nameCombo->setEditable(false);

        horizontalLayout_5->addWidget(nameCombo);

        editButton = new QPushButton(widget);
        editButton->setObjectName(QStringLiteral("editButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon);
        editButton->setIconSize(QSize(16, 16));

        horizontalLayout_5->addWidget(editButton);

        deleteButton = new QPushButton(widget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);

        horizontalLayout_5->addWidget(deleteButton);

        prevLabel = new QLabel(widget);
        prevLabel->setObjectName(QStringLiteral("prevLabel"));
        prevLabel->setMinimumSize(QSize(32, 32));
        prevLabel->setMaximumSize(QSize(32, 32));
        prevLabel->setScaledContents(true);

        horizontalLayout_5->addWidget(prevLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);

        typeBox = new QGroupBox(widget);
        typeBox->setObjectName(QStringLiteral("typeBox"));
        verticalLayout = new QVBoxLayout(typeBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        enemiesBox = new QGroupBox(typeBox);
        enemiesBox->setObjectName(QStringLiteral("enemiesBox"));
        horizontalLayout = new QHBoxLayout(enemiesBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftRightButton = new QPushButton(enemiesBox);
        leftRightButton->setObjectName(QStringLiteral("leftRightButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/leftRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftRightButton->setIcon(icon2);
        leftRightButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(leftRightButton);

        flyingButton = new QPushButton(enemiesBox);
        flyingButton->setObjectName(QStringLiteral("flyingButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/flying.png"), QSize(), QIcon::Normal, QIcon::Off);
        flyingButton->setIcon(icon3);
        flyingButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(flyingButton);

        chaserButton = new QPushButton(enemiesBox);
        chaserButton->setObjectName(QStringLiteral("chaserButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/chaser.png"), QSize(), QIcon::Normal, QIcon::Off);
        chaserButton->setIcon(icon4);
        chaserButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(chaserButton);

        flyingChaserButton = new QPushButton(enemiesBox);
        flyingChaserButton->setObjectName(QStringLiteral("flyingChaserButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/flyingChaser.png"), QSize(), QIcon::Normal, QIcon::Off);
        flyingChaserButton->setIcon(icon5);
        flyingChaserButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(flyingChaserButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(enemiesBox);

        itemsBox = new QGroupBox(typeBox);
        itemsBox->setObjectName(QStringLiteral("itemsBox"));
        horizontalLayout_3 = new QHBoxLayout(itemsBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        healthItemButton = new QPushButton(itemsBox);
        healthItemButton->setObjectName(QStringLiteral("healthItemButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/healthUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        healthItemButton->setIcon(icon6);
        healthItemButton->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(healthItemButton);

        livesItemButton = new QPushButton(itemsBox);
        livesItemButton->setObjectName(QStringLiteral("livesItemButton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/1up.png"), QSize(), QIcon::Normal, QIcon::Off);
        livesItemButton->setIcon(icon7);
        livesItemButton->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(livesItemButton);

        scoreItemButton = new QPushButton(itemsBox);
        scoreItemButton->setObjectName(QStringLiteral("scoreItemButton"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/scoreUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        scoreItemButton->setIcon(icon8);
        scoreItemButton->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(scoreItemButton);

        keyItemButton = new QPushButton(itemsBox);
        keyItemButton->setObjectName(QStringLiteral("keyItemButton"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/keysUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        keyItemButton->setIcon(icon9);
        keyItemButton->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(keyItemButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(itemsBox);

        othersBox = new QGroupBox(typeBox);
        othersBox->setObjectName(QStringLiteral("othersBox"));
        horizontalLayout_2 = new QHBoxLayout(othersBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        playerButton = new QPushButton(othersBox);
        playerButton->setObjectName(QStringLiteral("playerButton"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/player.png"), QSize(), QIcon::Normal, QIcon::Off);
        playerButton->setIcon(icon10);
        playerButton->setIconSize(QSize(32, 32));
        playerButton->setCheckable(true);

        horizontalLayout_2->addWidget(playerButton);

        lockedDoorButton = new QPushButton(othersBox);
        lockedDoorButton->setObjectName(QStringLiteral("lockedDoorButton"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/doorGUI.png"), QSize(), QIcon::Normal, QIcon::Off);
        lockedDoorButton->setIcon(icon11);
        lockedDoorButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(lockedDoorButton);

        checkPointButton = new QPushButton(othersBox);
        checkPointButton->setObjectName(QStringLiteral("checkPointButton"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/checkPoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkPointButton->setIcon(icon12);
        checkPointButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(checkPointButton);

        levelFinishButton = new QPushButton(othersBox);
        levelFinishButton->setObjectName(QStringLiteral("levelFinishButton"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/newObjs/endLevel.png"), QSize(), QIcon::Normal, QIcon::Off);
        levelFinishButton->setIcon(icon13);
        levelFinishButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(levelFinishButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(othersBox);


        verticalLayout_3->addWidget(typeBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        QObjectsDock->setWidget(widget);

        retranslateUi(QObjectsDock);

        QMetaObject::connectSlotsByName(QObjectsDock);
    } // setupUi

    void retranslateUi(QDockWidget *QObjectsDock)
    {
        QObjectsDock->setWindowTitle(QApplication::translate("QObjectsDock", "Objects", 0));
        nameLabel->setText(QApplication::translate("QObjectsDock", "Name: ", 0));
        editButton->setText(QString());
        deleteButton->setText(QString());
        prevLabel->setText(QString());
        typeBox->setTitle(QApplication::translate("QObjectsDock", "New object", 0));
        enemiesBox->setTitle(QApplication::translate("QObjectsDock", "Enemies", 0));
        leftRightButton->setText(QString());
        flyingButton->setText(QString());
        chaserButton->setText(QString());
        flyingChaserButton->setText(QString());
        itemsBox->setTitle(QApplication::translate("QObjectsDock", "Items", 0));
        healthItemButton->setText(QString());
        livesItemButton->setText(QString());
        scoreItemButton->setText(QString());
        keyItemButton->setText(QString());
        othersBox->setTitle(QApplication::translate("QObjectsDock", "Others", 0));
        playerButton->setText(QString());
        lockedDoorButton->setText(QString());
        checkPointButton->setText(QString());
        levelFinishButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QObjectsDock: public Ui_QObjectsDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QOBJECTSDOCK_H
