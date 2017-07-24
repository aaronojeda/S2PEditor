/********************************************************************************
** Form generated from reading UI file 'QTilesetsDock.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTILESETSDOCK_H
#define UI_QTILESETSDOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTilesetsDock
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tilePicker;
    QWidget *tab;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QSpinBox *zoomSpin;
    QCheckBox *collisionCheckBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDockWidget *QTilesetsDock)
    {
        if (QTilesetsDock->objectName().isEmpty())
            QTilesetsDock->setObjectName(QStringLiteral("QTilesetsDock"));
        QTilesetsDock->resize(249, 118);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QTilesetsDock->sizePolicy().hasHeightForWidth());
        QTilesetsDock->setSizePolicy(sizePolicy);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tilePicker = new QTabWidget(widget);
        tilePicker->setObjectName(QStringLiteral("tilePicker"));
        tilePicker->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tilePicker->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tilePicker->addTab(tab_2, QString());

        verticalLayout->addWidget(tilePicker);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        newButton = new QPushButton(widget);
        newButton->setObjectName(QStringLiteral("newButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/add-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);

        horizontalLayout_2->addWidget(newButton);

        zoomInButton = new QPushButton(widget);
        zoomInButton->setObjectName(QStringLiteral("zoomInButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInButton->setIcon(icon1);

        horizontalLayout_2->addWidget(zoomInButton);

        zoomOutButton = new QPushButton(widget);
        zoomOutButton->setObjectName(QStringLiteral("zoomOutButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutButton->setIcon(icon2);

        horizontalLayout_2->addWidget(zoomOutButton);

        zoomSpin = new QSpinBox(widget);
        zoomSpin->setObjectName(QStringLiteral("zoomSpin"));
        zoomSpin->setMinimum(1);
        zoomSpin->setMaximum(500);
        zoomSpin->setValue(100);

        horizontalLayout_2->addWidget(zoomSpin);

        collisionCheckBox = new QCheckBox(widget);
        collisionCheckBox->setObjectName(QStringLiteral("collisionCheckBox"));
        collisionCheckBox->setChecked(true);

        horizontalLayout_2->addWidget(collisionCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        QTilesetsDock->setWidget(widget);

        retranslateUi(QTilesetsDock);

        tilePicker->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QTilesetsDock);
    } // setupUi

    void retranslateUi(QDockWidget *QTilesetsDock)
    {
        QTilesetsDock->setWindowTitle(QApplication::translate("QTilesetsDock", "Tilesets", 0));
        tilePicker->setTabText(tilePicker->indexOf(tab), QApplication::translate("QTilesetsDock", "Tab 1", 0));
        tilePicker->setTabText(tilePicker->indexOf(tab_2), QApplication::translate("QTilesetsDock", "Tab 2", 0));
        newButton->setText(QString());
        zoomInButton->setText(QString());
        zoomOutButton->setText(QString());
        zoomSpin->setSuffix(QApplication::translate("QTilesetsDock", "%", 0));
        collisionCheckBox->setText(QApplication::translate("QTilesetsDock", "Collision", 0));
    } // retranslateUi

};

namespace Ui {
    class QTilesetsDock: public Ui_QTilesetsDock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTILESETSDOCK_H
