/********************************************************************************
** Form generated from reading UI file 'QGameSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGAMESETTINGSDIALOG_H
#define UI_QGAMESETTINGSDIALOG_H

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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QGameSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QSpinBox *livesInitSpin;
    QLabel *label;
    QSpinBox *livesMaxSpin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *livesCombo;
    QPushButton *livesButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QSpinBox *keysInitSpin;
    QLabel *label_7;
    QSpinBox *keysMaxSpin;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *keysCombo;
    QPushButton *keysButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_9;
    QListWidget *editorLevelList;
    QVBoxLayout *verticalLayout_9;
    QPushButton *addLevelButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_18;
    QListWidget *gameLevelList;
    QVBoxLayout *verticalLayout_12;
    QPushButton *levelUpButton;
    QPushButton *levelDownButton;
    QPushButton *deleteLevelButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *idLabel;
    QLineEdit *sourceLine;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QSpinBox *windowWidthSpin;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_18;
    QSpinBox *windowHeightSpin;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_15;
    QComboBox *startCombo;
    QPushButton *startScreenButton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QComboBox *pauseCombo;
    QPushButton *pauseScreenButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QComboBox *gameOverCombo;
    QPushButton *gameOverScreenButton;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_16;
    QComboBox *endCombo;
    QPushButton *endScreenButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSpinBox *healthInitSpin;
    QLabel *label_3;
    QSpinBox *healthMaxSpin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *healthCombo;
    QPushButton *healthButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QSpinBox *scoreInitSpin;
    QLabel *label_5;
    QSpinBox *scoreMaxSpin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *scoreCombo;
    QPushButton *scoreButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QGameSettingsDialog)
    {
        if (QGameSettingsDialog->objectName().isEmpty())
            QGameSettingsDialog->setObjectName(QStringLiteral("QGameSettingsDialog"));
        QGameSettingsDialog->resize(504, 516);
        gridLayout = new QGridLayout(QGameSettingsDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(QGameSettingsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        livesInitSpin = new QSpinBox(groupBox);
        livesInitSpin->setObjectName(QStringLiteral("livesInitSpin"));
        livesInitSpin->setMaximum(9999);

        horizontalLayout->addWidget(livesInitSpin);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        livesMaxSpin = new QSpinBox(groupBox);
        livesMaxSpin->setObjectName(QStringLiteral("livesMaxSpin"));
        livesMaxSpin->setMinimum(1);
        livesMaxSpin->setMaximum(9999);

        horizontalLayout->addWidget(livesMaxSpin);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        livesCombo = new QComboBox(groupBox);
        livesCombo->setObjectName(QStringLiteral("livesCombo"));
        livesCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(livesCombo);

        livesButton = new QPushButton(groupBox);
        livesButton->setObjectName(QStringLiteral("livesButton"));
        livesButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(livesButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(QGameSettingsDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        keysInitSpin = new QSpinBox(groupBox_4);
        keysInitSpin->setObjectName(QStringLiteral("keysInitSpin"));
        keysInitSpin->setMaximum(9999);

        horizontalLayout_7->addWidget(keysInitSpin);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        keysMaxSpin = new QSpinBox(groupBox_4);
        keysMaxSpin->setObjectName(QStringLiteral("keysMaxSpin"));
        keysMaxSpin->setMinimum(1);
        keysMaxSpin->setMaximum(9999);

        horizontalLayout_7->addWidget(keysMaxSpin);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        keysCombo = new QComboBox(groupBox_4);
        keysCombo->setObjectName(QStringLiteral("keysCombo"));
        keysCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_8->addWidget(keysCombo);

        keysButton = new QPushButton(groupBox_4);
        keysButton->setObjectName(QStringLiteral("keysButton"));
        keysButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_8->addWidget(keysButton);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_5 = new QGroupBox(QGameSettingsDialog);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_10 = new QVBoxLayout(groupBox_5);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_10->addWidget(label_21);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        editorLevelList = new QListWidget(groupBox_5);
        editorLevelList->setObjectName(QStringLiteral("editorLevelList"));

        horizontalLayout_9->addWidget(editorLevelList);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        addLevelButton = new QPushButton(groupBox_5);
        addLevelButton->setObjectName(QStringLiteral("addLevelButton"));
        addLevelButton->setMaximumSize(QSize(28, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/add-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        addLevelButton->setIcon(icon);

        verticalLayout_9->addWidget(addLevelButton);


        horizontalLayout_9->addLayout(verticalLayout_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        verticalLayout_10->addLayout(horizontalLayout_9);

        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_10->addWidget(label_22);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        gameLevelList = new QListWidget(groupBox_5);
        gameLevelList->setObjectName(QStringLiteral("gameLevelList"));

        horizontalLayout_18->addWidget(gameLevelList);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        levelUpButton = new QPushButton(groupBox_5);
        levelUpButton->setObjectName(QStringLiteral("levelUpButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        levelUpButton->setIcon(icon1);

        verticalLayout_12->addWidget(levelUpButton);

        levelDownButton = new QPushButton(groupBox_5);
        levelDownButton->setObjectName(QStringLiteral("levelDownButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Common/assets/images/GUI_Icons/arrowDown.png"), QSize(), QIcon::Normal, QIcon::Off);
        levelDownButton->setIcon(icon2);

        verticalLayout_12->addWidget(levelDownButton);

        deleteLevelButton = new QPushButton(groupBox_5);
        deleteLevelButton->setObjectName(QStringLiteral("deleteLevelButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/QObjectsDock/assets/images/GUI_Icons/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteLevelButton->setIcon(icon3);

        verticalLayout_12->addWidget(deleteLevelButton);


        horizontalLayout_18->addLayout(verticalLayout_12);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_4);


        verticalLayout_10->addLayout(horizontalLayout_18);

        idLabel = new QLabel(groupBox_5);
        idLabel->setObjectName(QStringLiteral("idLabel"));

        verticalLayout_10->addWidget(idLabel);

        sourceLine = new QLineEdit(groupBox_5);
        sourceLine->setObjectName(QStringLiteral("sourceLine"));

        verticalLayout_10->addWidget(sourceLine);


        gridLayout->addWidget(groupBox_5, 2, 1, 2, 1);

        groupBox_7 = new QGroupBox(QGameSettingsDialog);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout_8 = new QVBoxLayout(groupBox_7);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(31, 0));

        horizontalLayout_14->addWidget(label_17);

        windowWidthSpin = new QSpinBox(groupBox_7);
        windowWidthSpin->setObjectName(QStringLiteral("windowWidthSpin"));
        windowWidthSpin->setMaximum(9999);

        horizontalLayout_14->addWidget(windowWidthSpin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_8->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(31, 0));

        horizontalLayout_15->addWidget(label_18);

        windowHeightSpin = new QSpinBox(groupBox_7);
        windowHeightSpin->setObjectName(QStringLiteral("windowHeightSpin"));
        windowHeightSpin->setMaximum(9999);

        horizontalLayout_15->addWidget(windowHeightSpin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_15);


        gridLayout->addWidget(groupBox_7, 3, 0, 1, 1);

        groupBox_6 = new QGroupBox(QGameSettingsDialog);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_7 = new QVBoxLayout(groupBox_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(51, 0));

        horizontalLayout_12->addWidget(label_15);

        startCombo = new QComboBox(groupBox_6);
        startCombo->setObjectName(QStringLiteral("startCombo"));
        startCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_12->addWidget(startCombo);

        startScreenButton = new QPushButton(groupBox_6);
        startScreenButton->setObjectName(QStringLiteral("startScreenButton"));
        startScreenButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_12->addWidget(startScreenButton);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(51, 0));

        horizontalLayout_10->addWidget(label_13);

        pauseCombo = new QComboBox(groupBox_6);
        pauseCombo->setObjectName(QStringLiteral("pauseCombo"));
        pauseCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_10->addWidget(pauseCombo);

        pauseScreenButton = new QPushButton(groupBox_6);
        pauseScreenButton->setObjectName(QStringLiteral("pauseScreenButton"));
        pauseScreenButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_10->addWidget(pauseScreenButton);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(51, 0));

        horizontalLayout_11->addWidget(label_14);

        gameOverCombo = new QComboBox(groupBox_6);
        gameOverCombo->setObjectName(QStringLiteral("gameOverCombo"));
        gameOverCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_11->addWidget(gameOverCombo);

        gameOverScreenButton = new QPushButton(groupBox_6);
        gameOverScreenButton->setObjectName(QStringLiteral("gameOverScreenButton"));
        gameOverScreenButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_11->addWidget(gameOverScreenButton);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(51, 0));

        horizontalLayout_13->addWidget(label_16);

        endCombo = new QComboBox(groupBox_6);
        endCombo->setObjectName(QStringLiteral("endCombo"));
        endCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_13->addWidget(endCombo);

        endScreenButton = new QPushButton(groupBox_6);
        endScreenButton->setObjectName(QStringLiteral("endScreenButton"));
        endScreenButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_13->addWidget(endScreenButton);


        verticalLayout_7->addLayout(horizontalLayout_13);


        gridLayout->addWidget(groupBox_6, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(QGameSettingsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        healthInitSpin = new QSpinBox(groupBox_2);
        healthInitSpin->setObjectName(QStringLiteral("healthInitSpin"));
        healthInitSpin->setMaximum(9999);

        horizontalLayout_3->addWidget(healthInitSpin);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        healthMaxSpin = new QSpinBox(groupBox_2);
        healthMaxSpin->setObjectName(QStringLiteral("healthMaxSpin"));
        healthMaxSpin->setMinimum(1);
        healthMaxSpin->setMaximum(10);

        horizontalLayout_3->addWidget(healthMaxSpin);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        healthCombo = new QComboBox(groupBox_2);
        healthCombo->setObjectName(QStringLiteral("healthCombo"));
        healthCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(healthCombo);

        healthButton = new QPushButton(groupBox_2);
        healthButton->setObjectName(QStringLiteral("healthButton"));
        healthButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_4->addWidget(healthButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(QGameSettingsDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        scoreInitSpin = new QSpinBox(groupBox_3);
        scoreInitSpin->setObjectName(QStringLiteral("scoreInitSpin"));
        scoreInitSpin->setMaximum(9999);

        horizontalLayout_5->addWidget(scoreInitSpin);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        scoreMaxSpin = new QSpinBox(groupBox_3);
        scoreMaxSpin->setObjectName(QStringLiteral("scoreMaxSpin"));
        scoreMaxSpin->setMinimum(1);
        scoreMaxSpin->setMaximum(9999);

        horizontalLayout_5->addWidget(scoreMaxSpin);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        scoreCombo = new QComboBox(groupBox_3);
        scoreCombo->setObjectName(QStringLiteral("scoreCombo"));
        scoreCombo->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(scoreCombo);

        scoreButton = new QPushButton(groupBox_3);
        scoreButton->setObjectName(QStringLiteral("scoreButton"));
        scoreButton->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_6->addWidget(scoreButton);


        verticalLayout_4->addLayout(horizontalLayout_6);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QGameSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 1, 1, 1);

        QWidget::setTabOrder(healthInitSpin, healthMaxSpin);
        QWidget::setTabOrder(healthMaxSpin, healthCombo);
        QWidget::setTabOrder(healthCombo, healthButton);
        QWidget::setTabOrder(healthButton, livesInitSpin);
        QWidget::setTabOrder(livesInitSpin, livesMaxSpin);
        QWidget::setTabOrder(livesMaxSpin, livesCombo);
        QWidget::setTabOrder(livesCombo, livesButton);
        QWidget::setTabOrder(livesButton, scoreInitSpin);
        QWidget::setTabOrder(scoreInitSpin, scoreMaxSpin);
        QWidget::setTabOrder(scoreMaxSpin, scoreCombo);
        QWidget::setTabOrder(scoreCombo, scoreButton);
        QWidget::setTabOrder(scoreButton, keysInitSpin);
        QWidget::setTabOrder(keysInitSpin, keysMaxSpin);
        QWidget::setTabOrder(keysMaxSpin, keysCombo);
        QWidget::setTabOrder(keysCombo, keysButton);
        QWidget::setTabOrder(keysButton, startCombo);
        QWidget::setTabOrder(startCombo, startScreenButton);
        QWidget::setTabOrder(startScreenButton, pauseCombo);
        QWidget::setTabOrder(pauseCombo, pauseScreenButton);
        QWidget::setTabOrder(pauseScreenButton, gameOverCombo);
        QWidget::setTabOrder(gameOverCombo, gameOverScreenButton);
        QWidget::setTabOrder(gameOverScreenButton, endCombo);
        QWidget::setTabOrder(endCombo, endScreenButton);
        QWidget::setTabOrder(endScreenButton, windowWidthSpin);
        QWidget::setTabOrder(windowWidthSpin, windowHeightSpin);
        QWidget::setTabOrder(windowHeightSpin, gameLevelList);
        QWidget::setTabOrder(gameLevelList, levelUpButton);
        QWidget::setTabOrder(levelUpButton, levelDownButton);
        QWidget::setTabOrder(levelDownButton, sourceLine);

        retranslateUi(QGameSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QGameSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QGameSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QGameSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *QGameSettingsDialog)
    {
        QGameSettingsDialog->setWindowTitle(QApplication::translate("QGameSettingsDialog", "Game Settings Manager", 0));
        groupBox->setTitle(QApplication::translate("QGameSettingsDialog", "Lives", 0));
        label_9->setText(QApplication::translate("QGameSettingsDialog", "Init value:", 0));
        label->setText(QApplication::translate("QGameSettingsDialog", "Max value:", 0));
        label_2->setText(QApplication::translate("QGameSettingsDialog", "Icon:", 0));
        livesButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        groupBox_4->setTitle(QApplication::translate("QGameSettingsDialog", "Keys", 0));
        label_12->setText(QApplication::translate("QGameSettingsDialog", "Init value:", 0));
        label_7->setText(QApplication::translate("QGameSettingsDialog", "Max value:", 0));
        label_8->setText(QApplication::translate("QGameSettingsDialog", "Icon:", 0));
        keysButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        groupBox_5->setTitle(QApplication::translate("QGameSettingsDialog", "Levels", 0));
        label_21->setText(QApplication::translate("QGameSettingsDialog", "Editor", 0));
        addLevelButton->setText(QString());
        label_22->setText(QApplication::translate("QGameSettingsDialog", "Game", 0));
        levelUpButton->setText(QString());
        levelDownButton->setText(QString());
        deleteLevelButton->setText(QString());
        idLabel->setText(QApplication::translate("QGameSettingsDialog", "<No item selected>", 0));
        groupBox_7->setTitle(QApplication::translate("QGameSettingsDialog", "Game window", 0));
        label_17->setText(QApplication::translate("QGameSettingsDialog", "Width", 0));
        label_18->setText(QApplication::translate("QGameSettingsDialog", "Height", 0));
        groupBox_6->setTitle(QApplication::translate("QGameSettingsDialog", "Screens", 0));
        label_15->setText(QApplication::translate("QGameSettingsDialog", "Start", 0));
        startScreenButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        label_13->setText(QApplication::translate("QGameSettingsDialog", "Pause", 0));
        pauseScreenButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        label_14->setText(QApplication::translate("QGameSettingsDialog", "GameOver", 0));
        gameOverScreenButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        label_16->setText(QApplication::translate("QGameSettingsDialog", "End", 0));
        endScreenButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        groupBox_2->setTitle(QApplication::translate("QGameSettingsDialog", "Health", 0));
        label_10->setText(QApplication::translate("QGameSettingsDialog", "Init value:", 0));
        label_3->setText(QApplication::translate("QGameSettingsDialog", "Max value:", 0));
        label_4->setText(QApplication::translate("QGameSettingsDialog", "Icon:", 0));
        healthButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
        groupBox_3->setTitle(QApplication::translate("QGameSettingsDialog", "Score", 0));
        label_11->setText(QApplication::translate("QGameSettingsDialog", "Init value:", 0));
        label_5->setText(QApplication::translate("QGameSettingsDialog", "Max value:", 0));
        label_6->setText(QApplication::translate("QGameSettingsDialog", "Icon:", 0));
        scoreButton->setText(QApplication::translate("QGameSettingsDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class QGameSettingsDialog: public Ui_QGameSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGAMESETTINGSDIALOG_H
