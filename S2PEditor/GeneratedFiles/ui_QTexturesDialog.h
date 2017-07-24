/********************************************************************************
** Form generated from reading UI file 'QTexturesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEXTURESDIALOG_H
#define UI_QTEXTURESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
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

class Ui_QTexturesDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *textureList;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QLabel *idLabel;
    QLineEdit *sourceLine;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QTexturesDialog)
    {
        if (QTexturesDialog->objectName().isEmpty())
            QTexturesDialog->setObjectName(QStringLiteral("QTexturesDialog"));
        QTexturesDialog->resize(318, 479);
        verticalLayout_2 = new QVBoxLayout(QTexturesDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(QTexturesDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        textureList = new QListWidget(groupBox);
        textureList->setObjectName(QStringLiteral("textureList"));
        textureList->setMaximumSize(QSize(16777215, 200));

        horizontalLayout_5->addWidget(textureList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addButton = new QPushButton(groupBox);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setMaximumSize(QSize(28, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/add-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setMaximumSize(QSize(28, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon1);

        verticalLayout->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox);

        idLabel = new QLabel(QTexturesDialog);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout_2->addWidget(idLabel);

        sourceLine = new QLineEdit(QTexturesDialog);
        sourceLine->setObjectName(QStringLiteral("sourceLine"));
        sourceLine->setReadOnly(true);

        verticalLayout_2->addWidget(sourceLine);

        scrollArea = new QScrollArea(QTexturesDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 179));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(QTexturesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(QTexturesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QTexturesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QTexturesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QTexturesDialog);
    } // setupUi

    void retranslateUi(QDialog *QTexturesDialog)
    {
        QTexturesDialog->setWindowTitle(QApplication::translate("QTexturesDialog", "Texture Manager", 0));
        groupBox->setTitle(QString());
        addButton->setText(QString());
        deleteButton->setText(QString());
        idLabel->setText(QApplication::translate("QTexturesDialog", "<No item selected>", 0));
    } // retranslateUi

};

namespace Ui {
    class QTexturesDialog: public Ui_QTexturesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEXTURESDIALOG_H
