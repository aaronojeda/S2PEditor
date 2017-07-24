/********************************************************************************
** Form generated from reading UI file 'QNewLevelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWLEVELDIALOG_H
#define UI_QNEWLEVELDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QNewLevelDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *levelNameLabel;
    QLineEdit *levelNameEdit;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *levelGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *levelWidthLabel;
    QSpinBox *levelWidthSpin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *levelHeightLabel;
    QSpinBox *levelHeightSpin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *tileSizeLabel;
    QSpinBox *tileSizeSpin;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QNewLevelDialog)
    {
        if (QNewLevelDialog->objectName().isEmpty())
            QNewLevelDialog->setObjectName(QStringLiteral("QNewLevelDialog"));
        QNewLevelDialog->resize(182, 190);
        verticalLayout_3 = new QVBoxLayout(QNewLevelDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        levelNameLabel = new QLabel(QNewLevelDialog);
        levelNameLabel->setObjectName(QStringLiteral("levelNameLabel"));

        horizontalLayout_7->addWidget(levelNameLabel);

        levelNameEdit = new QLineEdit(QNewLevelDialog);
        levelNameEdit->setObjectName(QStringLiteral("levelNameEdit"));

        horizontalLayout_7->addWidget(levelNameEdit);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        levelGroupBox = new QGroupBox(QNewLevelDialog);
        levelGroupBox->setObjectName(QStringLiteral("levelGroupBox"));
        verticalLayout = new QVBoxLayout(levelGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        levelWidthLabel = new QLabel(levelGroupBox);
        levelWidthLabel->setObjectName(QStringLiteral("levelWidthLabel"));

        horizontalLayout->addWidget(levelWidthLabel);

        levelWidthSpin = new QSpinBox(levelGroupBox);
        levelWidthSpin->setObjectName(QStringLiteral("levelWidthSpin"));
        levelWidthSpin->setMinimum(1);
        levelWidthSpin->setMaximum(99999);
        levelWidthSpin->setValue(20);

        horizontalLayout->addWidget(levelWidthSpin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        levelHeightLabel = new QLabel(levelGroupBox);
        levelHeightLabel->setObjectName(QStringLiteral("levelHeightLabel"));

        horizontalLayout_3->addWidget(levelHeightLabel);

        levelHeightSpin = new QSpinBox(levelGroupBox);
        levelHeightSpin->setObjectName(QStringLiteral("levelHeightSpin"));
        levelHeightSpin->setMinimum(1);
        levelHeightSpin->setMaximum(99999);
        levelHeightSpin->setValue(15);

        horizontalLayout_3->addWidget(levelHeightSpin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tileSizeLabel = new QLabel(levelGroupBox);
        tileSizeLabel->setObjectName(QStringLiteral("tileSizeLabel"));

        horizontalLayout_4->addWidget(tileSizeLabel);

        tileSizeSpin = new QSpinBox(levelGroupBox);
        tileSizeSpin->setObjectName(QStringLiteral("tileSizeSpin"));
        tileSizeSpin->setMinimumSize(QSize(77, 0));
        tileSizeSpin->setMinimum(1);
        tileSizeSpin->setMaximum(9999);
        tileSizeSpin->setValue(32);

        horizontalLayout_4->addWidget(tileSizeSpin);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_6->addWidget(levelGroupBox);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(QNewLevelDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(QNewLevelDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNewLevelDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNewLevelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNewLevelDialog);
    } // setupUi

    void retranslateUi(QDialog *QNewLevelDialog)
    {
        QNewLevelDialog->setWindowTitle(QApplication::translate("QNewLevelDialog", "New level", 0));
        levelNameLabel->setText(QApplication::translate("QNewLevelDialog", "Name:", 0));
        levelGroupBox->setTitle(QApplication::translate("QNewLevelDialog", "Level settings", 0));
        levelWidthLabel->setText(QApplication::translate("QNewLevelDialog", "Width", 0));
        levelWidthSpin->setSpecialValueText(QString());
        levelWidthSpin->setSuffix(QApplication::translate("QNewLevelDialog", " tiles", 0));
        levelHeightLabel->setText(QApplication::translate("QNewLevelDialog", "Height", 0));
        levelHeightSpin->setSuffix(QApplication::translate("QNewLevelDialog", " tiles", 0));
        tileSizeLabel->setText(QApplication::translate("QNewLevelDialog", "Tile size", 0));
        tileSizeSpin->setSuffix(QApplication::translate("QNewLevelDialog", " px", 0));
    } // retranslateUi

};

namespace Ui {
    class QNewLevelDialog: public Ui_QNewLevelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWLEVELDIALOG_H
