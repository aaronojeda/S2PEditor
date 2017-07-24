/********************************************************************************
** Form generated from reading UI file 'QNewSpriteDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWSPRITEDIALOG_H
#define UI_QNEWSPRITEDIALOG_H

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

class Ui_QNewSpriteDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *textureIDLabel;
    QLineEdit *idEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *sourceLabel;
    QLineEdit *sourceEdit;
    QPushButton *browseButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QNewSpriteDialog)
    {
        if (QNewSpriteDialog->objectName().isEmpty())
            QNewSpriteDialog->setObjectName(QStringLiteral("QNewSpriteDialog"));
        QNewSpriteDialog->resize(194, 100);
        verticalLayout = new QVBoxLayout(QNewSpriteDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textureIDLabel = new QLabel(QNewSpriteDialog);
        textureIDLabel->setObjectName(QStringLiteral("textureIDLabel"));

        horizontalLayout_4->addWidget(textureIDLabel);

        idEdit = new QLineEdit(QNewSpriteDialog);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        horizontalLayout_4->addWidget(idEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        sourceLabel = new QLabel(QNewSpriteDialog);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));

        horizontalLayout_5->addWidget(sourceLabel);

        sourceEdit = new QLineEdit(QNewSpriteDialog);
        sourceEdit->setObjectName(QStringLiteral("sourceEdit"));

        horizontalLayout_5->addWidget(sourceEdit);

        browseButton = new QPushButton(QNewSpriteDialog);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_5->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(QNewSpriteDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(QNewSpriteDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNewSpriteDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNewSpriteDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNewSpriteDialog);
    } // setupUi

    void retranslateUi(QDialog *QNewSpriteDialog)
    {
        QNewSpriteDialog->setWindowTitle(QApplication::translate("QNewSpriteDialog", "New image", 0));
        textureIDLabel->setText(QApplication::translate("QNewSpriteDialog", "ID", 0));
        sourceLabel->setText(QApplication::translate("QNewSpriteDialog", "Source", 0));
        browseButton->setText(QApplication::translate("QNewSpriteDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class QNewSpriteDialog: public Ui_QNewSpriteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWSPRITEDIALOG_H
