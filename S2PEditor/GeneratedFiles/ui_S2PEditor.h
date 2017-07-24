/********************************************************************************
** Form generated from reading UI file 'S2PEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S2PEDITOR_H
#define UI_S2PEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S2PEditorClass
{
public:
    QAction *actionOpen;
    QAction *actionRun;
    QAction *actionStop;
    QAction *actionExit;
    QAction *actionAddLevel;
    QAction *actionSaveAs;
    QAction *actionTextures;
    QAction *actionSelectObject;
    QAction *actionSelectTile;
    QAction *actionBackgrounds;
    QAction *actionGameSettings;
    QAction *actionSaveProject;
    QAction *actionNewProject;
    QAction *actionExportProject;
    QAction *actionCreateGame;
    QAction *actionAbout;
    QAction *actionSounds;
    QAction *actionMusic;
    QAction *actionAboutS2PEditor;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_Project;
    QMenu *menu_Level;
    QMenu *menu_Game;
    QMenu *menu_Insert;
    QMenu *menu_Help;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *S2PEditorClass)
    {
        if (S2PEditorClass->objectName().isEmpty())
            S2PEditorClass->setObjectName(QStringLiteral("S2PEditorClass"));
        S2PEditorClass->resize(781, 694);
        actionOpen = new QAction(S2PEditorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/folder-7.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionRun = new QAction(S2PEditorClass);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/play-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon1);
        actionStop = new QAction(S2PEditorClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon2);
        actionExit = new QAction(S2PEditorClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAddLevel = new QAction(S2PEditorClass);
        actionAddLevel->setObjectName(QStringLiteral("actionAddLevel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddLevel->setIcon(icon3);
        actionSaveAs = new QAction(S2PEditorClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon4);
        actionTextures = new QAction(S2PEditorClass);
        actionTextures->setObjectName(QStringLiteral("actionTextures"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/editTextures.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTextures->setIcon(icon5);
        actionSelectObject = new QAction(S2PEditorClass);
        actionSelectObject->setObjectName(QStringLiteral("actionSelectObject"));
        actionSelectObject->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/selectObject.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectObject->setIcon(icon6);
        actionSelectTile = new QAction(S2PEditorClass);
        actionSelectTile->setObjectName(QStringLiteral("actionSelectTile"));
        actionSelectTile->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/selectTile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectTile->setIcon(icon7);
        actionBackgrounds = new QAction(S2PEditorClass);
        actionBackgrounds->setObjectName(QStringLiteral("actionBackgrounds"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/editBackground.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackgrounds->setIcon(icon8);
        actionGameSettings = new QAction(S2PEditorClass);
        actionGameSettings->setObjectName(QStringLiteral("actionGameSettings"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/settings-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGameSettings->setIcon(icon9);
        actionSaveProject = new QAction(S2PEditorClass);
        actionSaveProject->setObjectName(QStringLiteral("actionSaveProject"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveProject->setIcon(icon10);
        actionNewProject = new QAction(S2PEditorClass);
        actionNewProject->setObjectName(QStringLiteral("actionNewProject"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewProject->setIcon(icon11);
        actionExportProject = new QAction(S2PEditorClass);
        actionExportProject->setObjectName(QStringLiteral("actionExportProject"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/folder-13.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportProject->setIcon(icon12);
        actionCreateGame = new QAction(S2PEditorClass);
        actionCreateGame->setObjectName(QStringLiteral("actionCreateGame"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/game-controller-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreateGame->setIcon(icon13);
        actionAbout = new QAction(S2PEditorClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionSounds = new QAction(S2PEditorClass);
        actionSounds->setObjectName(QStringLiteral("actionSounds"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/music-player-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSounds->setIcon(icon14);
        actionMusic = new QAction(S2PEditorClass);
        actionMusic->setObjectName(QStringLiteral("actionMusic"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/S2PEditor/assets/images/GUI_Icons/music-player.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMusic->setIcon(icon15);
        actionAboutS2PEditor = new QAction(S2PEditorClass);
        actionAboutS2PEditor->setObjectName(QStringLiteral("actionAboutS2PEditor"));
        centralWidget = new QWidget(S2PEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        S2PEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(S2PEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 21));
        menu_Project = new QMenu(menuBar);
        menu_Project->setObjectName(QStringLiteral("menu_Project"));
        menu_Level = new QMenu(menuBar);
        menu_Level->setObjectName(QStringLiteral("menu_Level"));
        menu_Game = new QMenu(menuBar);
        menu_Game->setObjectName(QStringLiteral("menu_Game"));
        menu_Insert = new QMenu(menuBar);
        menu_Insert->setObjectName(QStringLiteral("menu_Insert"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        S2PEditorClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(S2PEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        S2PEditorClass->setStatusBar(statusBar);
        toolBar = new QToolBar(S2PEditorClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        S2PEditorClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_Project->menuAction());
        menuBar->addAction(menu_Level->menuAction());
        menuBar->addAction(menu_Game->menuAction());
        menuBar->addAction(menu_Insert->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Project->addAction(actionNewProject);
        menu_Project->addAction(actionOpen);
        menu_Project->addAction(actionSaveProject);
        menu_Project->addAction(actionExportProject);
        menu_Project->addSeparator();
        menu_Project->addAction(actionTextures);
        menu_Project->addAction(actionSounds);
        menu_Project->addSeparator();
        menu_Project->addAction(actionExit);
        menu_Level->addAction(actionAddLevel);
        menu_Level->addAction(actionSaveAs);
        menu_Level->addSeparator();
        menu_Level->addAction(actionRun);
        menu_Level->addAction(actionStop);
        menu_Level->addSeparator();
        menu_Level->addAction(actionBackgrounds);
        menu_Level->addAction(actionMusic);
        menu_Game->addAction(actionGameSettings);
        menu_Game->addAction(actionCreateGame);
        menu_Insert->addAction(actionSelectTile);
        menu_Insert->addAction(actionSelectObject);
        menu_Help->addAction(actionAboutS2PEditor);
        toolBar->addAction(actionNewProject);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSaveProject);
        toolBar->addAction(actionExportProject);
        toolBar->addSeparator();
        toolBar->addAction(actionTextures);
        toolBar->addAction(actionSounds);
        toolBar->addAction(actionBackgrounds);
        toolBar->addSeparator();
        toolBar->addAction(actionAddLevel);
        toolBar->addAction(actionSaveAs);
        toolBar->addAction(actionRun);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();
        toolBar->addAction(actionGameSettings);
        toolBar->addAction(actionCreateGame);
        toolBar->addSeparator();
        toolBar->addAction(actionSelectTile);
        toolBar->addAction(actionSelectObject);

        retranslateUi(S2PEditorClass);

        QMetaObject::connectSlotsByName(S2PEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *S2PEditorClass)
    {
        S2PEditorClass->setWindowTitle(QApplication::translate("S2PEditorClass", "S2PEditor", 0));
        actionOpen->setText(QApplication::translate("S2PEditorClass", "Open", 0));
        actionOpen->setShortcut(QString());
        actionRun->setText(QApplication::translate("S2PEditorClass", "Run", 0));
        actionRun->setShortcut(QApplication::translate("S2PEditorClass", "F5", 0));
        actionStop->setText(QApplication::translate("S2PEditorClass", "Stop", 0));
        actionStop->setShortcut(QString());
        actionExit->setText(QApplication::translate("S2PEditorClass", "Exit", 0));
        actionAddLevel->setText(QApplication::translate("S2PEditorClass", "New", 0));
        actionSaveAs->setText(QApplication::translate("S2PEditorClass", "Save as...", 0));
        actionTextures->setText(QApplication::translate("S2PEditorClass", "Textures", 0));
        actionSelectObject->setText(QApplication::translate("S2PEditorClass", "Object", 0));
        actionSelectTile->setText(QApplication::translate("S2PEditorClass", "Tile", 0));
        actionBackgrounds->setText(QApplication::translate("S2PEditorClass", "Backgrounds", 0));
        actionGameSettings->setText(QApplication::translate("S2PEditorClass", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        actionGameSettings->setToolTip(QApplication::translate("S2PEditorClass", "Game settings", 0));
#endif // QT_NO_TOOLTIP
        actionSaveProject->setText(QApplication::translate("S2PEditorClass", "Save", 0));
        actionNewProject->setText(QApplication::translate("S2PEditorClass", "New", 0));
        actionExportProject->setText(QApplication::translate("S2PEditorClass", "Export", 0));
        actionCreateGame->setText(QApplication::translate("S2PEditorClass", "Export", 0));
#ifndef QT_NO_TOOLTIP
        actionCreateGame->setToolTip(QApplication::translate("S2PEditorClass", "Create game", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("S2PEditorClass", "About S2PEditor", 0));
        actionSounds->setText(QApplication::translate("S2PEditorClass", "Sounds", 0));
        actionMusic->setText(QApplication::translate("S2PEditorClass", "Music", 0));
        actionAboutS2PEditor->setText(QApplication::translate("S2PEditorClass", "About S2PEditor", 0));
        menu_Project->setTitle(QApplication::translate("S2PEditorClass", "&Project", 0));
        menu_Level->setTitle(QApplication::translate("S2PEditorClass", "&Level", 0));
        menu_Game->setTitle(QApplication::translate("S2PEditorClass", "&Game", 0));
        menu_Insert->setTitle(QApplication::translate("S2PEditorClass", "&Insert", 0));
        menu_Help->setTitle(QApplication::translate("S2PEditorClass", "&Help", 0));
        toolBar->setWindowTitle(QApplication::translate("S2PEditorClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class S2PEditorClass: public Ui_S2PEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S2PEDITOR_H
