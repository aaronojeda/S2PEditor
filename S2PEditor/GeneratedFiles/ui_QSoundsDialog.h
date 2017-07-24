/********************************************************************************
** Form generated from reading UI file 'QSoundsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSOUNDSDIALOG_H
#define UI_QSOUNDSDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QSoundsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *soundList;
    QVBoxLayout *verticalLayout;
    QPushButton *addSfxButton;
    QPushButton *deleteSfxButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *musicList;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addMusicButton;
    QPushButton *deleteMusicButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *idLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *sourceLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *typeLine;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QSoundsDialog)
    {
        if (QSoundsDialog->objectName().isEmpty())
            QSoundsDialog->setObjectName(QStringLiteral("QSoundsDialog"));
        QSoundsDialog->resize(391, 339);
        verticalLayout_3 = new QVBoxLayout(QSoundsDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(QSoundsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        soundList = new QListWidget(groupBox);
        soundList->setObjectName(QStringLiteral("soundList"));
        soundList->setMaximumSize(QSize(16777215, 200));

        horizontalLayout_5->addWidget(soundList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addSfxButton = new QPushButton(groupBox);
        addSfxButton->setObjectName(QStringLiteral("addSfxButton"));
        addSfxButton->setMaximumSize(QSize(28, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/add-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        addSfxButton->setIcon(icon);

        verticalLayout->addWidget(addSfxButton);

        deleteSfxButton = new QPushButton(groupBox);
        deleteSfxButton->setObjectName(QStringLiteral("deleteSfxButton"));
        deleteSfxButton->setMaximumSize(QSize(28, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteSfxButton->setIcon(icon1);

        verticalLayout->addWidget(deleteSfxButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(QSoundsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        musicList = new QListWidget(groupBox_2);
        musicList->setObjectName(QStringLiteral("musicList"));
        musicList->setMaximumSize(QSize(16777215, 200));

        horizontalLayout_6->addWidget(musicList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addMusicButton = new QPushButton(groupBox_2);
        addMusicButton->setObjectName(QStringLiteral("addMusicButton"));
        addMusicButton->setMaximumSize(QSize(28, 16777215));
        addMusicButton->setIcon(icon);

        verticalLayout_2->addWidget(addMusicButton);

        deleteMusicButton = new QPushButton(groupBox_2);
        deleteMusicButton->setObjectName(QStringLiteral("deleteMusicButton"));
        deleteMusicButton->setMaximumSize(QSize(28, 16777215));
        deleteMusicButton->setIcon(icon1);

        verticalLayout_2->addWidget(deleteMusicButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_6->addLayout(verticalLayout_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        idLabel = new QLabel(QSoundsDialog);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout_3->addWidget(idLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(QSoundsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sourceLine = new QLineEdit(QSoundsDialog);
        sourceLine->setObjectName(QStringLiteral("sourceLine"));
        sourceLine->setReadOnly(true);

        horizontalLayout->addWidget(sourceLine);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(QSoundsDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        typeLine = new QLineEdit(QSoundsDialog);
        typeLine->setObjectName(QStringLiteral("typeLine"));
        typeLine->setReadOnly(true);

        horizontalLayout_2->addWidget(typeLine);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(QSoundsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(QSoundsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QSoundsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QSoundsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QSoundsDialog);
    } // setupUi

    void retranslateUi(QDialog *QSoundsDialog)
    {
        QSoundsDialog->setWindowTitle(QApplication::translate("QSoundsDialog", "Sound manager", 0));
        groupBox->setTitle(QApplication::translate("QSoundsDialog", "Sound effects", 0));
        addSfxButton->setText(QString());
        deleteSfxButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("QSoundsDialog", "Music tracks", 0));
        addMusicButton->setText(QString());
        deleteMusicButton->setText(QString());
        idLabel->setText(QApplication::translate("QSoundsDialog", "<No item selected>", 0));
        label_2->setText(QApplication::translate("QSoundsDialog", "Source:", 0));
        label->setText(QApplication::translate("QSoundsDialog", "Type:", 0));
    } // retranslateUi

};

namespace Ui {
    class QSoundsDialog: public Ui_QSoundsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSOUNDSDIALOG_H
