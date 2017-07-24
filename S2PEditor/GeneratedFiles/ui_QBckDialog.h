/********************************************************************************
** Form generated from reading UI file 'QBckDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBCKDIALOG_H
#define UI_QBCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QBckDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QPushButton *upButton;
    QPushButton *downButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *speedYEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *nameLabel;
    QListWidget *bckList;
    QLineEdit *speedXEdit;
    QLineEdit *typeEdit;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *imageIDEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QBckDialog)
    {
        if (QBckDialog->objectName().isEmpty())
            QBckDialog->setObjectName(QStringLiteral("QBckDialog"));
        QBckDialog->resize(361, 516);
        gridLayout = new QGridLayout(QBckDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addButton = new QPushButton(QBckDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/add-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(QBckDialog);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);

        verticalLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        upButton = new QPushButton(QBckDialog);
        upButton->setObjectName(QStringLiteral("upButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon2);

        verticalLayout->addWidget(upButton);

        downButton = new QPushButton(QBckDialog);
        downButton->setObjectName(QStringLiteral("downButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowDown.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon3);

        verticalLayout->addWidget(downButton);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        speedYEdit = new QLineEdit(QBckDialog);
        speedYEdit->setObjectName(QStringLiteral("speedYEdit"));
        speedYEdit->setReadOnly(true);

        gridLayout->addWidget(speedYEdit, 5, 1, 1, 1);

        scrollArea = new QScrollArea(QBckDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 200));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 341, 198));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 6, 0, 1, 2);

        label_3 = new QLabel(QBckDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(QBckDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        nameLabel = new QLabel(QBckDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 1, 0, 1, 2);

        bckList = new QListWidget(QBckDialog);
        bckList->setObjectName(QStringLiteral("bckList"));

        gridLayout->addWidget(bckList, 0, 0, 1, 1);

        speedXEdit = new QLineEdit(QBckDialog);
        speedXEdit->setObjectName(QStringLiteral("speedXEdit"));
        speedXEdit->setReadOnly(true);

        gridLayout->addWidget(speedXEdit, 4, 1, 1, 1);

        typeEdit = new QLineEdit(QBckDialog);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));
        typeEdit->setReadOnly(true);

        gridLayout->addWidget(typeEdit, 3, 1, 1, 1);

        label = new QLabel(QBckDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(QBckDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        imageIDEdit = new QLineEdit(QBckDialog);
        imageIDEdit->setObjectName(QStringLiteral("imageIDEdit"));
        imageIDEdit->setEnabled(true);
        imageIDEdit->setReadOnly(true);

        gridLayout->addWidget(imageIDEdit, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(QBckDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 1, 1, 1);


        retranslateUi(QBckDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QBckDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QBckDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QBckDialog);
    } // setupUi

    void retranslateUi(QDialog *QBckDialog)
    {
        QBckDialog->setWindowTitle(QApplication::translate("QBckDialog", "Background manager", 0));
        addButton->setText(QString());
        deleteButton->setText(QString());
        upButton->setText(QString());
        downButton->setText(QString());
        label_3->setText(QApplication::translate("QBckDialog", "X movement speed", 0));
        label_2->setText(QApplication::translate("QBckDialog", "Type", 0));
        nameLabel->setText(QApplication::translate("QBckDialog", "<No item selected>", 0));
        label->setText(QApplication::translate("QBckDialog", "Image ID", 0));
        label_4->setText(QApplication::translate("QBckDialog", "Y movement speed", 0));
    } // retranslateUi

};

namespace Ui {
    class QBckDialog: public Ui_QBckDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBCKDIALOG_H
