/********************************************************************************
** Form generated from reading UI file 'QAddSoundDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QADDSOUNDDIALOG_H
#define UI_QADDSOUNDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QAddSoundDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *idLabel;
    QLineEdit *idEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *sourceLabel;
    QLineEdit *sourceEdit;
    QPushButton *browseButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QAddSoundDialog)
    {
        if (QAddSoundDialog->objectName().isEmpty())
            QAddSoundDialog->setObjectName(QStringLiteral("QAddSoundDialog"));
        QAddSoundDialog->resize(174, 100);
        verticalLayout = new QVBoxLayout(QAddSoundDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        idLabel = new QLabel(QAddSoundDialog);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        horizontalLayout_4->addWidget(idLabel);

        idEdit = new QLineEdit(QAddSoundDialog);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        horizontalLayout_4->addWidget(idEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        sourceLabel = new QLabel(QAddSoundDialog);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));

        horizontalLayout_5->addWidget(sourceLabel);

        sourceEdit = new QLineEdit(QAddSoundDialog);
        sourceEdit->setObjectName(QStringLiteral("sourceEdit"));

        horizontalLayout_5->addWidget(sourceEdit);

        browseButton = new QPushButton(QAddSoundDialog);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_5->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(QAddSoundDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(QAddSoundDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QAddSoundDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QAddSoundDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QAddSoundDialog);
    } // setupUi

    void retranslateUi(QDialog *QAddSoundDialog)
    {
        QAddSoundDialog->setWindowTitle(QApplication::translate("QAddSoundDialog", "New sound", 0));
        idLabel->setText(QApplication::translate("QAddSoundDialog", "ID", 0));
        sourceLabel->setText(QApplication::translate("QAddSoundDialog", "Source", 0));
        browseButton->setText(QApplication::translate("QAddSoundDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class QAddSoundDialog: public Ui_QAddSoundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QADDSOUNDDIALOG_H
