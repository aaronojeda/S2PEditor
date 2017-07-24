/********************************************************************************
** Form generated from reading UI file 'QNewObjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNEWOBJECTDIALOG_H
#define UI_QNEWOBJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QNewObjectDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *typeEdit;
    QLabel *typeLabel;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *spriteBox;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *textureIDLabel;
    QComboBox *spriteCombo;
    QPushButton *newSpriteButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *widthLabel;
    QSpinBox *widthSpin;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_13;
    QLabel *heightLabel;
    QSpinBox *heightSpin;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *boundingBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *xBLabel;
    QSpinBox *xBSpin;
    QHBoxLayout *horizontalLayout_9;
    QLabel *yBLabel;
    QSpinBox *yBSpin;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *wBLabel;
    QSpinBox *wBSpin;
    QHBoxLayout *horizontalLayout_10;
    QLabel *hBLabel;
    QSpinBox *hBSpin;
    QPushButton *drawButton;
    QHBoxLayout *horizontalLayout;
    QGroupBox *valueGroupBox;
    QGridLayout *gridLayout_5;
    QSpinBox *xSpeedSpin;
    QLabel *ySpeedLabel;
    QLabel *xSpeedLabel;
    QLabel *value3Label;
    QSpinBox *value3Spin;
    QSpinBox *ySpeedSpin;
    QSpinBox *valueSpin;
    QSpinBox *value2Spin;
    QLabel *value2Label;
    QLabel *valueLabel;
    QSpacerItem *horizontalSpacer;
    QGroupBox *soundBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *soundLabel;
    QComboBox *soundCombo;
    QPushButton *newSoundButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *sound2Label;
    QComboBox *sound2Combo;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *m_animBox;
    QScrollArea *spriteSheetSArea;
    QWidget *scrollAreaWidgetContents;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QNewObjectDialog)
    {
        if (QNewObjectDialog->objectName().isEmpty())
            QNewObjectDialog->setObjectName(QStringLiteral("QNewObjectDialog"));
        QNewObjectDialog->resize(658, 520);
        verticalLayout_3 = new QVBoxLayout(QNewObjectDialog);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        typeEdit = new QLineEdit(QNewObjectDialog);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));
        typeEdit->setEnabled(false);
        typeEdit->setMaximumSize(QSize(133, 20));

        gridLayout_2->addWidget(typeEdit, 1, 1, 1, 1);

        typeLabel = new QLabel(QNewObjectDialog);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setMinimumSize(QSize(27, 0));

        gridLayout_2->addWidget(typeLabel, 1, 0, 1, 1);

        nameLabel = new QLabel(QNewObjectDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_2->addWidget(nameLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(QNewObjectDialog);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setMaximumSize(QSize(134, 20));

        gridLayout_2->addWidget(nameEdit, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        spriteBox = new QGroupBox(QNewObjectDialog);
        spriteBox->setObjectName(QStringLiteral("spriteBox"));
        verticalLayout_9 = new QVBoxLayout(spriteBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        textureIDLabel = new QLabel(spriteBox);
        textureIDLabel->setObjectName(QStringLiteral("textureIDLabel"));
        textureIDLabel->setMinimumSize(QSize(31, 0));

        horizontalLayout_11->addWidget(textureIDLabel);

        spriteCombo = new QComboBox(spriteBox);
        spriteCombo->setObjectName(QStringLiteral("spriteCombo"));
        spriteCombo->setMinimumSize(QSize(150, 0));

        horizontalLayout_11->addWidget(spriteCombo);

        newSpriteButton = new QPushButton(spriteBox);
        newSpriteButton->setObjectName(QStringLiteral("newSpriteButton"));
        newSpriteButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_11->addWidget(newSpriteButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        widthLabel = new QLabel(spriteBox);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        widthLabel->setMinimumSize(QSize(31, 0));

        horizontalLayout_12->addWidget(widthLabel);

        widthSpin = new QSpinBox(spriteBox);
        widthSpin->setObjectName(QStringLiteral("widthSpin"));
        widthSpin->setMaximum(99999);
        widthSpin->setValue(0);

        horizontalLayout_12->addWidget(widthSpin);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);


        verticalLayout_9->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        heightLabel = new QLabel(spriteBox);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));

        horizontalLayout_13->addWidget(heightLabel);

        heightSpin = new QSpinBox(spriteBox);
        heightSpin->setObjectName(QStringLiteral("heightSpin"));
        heightSpin->setMaximum(99999);
        heightSpin->setValue(0);

        horizontalLayout_13->addWidget(heightSpin);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_10);


        verticalLayout_9->addLayout(horizontalLayout_13);


        verticalLayout_2->addWidget(spriteBox);

        boundingBox = new QGroupBox(QNewObjectDialog);
        boundingBox->setObjectName(QStringLiteral("boundingBox"));
        boundingBox->setEnabled(true);
        boundingBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_6 = new QVBoxLayout(boundingBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        xBLabel = new QLabel(boundingBox);
        xBLabel->setObjectName(QStringLiteral("xBLabel"));

        horizontalLayout_7->addWidget(xBLabel);

        xBSpin = new QSpinBox(boundingBox);
        xBSpin->setObjectName(QStringLiteral("xBSpin"));
        xBSpin->setMaximum(99999);

        horizontalLayout_7->addWidget(xBSpin);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        yBLabel = new QLabel(boundingBox);
        yBLabel->setObjectName(QStringLiteral("yBLabel"));

        horizontalLayout_9->addWidget(yBLabel);

        yBSpin = new QSpinBox(boundingBox);
        yBSpin->setObjectName(QStringLiteral("yBSpin"));
        yBSpin->setMaximum(99999);

        horizontalLayout_9->addWidget(yBSpin);


        verticalLayout_5->addLayout(horizontalLayout_9);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        wBLabel = new QLabel(boundingBox);
        wBLabel->setObjectName(QStringLiteral("wBLabel"));
        wBLabel->setMinimumSize(QSize(31, 0));

        horizontalLayout_8->addWidget(wBLabel);

        wBSpin = new QSpinBox(boundingBox);
        wBSpin->setObjectName(QStringLiteral("wBSpin"));
        wBSpin->setMaximum(99999);

        horizontalLayout_8->addWidget(wBSpin);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        hBLabel = new QLabel(boundingBox);
        hBLabel->setObjectName(QStringLiteral("hBLabel"));

        horizontalLayout_10->addWidget(hBLabel);

        hBSpin = new QSpinBox(boundingBox);
        hBSpin->setObjectName(QStringLiteral("hBSpin"));
        hBSpin->setMaximum(99999);

        horizontalLayout_10->addWidget(hBSpin);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout_3->addLayout(verticalLayout);

        drawButton = new QPushButton(boundingBox);
        drawButton->setObjectName(QStringLiteral("drawButton"));
        drawButton->setMinimumSize(QSize(0, 0));
        drawButton->setMaximumSize(QSize(40, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawButton->setIcon(icon);

        horizontalLayout_3->addWidget(drawButton);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(boundingBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        valueGroupBox = new QGroupBox(QNewObjectDialog);
        valueGroupBox->setObjectName(QStringLiteral("valueGroupBox"));
        valueGroupBox->setEnabled(true);
        gridLayout_5 = new QGridLayout(valueGroupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        xSpeedSpin = new QSpinBox(valueGroupBox);
        xSpeedSpin->setObjectName(QStringLiteral("xSpeedSpin"));
        xSpeedSpin->setMinimum(-99);
        xSpeedSpin->setMaximum(99);

        gridLayout_5->addWidget(xSpeedSpin, 0, 1, 1, 1);

        ySpeedLabel = new QLabel(valueGroupBox);
        ySpeedLabel->setObjectName(QStringLiteral("ySpeedLabel"));

        gridLayout_5->addWidget(ySpeedLabel, 1, 0, 1, 1);

        xSpeedLabel = new QLabel(valueGroupBox);
        xSpeedLabel->setObjectName(QStringLiteral("xSpeedLabel"));

        gridLayout_5->addWidget(xSpeedLabel, 0, 0, 1, 1);

        value3Label = new QLabel(valueGroupBox);
        value3Label->setObjectName(QStringLiteral("value3Label"));

        gridLayout_5->addWidget(value3Label, 2, 0, 1, 1);

        value3Spin = new QSpinBox(valueGroupBox);
        value3Spin->setObjectName(QStringLiteral("value3Spin"));
        value3Spin->setMaximum(9999);

        gridLayout_5->addWidget(value3Spin, 2, 1, 1, 1);

        ySpeedSpin = new QSpinBox(valueGroupBox);
        ySpeedSpin->setObjectName(QStringLiteral("ySpeedSpin"));
        ySpeedSpin->setMinimum(-99);
        ySpeedSpin->setMaximum(99);

        gridLayout_5->addWidget(ySpeedSpin, 1, 1, 1, 1);

        valueSpin = new QSpinBox(valueGroupBox);
        valueSpin->setObjectName(QStringLiteral("valueSpin"));
        valueSpin->setMinimum(0);
        valueSpin->setMaximum(9999);

        gridLayout_5->addWidget(valueSpin, 0, 3, 1, 1);

        value2Spin = new QSpinBox(valueGroupBox);
        value2Spin->setObjectName(QStringLiteral("value2Spin"));
        value2Spin->setMaximum(9999);

        gridLayout_5->addWidget(value2Spin, 1, 3, 1, 1);

        value2Label = new QLabel(valueGroupBox);
        value2Label->setObjectName(QStringLiteral("value2Label"));
        value2Label->setEnabled(true);

        gridLayout_5->addWidget(value2Label, 1, 2, 1, 1);

        valueLabel = new QLabel(valueGroupBox);
        valueLabel->setObjectName(QStringLiteral("valueLabel"));

        gridLayout_5->addWidget(valueLabel, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 4, 1, 1);


        horizontalLayout->addWidget(valueGroupBox);


        verticalLayout_2->addLayout(horizontalLayout);

        soundBox = new QGroupBox(QNewObjectDialog);
        soundBox->setObjectName(QStringLiteral("soundBox"));
        verticalLayout_7 = new QVBoxLayout(soundBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        soundLabel = new QLabel(soundBox);
        soundLabel->setObjectName(QStringLiteral("soundLabel"));
        soundLabel->setMinimumSize(QSize(31, 0));

        horizontalLayout_4->addWidget(soundLabel);

        soundCombo = new QComboBox(soundBox);
        soundCombo->setObjectName(QStringLiteral("soundCombo"));
        soundCombo->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(soundCombo);

        newSoundButton = new QPushButton(soundBox);
        newSoundButton->setObjectName(QStringLiteral("newSoundButton"));
        newSoundButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(newSoundButton);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        sound2Label = new QLabel(soundBox);
        sound2Label->setObjectName(QStringLiteral("sound2Label"));
        sound2Label->setMinimumSize(QSize(44, 0));

        horizontalLayout_5->addWidget(sound2Label);

        sound2Combo = new QComboBox(soundBox);
        sound2Combo->setObjectName(QStringLiteral("sound2Combo"));
        sound2Combo->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(sound2Combo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(soundBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        m_animBox = new QGroupBox(QNewObjectDialog);
        m_animBox->setObjectName(QStringLiteral("m_animBox"));
        m_animBox->setMinimumSize(QSize(370, 180));

        verticalLayout_4->addWidget(m_animBox);

        spriteSheetSArea = new QScrollArea(QNewObjectDialog);
        spriteSheetSArea->setObjectName(QStringLiteral("spriteSheetSArea"));
        spriteSheetSArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 281));
        spriteSheetSArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(spriteSheetSArea);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(QNewObjectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);

        QWidget::setTabOrder(nameEdit, typeEdit);
        QWidget::setTabOrder(typeEdit, spriteCombo);
        QWidget::setTabOrder(spriteCombo, newSpriteButton);
        QWidget::setTabOrder(newSpriteButton, widthSpin);
        QWidget::setTabOrder(widthSpin, heightSpin);
        QWidget::setTabOrder(heightSpin, xBSpin);
        QWidget::setTabOrder(xBSpin, yBSpin);
        QWidget::setTabOrder(yBSpin, wBSpin);
        QWidget::setTabOrder(wBSpin, hBSpin);
        QWidget::setTabOrder(hBSpin, drawButton);
        QWidget::setTabOrder(drawButton, xSpeedSpin);
        QWidget::setTabOrder(xSpeedSpin, ySpeedSpin);
        QWidget::setTabOrder(ySpeedSpin, value3Spin);
        QWidget::setTabOrder(value3Spin, spriteSheetSArea);

        retranslateUi(QNewObjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QNewObjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QNewObjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QNewObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *QNewObjectDialog)
    {
        QNewObjectDialog->setWindowTitle(QApplication::translate("QNewObjectDialog", "New object", 0));
        typeLabel->setText(QApplication::translate("QNewObjectDialog", "Type", 0));
        nameLabel->setText(QApplication::translate("QNewObjectDialog", "Name", 0));
        spriteBox->setTitle(QApplication::translate("QNewObjectDialog", "Sprite", 0));
        textureIDLabel->setText(QApplication::translate("QNewObjectDialog", "ID", 0));
        newSpriteButton->setText(QApplication::translate("QNewObjectDialog", "...", 0));
        widthLabel->setText(QApplication::translate("QNewObjectDialog", "Width", 0));
        heightLabel->setText(QApplication::translate("QNewObjectDialog", "Height", 0));
        boundingBox->setTitle(QApplication::translate("QNewObjectDialog", "Bounding box", 0));
        xBLabel->setText(QApplication::translate("QNewObjectDialog", "x", 0));
        yBLabel->setText(QApplication::translate("QNewObjectDialog", "y", 0));
        wBLabel->setText(QApplication::translate("QNewObjectDialog", "Width", 0));
        hBLabel->setText(QApplication::translate("QNewObjectDialog", "Height", 0));
        drawButton->setText(QString());
        valueGroupBox->setTitle(QApplication::translate("QNewObjectDialog", "Special values", 0));
        ySpeedLabel->setText(QApplication::translate("QNewObjectDialog", "Y speed", 0));
        xSpeedLabel->setText(QApplication::translate("QNewObjectDialog", "X speed", 0));
        value3Label->setText(QApplication::translate("QNewObjectDialog", "Value3", 0));
        value2Label->setText(QApplication::translate("QNewObjectDialog", "Value2", 0));
        valueLabel->setText(QApplication::translate("QNewObjectDialog", "Value", 0));
        soundBox->setTitle(QApplication::translate("QNewObjectDialog", "Sound effects", 0));
        soundLabel->setText(QApplication::translate("QNewObjectDialog", "Sound", 0));
        newSoundButton->setText(QApplication::translate("QNewObjectDialog", "...", 0));
        sound2Label->setText(QApplication::translate("QNewObjectDialog", "Sound2", 0));
        m_animBox->setTitle(QApplication::translate("QNewObjectDialog", "Animation frames", 0));
    } // retranslateUi

};

namespace Ui {
    class QNewObjectDialog: public Ui_QNewObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNEWOBJECTDIALOG_H
