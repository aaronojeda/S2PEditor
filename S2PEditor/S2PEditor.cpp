#include "S2PEditor.h"
#include <fstream>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QInputDialog>
#include <QCloseEvent>
#include <QTextCodec>
#include "EditorController.h"
#include "QSDLCanvas.h"
#include "QTilesetsDock.h"
#include "QObjectsDock.h"
#include "QNewTilesetDialog.h"
#include "QNewLevelDialog.h"
#include "QCanvasScrollArea.h"
#include "EditorParser.h"
#include "QTexturesDialog.h"
#include "QBckDialog.h"
#include "QGameSettingsDialog.h"
#include "QLevelsDock.h"
#include "QNewProjectDialog.h"
#include "Camera.h"
#include "QSoundsDialog.h"

// Supongo que es cosa de QMainWindow y del Designer que añadirá algunos widgets por defecto.

using namespace std;

S2PEditor::S2PEditor(QWidget *parent) :
QMainWindow(parent),
m_SDLCanvas{ nullptr },
m_canvasArea{ nullptr },
m_appName{ "S2PEditor" },
m_lastEdited{ "projects/lastEdited.cfg" }
{
	ui.setupUi(this);
	if (initEditor())
	{
		bool errorLoading = false;
		// Load project if file exists. If not, project has just been created
		if (QFile().exists(m_projectSource))
		{
			if (!TheEditor::Instance().loadProject(m_projectSource.toStdString()))
			{
				QMessageBox::critical(this, "S2PEditor",
					"Couldn't load last project file:\n" +
					m_projectSource);
				errorLoading = true;
			}
		}
		// If current level was just created, add it to the project (if it loaded correctly)
		if (!TheEditor::Instance().levelExists(m_levelName.toStdString()) && !errorLoading)
		{
			TheEditor::Instance().addLevel(m_levelName.toStdString(), m_levelSource.toStdString());
		}
		// Disable stop action
		ui.actionStop->setDisabled(true);
		// Init docked windows
		initObjectsDock();
		initTilesetsDock();
		initLevelsDock();
		// Set application title
		updateWindowTitle();
		// Save loaded project
		saveProject();
	}
}

S2PEditor::~S2PEditor()
{
	// QSDLCanvas class is QObject, so no need for deletion of m_SDLCanvas(Qt manages it).
}

bool S2PEditor::initEditor()
{
	// init central widget
	m_canvasArea = new QCanvasScrollArea(this);
	m_canvasArea->setWidgetResizable(true);
	setCentralWidget(m_canvasArea);

	// get last edited project
	EditorParser parser;
	string lastProject;
	parser.parseLastProject(m_lastEdited, lastProject);

	// Check if project file exists
	if (QFile().exists(lastProject.c_str()))
	{
		// THERE IS A LAST EDITED PROJECT
		m_projectSource = lastProject.c_str();
		string fileName = lastProject.substr(lastProject.find_last_of("/\\") + 1);
		m_projectName = fileName.substr(0, fileName.find_last_of(".")).c_str();

		// get last edited level
		string lastLevel;
		parser.parseLastLevel(m_lastEdited, lastLevel);
		// Check if level file exists
		if (QFile().exists(lastLevel.c_str()))
		{
			// THERE IS A LAST EDITED LEVEL. Get its file path
			m_levelSource = lastLevel.c_str();
			string fileName = lastLevel.substr(lastLevel.find_last_of("/\\") + 1);
			m_levelName = fileName.substr(0, fileName.find_last_of(".")).c_str();
		}
		else
		{
			// COULD NOT PARSE LAST EDITED LEVEL. TRY TO LOAD THE FIRST LEVEL OF THE PROJECT
			vector<pair<string, string>> projectLevels;
			parser.parseEditorLevels(m_projectSource.toStdString(), projectLevels);
			if (projectLevels.size())
			{
				// THERE ARE LEVELS IN THE PROJECT. Take the first one
				m_levelSource = projectLevels.front().second.c_str();
			}
		}
		// INIT CANVAS WITH LASTEDITED LEVEL, FIRST LEVEL OF THE PROJECT OR NONE
		return initCanvas();
	}
	else
	{
		// COULD NOT PARSE LAST EDITED PROJECT. ASK FOR A NEW ONE
		QMessageBox::information(this, "S2PEditor",
			"Welcome! There is no last edited project so maybe this is your\n"
			"first time with S2PEditor. Now you will be asked for some\n"
			"project settings so you can start creating platformers. Enjoy!");

		// Ask for project name and first level attributes
		QNewProjectDialog d;
		// Disable cancel dialog options
		d.setWindowFlags(Qt::WindowTitleHint);
		d.buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
		if (d.exec())
		{
			QString projectName, levelName;
			int lWidth, lHeight, tileSize;
			d.getValues(projectName, levelName, lWidth, lHeight, tileSize);

			// Update current project and level names
			m_projectName = projectName;
			m_projectSource = "projects/" + m_projectName + "/" + m_projectName + ".s2pe";
			m_levelName = levelName;
			m_levelSource = "projects/" + m_projectName + "/levels/" + m_levelName + ".xml";
			
			// Initialize canvas and set it as central scrollarea widget
			m_SDLCanvas = new QSDLCanvas(this);
			m_canvasArea->setWidget(m_SDLCanvas);
			// Create SDLCanvas with the given values
			m_SDLCanvas->setSizeHint(QSize(lWidth*tileSize, lHeight*tileSize));
			// Return success if initEditor succeed
			return m_SDLCanvas->initEditor(m_levelSource.toStdString(), lWidth, lHeight, tileSize);
		}
	}
	// The program should never reach this point as dialog cancel options are disabled
	return false;
}

bool S2PEditor::initCanvas()
{
	// Initialize canvas and set it as central scrollarea widget
	m_SDLCanvas = new QSDLCanvas(this);
	m_canvasArea->setWidget(m_SDLCanvas);

	// Check if there is a previously edited level
	if (!m_levelSource.isEmpty())
	{
		// Create SDL canvas with the size of the last edited level
		int width = 0;
		int height = 0;
		int tileSize = 0;
		EditorParser parser;
		if (!parser.parseLevelSize(m_levelSource.toStdString(), width, height, tileSize))
		{
			m_SDLCanvas->setSizeHint(QSize(width*tileSize, height*tileSize));
			// Return success if initEditor succeed
			return m_SDLCanvas->initEditor(m_levelSource.toStdString());
		}
	}

	// Unable to load last edited level. Show dialog to create new level
	QMessageBox::information(this, "S2PEditor",
		"Could not load last edited level of project '" +
		m_projectName + "'.\nCreating new level.");

	QNewLevelDialog d;
	// Disable cancel dialog options
	d.disableCancelButton();
	d.setWindowFlags(Qt::WindowTitleHint);
	int levelWidth, levelHeight, tileSize;
	if (d.exec())
	{
		// Get level attributes
		d.getValues(m_levelName, levelWidth, levelHeight, tileSize);
		m_levelSource = "projects/" + m_projectName + "/levels/" + m_levelName + ".xml";
	}
	// Create SDLCanvas with the given values
	m_SDLCanvas->setSizeHint(QSize(levelWidth*tileSize, levelHeight*tileSize));
	// Return success if initEditor succeed
	return m_SDLCanvas->initEditor(m_levelSource.toStdString(), levelWidth, levelHeight, tileSize);
}

void S2PEditor::initObjectsDock()
{
	// Initialize game objects window dock
	m_objectsDock = new QObjectsDock(this);
	addDockWidget(Qt::RightDockWidgetArea, m_objectsDock);
	// Load project objects
	m_objectsDock->update();
}

void S2PEditor::initTilesetsDock()
{
	// Initialize tileset window dock
	m_tilesetsDock = new QTilesetsDock(this);
	addDockWidget(Qt::RightDockWidgetArea, m_tilesetsDock);
	// Connect signals & slots
	connect(m_tilesetsDock, SIGNAL(tilesetClosed(int)), this, SLOT(removeTileset(int)));
	// Load project tilesets
	m_tilesetsDock->update();
}

void S2PEditor::initLevelsDock()
{
	// Initialize project levels window dock
	m_levelsDock = new QLevelsDock(this);
	addDockWidget(Qt::RightDockWidgetArea, m_levelsDock);
	// Tab with objects dock to save space
	tabifyDockWidget(m_levelsDock, m_tilesetsDock);
	// Connect signals & slots
	connect(m_levelsDock, &QLevelsDock::loadLevel, this, &S2PEditor::loadLevel);
	connect(m_levelsDock, &QLevelsDock::saveAndLoad, this, &S2PEditor::saveAndLoadLevel);
	connect(m_levelsDock, &QLevelsDock::deleteLevel, this, &S2PEditor::deleteLevel);
	// Load project levels
	m_levelsDock->update();
}

void S2PEditor::on_actionAddLevel_triggered()
{
	QNewLevelDialog d(this); 

	if (d.exec())
	{
		// Get level attributes from dialog
		int levelWidth, levelHeight, tileSize;
		QString levelName;
		d.getValues(levelName, levelWidth, levelHeight, tileSize);
		// Check if there is already a level with that name
		if (!TheEditor::Instance().levelExists(levelName.toStdString()))
		{
			// Save current (soon previous) level
			TheEditor::Instance().saveLevel(m_levelSource.toStdString());
			// Add extension to level name
			auto newLevelSrc = "projects/" + m_projectName + "/levels/" +  levelName + ".xml";
			// Tell Editor to create new level with given size and name
			if (TheEditor::Instance().newLevel(levelName.toStdString(), newLevelSrc.toStdString(), levelWidth, levelHeight, tileSize))
			{
				// Update current level
				m_levelName = levelName;
				m_levelSource = newLevelSrc;
				// Add new level to levels dock
				m_levelsDock->addLevel(levelName, m_levelSource);
				// Tells SDL canvas the size of the new level
				m_SDLCanvas->setSizeHint(QSize(levelWidth*tileSize, levelHeight*tileSize));
				m_SDLCanvas->resize(m_SDLCanvas->sizeHint());
				m_canvasArea->canvasResized();
				// Change window title to have feedback about what level are we editing
				updateWindowTitle();
				// Set default object
				TheEditor::Instance().setObject(m_objectsDock->currentObject().toStdString());
				// Set collidable
				TheEditor::Instance().setCollisionTiles(m_tilesetsDock->collidable());
				// Save project changes
				saveProject();
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Couldn't create new level\n");
			}
		}
		else
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a level called '" + levelName + "' in the project.");
		}
	}
}

void S2PEditor::on_actionNewProject_triggered()
{
	// Ask if user want to save current project
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Question);
	msgBox.setText("Do you want to save the current project?");
	// Set message box buttons. Default to 'No'
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	if (msgBox.exec() == QMessageBox::Yes)
	{
		// The user wants to save
		saveProject();
	}

	// Ask for project name and first level attributes
	QNewProjectDialog d;
	if (d.exec())
	{
		QString projectName, levelName;
		int lWidth, lHeight, tileSize;
		d.getValues(projectName, levelName, lWidth, lHeight, tileSize);
		bool bNewProject = true;
		// Check if a project with that name already exists
		if (QDir().exists("projects/" + projectName))
		{
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setText("A project called " + projectName + " already exists.\n"
				"Do you want to overwrite it?");
			if (msgBox.exec() == QMessageBox::Yes)
			{
				// Remove previous project content
				QDir previousDir("projects/" + projectName);
				previousDir.removeRecursively();
			}
			else
			{
				bNewProject = false;
			}
		}
		if (bNewProject)
		{
			// Clear previous project
			TheEditor::Instance().clear();
			// Update (clear) objects, tilesets and levels
			m_objectsDock->update();
			m_tilesetsDock->update();
			m_levelsDock->update();
			// Reset insertion mode to none
			ui.actionSelectObject->setChecked(false);;
			ui.actionSelectTile->setChecked(false);
			TheEditor::Instance().selectObject(false);
			TheEditor::Instance().selectTile(false);

			// Update current project and level names
			m_projectName = projectName;
			m_projectSource = "projects/" + m_projectName + "/" + m_projectName + ".s2pe";
			m_levelName = levelName;
			m_levelSource = "projects/" + m_projectName + "/levels/" + m_levelName + ".xml";

			// Create new project's first level
			if (TheEditor::Instance().newLevel(levelName.toStdString(), m_levelSource.toStdString(), lWidth, lHeight, tileSize))
			{
				m_levelsDock->addLevel(levelName, m_levelSource);
				// Tells SDL canvas the size of the new level
				m_SDLCanvas->setSizeHint(QSize(lWidth*tileSize, lHeight*tileSize));
				m_SDLCanvas->resize(m_SDLCanvas->sizeHint());
				m_canvasArea->canvasResized();
				// Change window title to have feedback about what level are we editing
				updateWindowTitle();
				// Set default object
				TheEditor::Instance().setObject(m_objectsDock->currentObject().toStdString());
				// save new project
				saveProject();
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Couldn't create new level\n");
			}
		}
	}
}

void S2PEditor::on_actionOpen_triggered()
{
	QString projectFile = QFileDialog::getOpenFileName(this, "Load project", QString(),
		"Level files (*.s2pe)");
	// Make projectFile path local
	projectFile = projectFile.section("/", -3);
	loadProject(projectFile);
}

void S2PEditor::loadProject(QString projectFile)
{
	if (!projectFile.isEmpty())
	{
		// ask for saving if the loaded project is a new one
		if (projectFile != m_projectSource)
		{
			// Ask if user want to save current project
			QMessageBox msgBox;
			msgBox.setIcon(QMessageBox::Question);
			msgBox.setText("Do you want to save the current project?");
			// Set message box buttons. Default to 'No'
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::Yes);
			if (msgBox.exec() == QMessageBox::Yes)
			{
				// The user wants to save
				saveProject();
			}
		}

		bool successLoading = true;
		// Load new project
		if (TheEditor::Instance().loadProject(projectFile.toStdString()))
		{
			auto curLevel = TheEditor::Instance().getLevels().front();
			// Load first level of the project
			if (loadLevel(curLevel.first.c_str(), curLevel.second.c_str()))
			{
				// Update docks
				m_tilesetsDock->update();
				m_objectsDock->update();
				m_levelsDock->update();
				// Reset insertion mode to none
				ui.actionSelectObject->setChecked(false);;
				ui.actionSelectTile->setChecked(false);
				TheEditor::Instance().selectObject(false);
				TheEditor::Instance().selectTile(false);
				// Update current project and level
				m_projectName = projectFile.section("/", -1).section(".", 0, 0);
				m_projectSource = projectFile;
				m_levelName = curLevel.first.c_str();
				m_levelSource = curLevel.second.c_str();
				// Save project changes and update window title
				saveProject();
				updateWindowTitle();
			}
			else
			{
				successLoading = false;
			}
		}
		else
		{
			successLoading = false;
		}
		// Check if there have been problems opening project's or first level's file
		if (!successLoading)
		{
			QMessageBox::critical(this, "S2PEditor",
				"Could not open project '" +
				projectFile.section("/", -1).section(".", 0, 0) + "'." +
				" Opening previous project.");
			// Load previous project
			loadProject(m_projectSource);
		}
	}
}


void S2PEditor::on_actionSaveAs_triggered()
{
	bool ok;
	// Ask for copied level name (original_Copy default)
	QString levelName = QInputDialog::getText(this, "Save as", "Level name", 
		QLineEdit::Normal, m_levelName + "_Copy", &ok);
	if (ok)
	{
		// Check if there is already a level with that name
		if (!TheEditor::Instance().levelExists(levelName.toStdString()))
		{
			// Save original level
			TheEditor::Instance().saveLevel(m_levelSource.toStdString());
			// Copy the level file
			QString levelsPath = m_levelSource.section("/", 0, -2) + "/";
			QString levelFile = levelsPath + levelName + ".xml";
			QFile::copy(m_levelSource, levelFile); 
			// Add level to editor, levels dock
			TheEditor::Instance().addLevel(levelName.toStdString(), levelFile.toStdString());
			m_levelsDock->addLevel(levelName, levelFile);
			// Make 'new' level current
			m_levelName = levelName;
			m_levelSource = levelFile;
			// Save project changes (and 'new' level) and load copy level
			saveProject();
			TheEditor::Instance().loadLevel(levelFile.toStdString());
			// Update window title
			updateWindowTitle();
		}
		else
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a level called '" + levelName + "'.");
		}
	}
}

void S2PEditor::on_actionSaveProject_triggered()
{
	saveProject();
}

void S2PEditor::on_actionRun_triggered()
{
	// Disable resize in test mode
	setFixedSize(size());
	// Disable editor mode actions
	disableActions();
	// Test the level being edited
	TheEditor::Instance().runLevel(m_levelSource.toStdString());
	// Now we're testing the level, so we activate stop action
	ui.actionStop->setDisabled(false);
}

void S2PEditor::on_actionStop_triggered()
{
	TheEditor::Instance().stopLevel();
	// Enable editor mode actions
	enableActions();
	// Disable stop action, as we are no longer testing the level
	ui.actionStop->setDisabled(true);
}

void S2PEditor::on_actionExit_triggered()
{
	close();
}

void S2PEditor::updateLastEdited()
{
	// Update 'last edited' file
	EditorParser parser;
	if (parser.writeLastEdited(m_lastEdited, m_projectSource.toStdString(), m_levelSource.toStdString())
		!= tinyxml2::XML_SUCCESS)
	{
		QMessageBox::warning(this, "S2PEditor",
			"Couldn't update last edited file.\n");
	}
}

void S2PEditor::on_actionTextures_triggered()
{
	QTexturesDialog d(TheEditor::Instance().getTextures(), this);
	if (d.exec())
	{
		// Get updated textures from textures dialog list
		map<string, string> updatedTextures;
		for (int i = 0; i < d.textureList->count(); i++)
		{
			QListWidgetItem* curItem = d.textureList->item(i);
			updatedTextures[curItem->text().toStdString()] = curItem->data(Qt::UserRole).toString().toStdString();
		}
		// Update the textures in the editor
		TheEditor::Instance().updateTextures(updatedTextures);
	}
}

void S2PEditor::on_actionSounds_triggered()
{
	QSoundsDialog d(TheEditor::Instance().getSfxs(), TheEditor::Instance().getMusic(), this);
	if (d.exec())
	{
		// Get updated sounds from dialog sound list
		map<string, string> updatedSfxs;
		for (int i = 0; i < d.soundList->count(); i++)
		{
			QListWidgetItem *curItem = d.soundList->item(i);
			updatedSfxs[curItem->text().toStdString()] = curItem->data(Qt::UserRole).toString().toStdString();
		}
		// Get updated musics from dialog music list
		map<string, string> updatedMusics;
		for (int i = 0; i < d.musicList->count(); i++)
		{
			QListWidgetItem *curItem = d.musicList->item(i);
			updatedMusics[curItem->text().toStdString()] = curItem->data(Qt::UserRole).toString().toStdString();
		}
		// Update sfxs and musics in the editor
		TheEditor::Instance().updateSounds(updatedSfxs, updatedMusics);
	}
}

void S2PEditor::on_actionMusic_triggered()
{
	// Project music list
	QStringList musicList;
	// Current level music
	string levelMusic = TheEditor::Instance().getLevelMusic();
	// Allow to select empty item (no music)
	musicList << "";
	// Fill project music list
	for (auto music : TheEditor::Instance().getMusic())
	{
		if (levelMusic == music.first)
		{
			// Set level music as default
			musicList.push_front(music.first.c_str());
		}
		else
		{
			musicList.push_back(music.first.c_str());
		}
	}

	// Check if there is any music
	if (musicList.size())
	{
		// Show standard item dialog
		QString musicID = QInputDialog::getItem(this, "Level music", "Music ID", musicList, 0, false);
		// Set selected as level's music
		TheEditor::Instance().setLevelMusic(musicID.toStdString());
	}
	else
	{
		QMessageBox::information(this, "S2PEditor",
			"There aren't music files in the sound manager.\n");
	}
}

void S2PEditor::on_actionBackgrounds_triggered()
{
	QBckDialog d(this);
	if (d.exec())
	{
		TheEditor::Instance().updateBackgrounds(d.getBcks());
	}
}

void S2PEditor::on_actionSelectObject_triggered()
{
	if (ui.actionSelectTile->isChecked())
	{
		ui.actionSelectTile->setChecked(false);
	}
	TheEditor::Instance().selectObject(ui.actionSelectObject->isChecked());
}

void S2PEditor::on_actionSelectTile_triggered()
{
	if (ui.actionSelectObject->isChecked())
	{
		ui.actionSelectObject->setChecked(false);
	}
	TheEditor::Instance().selectTile(ui.actionSelectTile->isChecked());
}

void S2PEditor::on_actionGameSettings_triggered()
{
	QGameSettingsDialog d;
	if (d.exec())
	{
		// Update max values
		int maxHealth, maxLives, maxScore, maxKeys;
		d.getMaxValues(maxHealth, maxLives, maxScore, maxKeys);
		TheEditor::Instance().setMaxValues(maxHealth, maxLives, maxScore, maxKeys);
		// Update min values
		int initHealth, initLives, initScore, initKeys;
		d.getInitValues(initHealth, initLives, initScore, initKeys);
		TheEditor::Instance().setInitValues(initHealth, initLives, initScore, initKeys);
		// Update HUD icons
		string healthIcon, livesIcon, scoreIcon, keysIcon;
		d.getHUDIcons(healthIcon, livesIcon, scoreIcon, keysIcon);
		TheEditor::Instance().setHUDIcons(healthIcon, livesIcon, scoreIcon, keysIcon);
		// Update screen textures
		string startScreen, pauseScreen, gameOverScreen, endScreen;
		d.getScreenTextureIDs(startScreen, pauseScreen, gameOverScreen, endScreen);
		TheEditor::Instance().setScreenTextureIDs(startScreen, pauseScreen, gameOverScreen, endScreen);
		// Update window size
		int wWidth, wHeight;
		d.getWindowSize(wWidth, wHeight);
		TheEditor::Instance().setWindowSize(wWidth, wHeight);
		// Update game levels 
		TheEditor::Instance().setLevelFiles(d.getGameLevels());
		// Update game settings
		TheEditor::Instance().updateGameSettings();
	}
}

bool S2PEditor::loadLevel(QString id, QString source)
{
	QSize levelSize;
	if (TheEditor::Instance().loadLevel(source.toStdString()))
	{
		// Load level with given id and source values
		m_levelName = id;
		m_levelSource = source;
		updateWindowTitle();
		levelSize = { TheEditor::Instance().getLevelWidthPx(), TheEditor::Instance().getLevelHeightPx() };
		// Tells SDL canvas the size of the new level
		m_SDLCanvas->setSizeHint(levelSize);
		m_SDLCanvas->resize(m_SDLCanvas->sizeHint());
		m_canvasArea->canvasResized();
		return true;
	}
	else
	{
		TheEditor::Instance().stop();
		QMessageBox::critical(this, "S2PEditor",
			"Couldn't load level '" + id + "'");
		// Clean canvas area until new level is loaded
		levelSize = { 0, 0 };
		return false;
	}
}

void S2PEditor::saveAndLoadLevel(QString id, QString source)
{
	// Save current level before loading new one
	TheEditor::Instance().saveLevel(m_levelSource.toStdString());
	loadLevel(id, source);
}

void S2PEditor::deleteLevel(QString id, QString source)
{

	// Delete level from project levels
	if (TheEditor::Instance().deleteLevel(id.toStdString(), source.toStdString()))
	{
		// Check if level exists
		if (QFile::exists(source))
		{
			// Delete the file
			if (QFile::remove(source))
			{
				// Check if the deleted is the current level
				if (m_levelSource == source)
				{
					// Current level no longer exists. Load first level
					QString firstID = QString::fromStdString(TheEditor::Instance().getLevels().front().first);
					QString firstSource = QString::fromStdString(TheEditor::Instance().getLevels().front().second);
					loadLevel(firstID, firstSource);
				}
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Could not delete the level file.");
			}
		}
		else
		{
			QMessageBox::critical(this, "S2PEditor",
				"Could not find level file.");
		}
	}
	else
	{
		QMessageBox::critical(this, "S2PEditor",
			"Could not delete level from the project.");
	}
	// Save changes in the project
	saveProject();
}

void S2PEditor::saveProject()
{
	// If 'projects' dir doesn't exist, create it
	if (!QDir().exists("projects"))
	{
		QDir().mkdir("projects");
	}
	// If current project dir doesn't exist, create it
	if (!QDir().exists("projects/" + m_projectName))
	{
		QDir().mkdir("projects/" + m_projectName);
	}
	// If current project levels dir doesn't exist, create it
	if (!QDir().exists("projects/" + m_projectName + "/levels"))
	{
		QDir().mkdir("projects/" + m_projectName + "/levels");
	}

	// Save current project and level
	TheEditor::Instance().saveProject(m_projectSource.toStdString());
	TheEditor::Instance().saveLevel(m_levelSource.toStdString());

	updateLastEdited();
}

void S2PEditor::updateWindowTitle()
{
	setWindowTitle(m_levelName + " - " + m_projectName + " - " + m_appName);
}

void S2PEditor::removeTileset(int index)
{
	TheEditor::Instance().removeTileset(index);
	saveProject();
}

void S2PEditor::on_actionExportProject_triggered()
{
	bool nameOk;
	// Ask for exported project name
	QString exportName = QInputDialog::getText(this, "Export project", "Project name",
		QLineEdit::Normal, QString(), &nameOk);
	if (nameOk)
	{
		// Where to export
		QString dstFolder = QFileDialog::getExistingDirectory(this, "Destination folder", "/");
		if (!dstFolder.isEmpty())
		{
			// Make destiny folder
			QDir dstRootDir(dstFolder + "/" + exportName);
			dstRootDir.mkpath(dstRootDir.path());
			// Copy project file
			QFile().copy(m_projectSource, dstRootDir.path() + "/" + exportName + ".s2pe");

			// Make levels folder
			QDir dstLevelsDir(dstRootDir.path() + "/levels");
			dstLevelsDir.mkpath(dstLevelsDir.path());
			// Copy each project level
			auto levels = TheEditor::Instance().getLevels();
			vector<pair<string, string>> localLevels;
			for (auto level : levels)
			{
				QString srcLevel = level.second.c_str();
				QString dstLevel = dstLevelsDir.path() + "/" + srcLevel.section("/", -1);
				QFile().copy(srcLevel, dstLevel);
				// Save local level path
				auto localPath = make_pair(level.first, "projects/" + exportName.toStdString() +
					"/levels" + level.second.substr(level.second.find_last_of("/\\")));
				localLevels.push_back(localPath);
			}

			// Make assets folder
			QDir dstAssetsDir(dstRootDir.path() + "/assets");
			dstAssetsDir.mkdir(dstAssetsDir.path());

			// Get assets: textures, sfxs and music
			auto textures = TheEditor::Instance().getTextures();
			auto sfxs = TheEditor::Instance().getSfxs();
			auto music = TheEditor::Instance().getMusic();

			// Copy each project asset into an assets folder
			map<string, string> assets;
			// Add textures, sfxs and music to assets map
			assets.insert(textures.begin(), textures.end());
			assets.insert(sfxs.begin(), sfxs.end());
			assets.insert(music.begin(), music.end());
			for (auto asset : assets)
			{
				QString srcAsset = asset.second.c_str();	// source path
				QString dstAsset = dstAssetsDir.path() + "/" + srcAsset.section("/", -1);	// destiny path
				// copy asset into 'assets' folder
				QFile::copy(srcAsset, dstAsset);
			}

			// Get local texture paths
			map<string, string> localTextures;
			for (auto texture : textures)
			{
				//Save local texture path
				string localPath = "projects/" + exportName.toStdString() + "/assets" +
					texture.second.substr(texture.second.find_last_of("/\\"));
				// insert 
				localTextures.insert(make_pair(texture.first, localPath));
			}

			// Get local sfx paths
			map<string, string> localSfxs;
			for (auto sfx : sfxs)
			{
				//Save local sfx path
				string localPath = "projects/" + exportName.toStdString() + "/assets" +
					sfx.second.substr(sfx.second.find_last_of("/\\"));
				// insert 
				localSfxs.insert(make_pair(sfx.first, localPath));
			}

			// Get local music path
			map<string, string> localMusic;
			for (auto msc : music)
			{
				//Save local music path
				string localPath = "projects/" + exportName.toStdString() + "/assets" +
					msc.second.substr(msc.second.find_last_of("/\\"));
				// insert 
				localMusic.insert(make_pair(msc.first, localPath));
			}

			// Write new project file with local assets
			QString projectFile = dstRootDir.path() + "/" + exportName + ".s2pe";
			EditorParser parser;
			if (parser.writeProjectFile(projectFile.toStdString(),
				TheEditor::Instance().getObjectCfgs(),
				localTextures,
				TheEditor::Instance().getTilesets(),
				localLevels,
				localSfxs,
				localMusic))
			{
				QMessageBox::information(this, "S2PEditor",
					"Project exported successfully to folder\n"
					+ dstRootDir.path());
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Could not export the project.");
			}
		}
	}
}

void S2PEditor::on_actionCreateGame_triggered()
{
	bool nameOk;
	// Ask for game name
	QString gameName = QInputDialog::getText(this, "Create game", "Game name",
		QLineEdit::Normal, QString(), &nameOk);
	if (nameOk)
	{
		// Where to create the game
		QString dstDirPath = QFileDialog::getExistingDirectory(this, "Destiny folder");
		if (!dstDirPath.isEmpty())
		{
			// Create game folder
			QDir gameDir(dstDirPath + "/" + gameName);
			QString gamePath = gameDir.path();
			gameDir.mkpath(gameDir.path());

			// Create levels subfolder 
			QDir levelsDir(gameDir.path() + "/levels");
			levelsDir.mkpath(levelsDir.path());
			// Copy game level files and get local paths
			vector<pair<string, string>> localLevels;
			for (auto level : TheEditor::Instance().getGameLevels())
			{
				string levelFile = level.second.substr(level.second.find_last_of("/\\"));	// "/level.xml"
				// Copy source level in destiny folder
				QFile().copy(level.second.c_str(), levelsDir.path() + levelFile.c_str());
				// save local level
				localLevels.push_back(make_pair(level.first, "levels" + levelFile));
			}

			// Create assets subfolder
			QDir assetsDir(gameDir.path() + "/assets");
			assetsDir.mkpath(assetsDir.path());

			// Get assets: textures, sfxs and music
			auto textures = TheEditor::Instance().getTextures();
			auto sfxs = TheEditor::Instance().getSfxs();
			auto music = TheEditor::Instance().getMusic();

			// Copy each project asset into an assets folder
			map<string, string> assets;
			// Add textures, sfxs and music to assets map
			assets.insert(textures.begin(), textures.end());
			assets.insert(sfxs.begin(), sfxs.end());
			assets.insert(music.begin(), music.end());
			for (auto asset : assets)
			{
				QString srcAsset = asset.second.c_str();	// source path
				QString dstAsset = assetsDir.path() + "/" + srcAsset.section("/", -1);	// destiny path
				// copy asset into 'assets' folder
				QFile::copy(srcAsset, dstAsset);
			}

			// Get local texture paths
			map<string, string> localTextures;
			for (auto texture : TheEditor::Instance().getTextures())
			{
				string imageFile = texture.second.substr(texture.second.find_last_of("/\\"));	// "/image.png"
				// Save local path
				localTextures.insert(make_pair(texture.first, "assets" + imageFile));
			}

			// Get local sfx paths
			map<string, string> localSfxs;
			for (auto sound : TheEditor::Instance().getSfxs())
			{
				string soundFile = sound.second.substr(sound.second.find_last_of("/\\"));	// "/sfx.wav"
				// Save local path
				localSfxs.insert(make_pair(sound.first, "assets" + soundFile));
			}

			// Copy sounds and get local paths
			map<string, string> localMusic;
			for (auto msc : music)
			{
				string soundFile = msc.second.substr(msc.second.find_last_of("/\\"));	// "/music.ogg"
				// Save local path
				localMusic.insert(make_pair(msc.first, "assets" + soundFile));
			}

			// Create s2p game file
			EditorParser parser;
			if (parser.writeGameFile(
				gameDir.path().toStdString() + "/game.s2p",
				localTextures,
				TheEditor::Instance().getTilesets(),
				localLevels,
				localSfxs,
				localMusic) == 0)	// success
			{
				// copy other game resources and dlls
				copyRecursively("gameData", gameDir.path());
				// Show information about success
				QMessageBox::information(this, "S2PEditor",
					"Game exported successfully to folder\n"
					+ gameDir.path());
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Could not export the game.");
			}
		}
	}
}

void S2PEditor::copyRecursively(QString srcDirPath, QString dstDirPath)
{
	QDir srcDir{ srcDirPath };
	if (srcDir.exists())
	{
		// entryList give us local path of files and directories in srcDir
		auto srcFiles = srcDir.entryList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
		for (auto srcFile : srcFiles)
		{
			// get info of the current entry
			QFileInfo srcFileInfo{ srcDir.path() + "/" + srcFile };
			if (srcFileInfo.isDir())
			{
				// make new folder and copy its files recursively
				QDir newFolder{ dstDirPath + "/" + srcFile };
				newFolder.mkdir(newFolder.path());
				copyRecursively(srcFileInfo.absoluteFilePath(), newFolder.path());
			}
			else
			{
				// copy the file
				QFile().copy(srcFileInfo.absoluteFilePath(), 
							 dstDirPath + "/" + srcFile);
			}
		}
	}
}

void S2PEditor::closeEvent(QCloseEvent *event)
{
	// Ask if the user wants to save the project
	switch (QMessageBox(QMessageBox::Question, "",
		"Do you want to save the project before closing",
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this).exec())
	{
	case QMessageBox::Yes:
		saveProject();
		event->accept();
		break;
	case QMessageBox::Cancel:
		event->ignore();
		break;
	default:
		event->accept();		
	}
}

void S2PEditor::disableActions()
{

	ui.actionOpen->setDisabled(true);
	ui.actionSaveAs->setDisabled(true);
	ui.actionRun->setDisabled(true);
	ui.actionAddLevel->setDisabled(true);
	ui.actionSelectObject->setDisabled(true);
	ui.actionSelectTile->setDisabled(true);
	ui.actionTextures->setDisabled(true);
	ui.actionBackgrounds->setDisabled(true);
	ui.actionGameSettings->setDisabled(true);
	ui.actionSaveProject->setDisabled(true);
	ui.actionNewProject->setDisabled(true);
	ui.actionExportProject->setDisabled(true);
	ui.actionCreateGame->setDisabled(true);
	ui.actionSounds->setDisabled(true);
	ui.actionMusic->setDisabled(true);
	// Disable dock windows
	m_tilesetsDock->setDisabled(true);
	m_objectsDock->setDisabled(true);
	m_levelsDock->setDisabled(true);
	// Hide scrollbars in test mode (camera will be centered in the player)
	m_canvasArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_canvasArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void S2PEditor::enableActions()
{
	// Enable resize again
	setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	setMinimumSize(0, 0);
	// Enable again the editor mode actions
	ui.actionRun->setDisabled(false);
	ui.actionOpen->setDisabled(false);
	ui.actionSaveAs->setDisabled(false);
	ui.actionAddLevel->setDisabled(false);
	ui.actionSelectObject->setDisabled(false);
	ui.actionSelectTile->setDisabled(false);
	ui.actionTextures->setDisabled(false);
	ui.actionBackgrounds->setDisabled(false);
	ui.actionGameSettings->setDisabled(false);
	ui.actionSaveProject->setDisabled(false);
	ui.actionNewProject->setDisabled(false);
	ui.actionExportProject->setDisabled(false);
	ui.actionCreateGame->setDisabled(false);
	ui.actionSounds->setDisabled(false);
	ui.actionMusic->setDisabled(false);
	// Enable dock windows
	m_tilesetsDock->setDisabled(false);
	m_objectsDock->setDisabled(false);
	m_levelsDock->setDisabled(false);
	// Get scrollbars back if they are needed
	m_canvasArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	m_canvasArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void S2PEditor::on_actionAboutS2PEditor_triggered()
{
	// Show info about the program
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	QMessageBox::about(this, "About S2PEditor", QString::fromLatin1(
		"<center><font size = 6>S2PEditor 1.0</font></center>"
		"<br><center>SDL 2D Platformers Editor</center>"
		"<br><center>Designed and programmed by Aarón Ojeda</center>"));
}
