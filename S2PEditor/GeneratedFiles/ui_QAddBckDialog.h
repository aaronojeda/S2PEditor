/********************************************************************************
** Form generated from reading UI file 'QAddBckDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QADDBCKDIALOG_H
#define UI_QADDBCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_QAddBckDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *typeCombo;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *imageCombo;
    QPushButton *newImageButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *xSpeedSpin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *ySpeedSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QAddBckDialog)
    {
        if (QAddBckDialog->objectName().isEmpty())
            QAddBckDialog->setObjectName(QStringLiteral("QAddBckDialog"));
        QAddBckDialog->resize(210, 154);
        formLayout = new QFormLayout(QAddBckDialog);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(QAddBckDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        typeCombo = new QComboBox(QAddBckDialog);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, typeCombo);

        label_2 = new QLabel(QAddBckDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageCombo = new QComboBox(QAddBckDialog);
        imageCombo->setObjectName(QStringLiteral("imageCombo"));

        horizontalLayout->addWidget(imageCombo);

        newImageButton = new QPushButton(QAddBckDialog);
        newImageButton->setObjectName(QStringLiteral("newImageButton"));
        newImageButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(newImageButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(QAddBckDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        xSpeedSpin = new QSpinBox(QAddBckDialog);
        xSpeedSpin->setObjectName(QStringLiteral("xSpeedSpin"));

        horizontalLayout_2->addWidget(xSpeedSpin);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(QAddBckDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        ySpeedSpin = new QSpinBox(QAddBckDialog);
        ySpeedSpin->setObjectName(QStringLiteral("ySpeedSpin"));

        horizontalLayout_3->addWidget(ySpeedSpin);


        formLayout->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_3);

        buttonBox = new QDialogButtonBox(QAddBckDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::FieldRole, buttonBox);


        retranslateUi(QAddBckDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QAddBckDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QAddBckDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QAddBckDialog);
    } // setupUi

    void retranslateUi(QDialog *QAddBckDialog)
    {
        QAddBckDialog->setWindowTitle(QApplication::translate("QAddBckDialog", "Add background", 0));
        label->setText(QApplication::translate("QAddBckDialog", "Type", 0));
        label_2->setText(QApplication::translate("QAddBckDialog", "Image", 0));
        newImageButton->setText(QApplication::translate("QAddBckDialog", "...", 0));
        label_3->setText(QApplication::translate("QAddBckDialog", "X speed", 0));
        label_4->setText(QApplication::translate("QAddBckDialog", "Y speed", 0));
    } // retranslateUi

};

namespace Ui {
    class QAddBckDialog: public Ui_QAddBckDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QADDBCKDIALOG_H
