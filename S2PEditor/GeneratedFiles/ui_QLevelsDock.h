/********************************************************************************
** Form generated from reading UI file 'QLevelsDock.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLEVELSDOCK_H
#define UI_QLEVELSDOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QLevelsDock
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QListWidget *levelList;
    QVBoxLayout *verticalLayout_5;
    QPushButton *levelUpButton;
    QPushButton *levelDownButton;
    QSpacerItem *verticalSpacer;
    QPushButton *loadButton;
    QPushButton *deleteLevelButton;
    QSpacerItem *horizontalSpacer;
    QLabel *idLabel;
    QLineEdit *sourceLine;

    void setupUi(QDockWidget *QLevelsDock)
    {
        if (QLevelsDock->objectName().isEmpty())
            QLevelsDock->setObjectName(QStringLiteral("QLevelsDock"));
        QLevelsDock->resize(186, 209);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        levelList = new QListWidget(widget);
        levelList->setObjectName(QStringLiteral("levelList"));

        horizontalLayout_9->addWidget(levelList);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        levelUpButton = new QPushButton(widget);
        levelUpButton->setObjectName(QStringLiteral("levelUpButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        levelUpButton->setIcon(icon);

        verticalLayout_5->addWidget(levelUpButton);

        levelDownButton = new QPushButton(widget);
        levelDownButton->setObjectName(QStringLiteral("levelDownButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowDown.png"), QSize(), QIcon::Normal, QIcon::Off);
        levelDownButton->setIcon(icon1);

        verticalLayout_5->addWidget(levelDownButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        loadButton = new QPushButton(widget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/saveLoad.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadButton->setIcon(icon2);

        verticalLayout_5->addWidget(loadButton);

        deleteLevelButton = new QPushButton(widget);
        deleteLevelButton->setObjectName(QStringLiteral("deleteLevelButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteLevelButton->setIcon(icon3);

        verticalLayout_5->addWidget(deleteLevelButton);


        horizontalLayout_9->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_9);

        idLabel = new QLabel(widget);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout->addWidget(idLabel);

        sourceLine = new QLineEdit(widget);
        sourceLine->setObjectName(QStringLiteral("sourceLine"));

        verticalLayout->addWidget(sourceLine);

        QLevelsDock->setWidget(widget);

        retranslateUi(QLevelsDock);

        QMetaObject::connectSlotsByName(QLevelsDock);
    } // setupUi

    void retranslateUi(QDockWidget *QLevelsDock)
    {
        QLevelsDock->setWindowTitle(QApplication::translate("QLevelsDock", "Levels", 0));
        levelUpButton->setText(QString());
        levelDownButton->setText(QString());
        loadButton->setText(QString());
        deleteLevelButton->setText(QString());
        idLabel->setText(QApplication::translate("QLevelsDock", "<No item selected>", 0));
    } // retranslateUi

};

namespace Ui {
    class QLevelsDock: public Ui_QLevelsDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLEVELSDOCK_H
