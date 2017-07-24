/********************************************************************************
** Form generated from reading UI file 'QNewTilesetDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWTILESETDIALOG_H
#define UI_QNEWTILESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QNewTilesetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *textureIDLabel;
    QComboBox *textureIDCombo;
    QPushButton *newTextureButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *sizeSpin;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spacingSpin;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *marginSpin;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QNewTilesetDialog)
    {
        if (QNewTilesetDialog->objectName().isEmpty())
            QNewTilesetDialog->setObjectName(QStringLiteral("QNewTilesetDialog"));
        QNewTilesetDialog->resize(199, 219);
        verticalLayout = new QVBoxLayout(QNewTilesetDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(QNewTilesetDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(QNewTilesetDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(QNewTilesetDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        textureIDLabel = new QLabel(groupBox);
        textureIDLabel->setObjectName(QStringLiteral("textureIDLabel"));

        horizontalLayout_6->addWidget(textureIDLabel);

        textureIDCombo = new QComboBox(groupBox);
        textureIDCombo->setObjectName(QStringLiteral("textureIDCombo"));
        textureIDCombo->setMinimumSize(QSize(100, 0));

        horizontalLayout_6->addWidget(textureIDCombo);

        newTextureButton = new QPushButton(groupBox);
        newTextureButton->setObjectName(QStringLiteral("newTextureButton"));
        newTextureButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_6->addWidget(newTextureButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(53, 0));

        horizontalLayout_5->addWidget(label_5);

        sizeSpin = new QSpinBox(groupBox);
        sizeSpin->setObjectName(QStringLiteral("sizeSpin"));
        sizeSpin->setMaximum(999);
        sizeSpin->setValue(32);

        horizontalLayout_5->addWidget(sizeSpin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(53, 0));

        horizontalLayout_4->addWidget(label_4);

        spacingSpin = new QSpinBox(groupBox);
        spacingSpin->setObjectName(QStringLiteral("spacingSpin"));
        spacingSpin->setMinimumSize(QSize(58, 0));
        spacingSpin->setValue(0);

        horizontalLayout_4->addWidget(spacingSpin);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(53, 0));

        horizontalLayout_3->addWidget(label_6);

        marginSpin = new QSpinBox(groupBox);
        marginSpin->setObjectName(QStringLiteral("marginSpin"));
        marginSpin->setMinimumSize(QSize(58, 0));
        marginSpin->setValue(0);

        horizontalLayout_3->addWidget(marginSpin);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(QNewTilesetDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(QNewTilesetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNewTilesetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNewTilesetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNewTilesetDialog);
    } // setupUi

    void retranslateUi(QDialog *QNewTilesetDialog)
    {
        QNewTilesetDialog->setWindowTitle(QApplication::translate("QNewTilesetDialog", "New Tileset", 0));
        label->setText(QApplication::translate("QNewTilesetDialog", "Name:", 0));
        nameEdit->setText(QString());
        groupBox->setTitle(QApplication::translate("QNewTilesetDialog", "Image", 0));
        textureIDLabel->setText(QApplication::translate("QNewTilesetDialog", "ID", 0));
        newTextureButton->setText(QApplication::translate("QNewTilesetDialog", "...", 0));
        label_5->setText(QApplication::translate("QNewTilesetDialog", "Tile size:", 0));
        sizeSpin->setSuffix(QApplication::translate("QNewTilesetDialog", " px", 0));
        label_4->setText(QApplication::translate("QNewTilesetDialog", "Spacing:", 0));
        spacingSpin->setSuffix(QApplication::translate("QNewTilesetDialog", " px", 0));
        label_6->setText(QApplication::translate("QNewTilesetDialog", "Margin:", 0));
        marginSpin->setSuffix(QApplication::translate("QNewTilesetDialog", " px", 0));
    } // retranslateUi

};

namespace Ui {
    class QNewTilesetDialog: public Ui_QNewTilesetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWTILESETDIALOG_H
