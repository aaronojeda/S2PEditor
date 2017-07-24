/********************************************************************************
** Form generated from reading UI file 'QNewProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWPROJECTDIALOG_H
#define UI_QNEWPROJECTDIALOG_H

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

class Ui_QNewProjectDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *projectNameEdit;
    QGroupBox *levelGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *levelNameLabel;
    QLineEdit *levelNameEdit;
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

    void setupUi(QDialog *QNewProjectDialog)
    {
        if (QNewProjectDialog->objectName().isEmpty())
            QNewProjectDialog->setObjectName(QStringLiteral("QNewProjectDialog"));
        QNewProjectDialog->resize(200, 216);
        verticalLayout_2 = new QVBoxLayout(QNewProjectDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(QNewProjectDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        projectNameEdit = new QLineEdit(QNewProjectDialog);
        projectNameEdit->setObjectName(QStringLiteral("projectNameEdit"));

        horizontalLayout_5->addWidget(projectNameEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        levelGroupBox = new QGroupBox(QNewProjectDialog);
        levelGroupBox->setObjectName(QStringLiteral("levelGroupBox"));
        verticalLayout = new QVBoxLayout(levelGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        levelNameLabel = new QLabel(levelGroupBox);
        levelNameLabel->setObjectName(QStringLiteral("levelNameLabel"));

        horizontalLayout_7->addWidget(levelNameLabel);

        levelNameEdit = new QLineEdit(levelGroupBox);
        levelNameEdit->setObjectName(QStringLiteral("levelNameEdit"));

        horizontalLayout_7->addWidget(levelNameEdit);


        verticalLayout->addLayout(horizontalLayout_7);

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


        verticalLayout_2->addWidget(levelGroupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(QNewProjectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(QNewProjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNewProjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNewProjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *QNewProjectDialog)
    {
        QNewProjectDialog->setWindowTitle(QApplication::translate("QNewProjectDialog", "New project", 0));
        label->setText(QApplication::translate("QNewProjectDialog", "Project Name:", 0));
        levelGroupBox->setTitle(QApplication::translate("QNewProjectDialog", "First level", 0));
        levelNameLabel->setText(QApplication::translate("QNewProjectDialog", "Name:", 0));
        levelWidthLabel->setText(QApplication::translate("QNewProjectDialog", "Width", 0));
        levelWidthSpin->setSpecialValueText(QString());
        levelWidthSpin->setSuffix(QApplication::translate("QNewProjectDialog", " tiles", 0));
        levelHeightLabel->setText(QApplication::translate("QNewProjectDialog", "Height", 0));
        levelHeightSpin->setSuffix(QApplication::translate("QNewProjectDialog", " tiles", 0));
        tileSizeLabel->setText(QApplication::translate("QNewProjectDialog", "Tile size", 0));
        tileSizeSpin->setSuffix(QApplication::translate("QNewProjectDialog", " px", 0));
    } // retranslateUi

};

namespace Ui {
    class QNewProjectDialog: public Ui_QNewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWPROJECTDIALOG_H
