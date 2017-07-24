#include "QGameSettingsDialog.h"
#include <QDebug>
#include <QFileDialog>
#include "QNewSpriteDialog.h"
#include "EditorController.h"
#include <QMessageBox>

using namespace std;

QGameSettingsDialog::QGameSettingsDialog(QWidget *parent)
: QDialog(parent)
{
	setupUi(this);
	// Set current values
	setValues();
}

QGameSettingsDialog::~QGameSettingsDialog()
{

}

void QGameSettingsDialog::getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys)
{
	maxHealth = healthMaxSpin->value();
	maxLives = livesMaxSpin->value();
	maxScore = scoreMaxSpin->value();
	maxKeys = keysMaxSpin->value();
}

void QGameSettingsDialog::getInitValues(int &InitHealth, int &InitLives, int &InitScore, int &InitKeys)
{
	InitHealth = healthInitSpin->value();
	InitLives = livesInitSpin->value();
	InitScore = scoreInitSpin->value();
	InitKeys = keysInitSpin->value();
}

void QGameSettingsDialog::getHUDIcons(std::string &healthIcon, std::string &livesIcon, std::string &scoreIcon, std::string &keysIcon)
{
	healthIcon = healthCombo->currentText().toStdString();
	livesIcon = livesCombo->currentText().toStdString();
	scoreIcon = scoreCombo->currentText().toStdString();
	keysIcon = keysCombo->currentText().toStdString();
}

void QGameSettingsDialog::getScreenTextureIDs(std::string &start, std::string &pause, std::string &gameOver, std::string &end)
{
	start = startCombo->currentText().toStdString();
	pause = pauseCombo->currentText().toStdString();
	gameOver = gameOverCombo->currentText().toStdString();
	end = endCombo->currentText().toStdString();
}


void QGameSettingsDialog::setValues()
{
	// Fill editor level List
	auto levels = TheEditor::Instance().getLevels();
	for (auto level : levels)
	{
		QListWidgetItem *item = new QListWidgetItem(level.first.c_str(), editorLevelList);
		item->setData(Qt::UserRole, level.second.c_str());
	}
	// Fill game level list
	levels = TheEditor::Instance().getGameLevels();
	for (auto level : levels)
	{
		QListWidgetItem *item = new QListWidgetItem(level.first.c_str(), gameLevelList);
		item->setData(Qt::UserRole, level.second.c_str());
	}
	// Load textures to combo boxes
	for (auto texture : TheEditor::Instance().getTextures())
	{
		healthCombo->addItem(texture.first.c_str());
		livesCombo->addItem(texture.first.c_str());
		scoreCombo->addItem(texture.first.c_str());
		keysCombo->addItem(texture.first.c_str());
		startCombo->addItem(texture.first.c_str());
		pauseCombo->addItem(texture.first.c_str());
		gameOverCombo->addItem(texture.first.c_str());
		endCombo->addItem(texture.first.c_str());
	}
	// Get HUD icons
	string healthIcon, livesIcon, scoreIcon, keysIcon;
	TheEditor::Instance().getHUDIcons(healthIcon, livesIcon, scoreIcon, keysIcon);
	// Get maximum and initial values
	int maxHealth, maxLives, maxScore, maxKeys, initHealth, initLives, initScore, initKeys;
	TheEditor::Instance().getMaxValues(maxHealth, maxLives, maxScore, maxKeys);
	TheEditor::Instance().getInitValues(initHealth, initLives, initScore, initKeys);
	// Set health values
	healthMaxSpin->setValue(maxHealth);
	healthInitSpin->setValue(initHealth);
	healthCombo->setCurrentText(healthIcon.c_str());
	// Set lives values
	livesMaxSpin->setValue(maxLives);
	livesInitSpin->setValue(initLives);
	livesCombo->setCurrentText(livesIcon.c_str());
	// Set score values
	scoreMaxSpin->setValue(maxScore);
	scoreInitSpin->setValue(initScore);
	scoreCombo->setCurrentText(scoreIcon.c_str());
	// Set keys values
	keysMaxSpin->setValue(maxKeys);
	keysInitSpin->setValue(initKeys);
	keysCombo->setCurrentText(keysIcon.c_str());
	// Get game screen sources
	string startScreenID, pauseScreenID, gameOverScreenID, endScreenID;
	TheEditor::Instance().getScreenTextureIDs(startScreenID, pauseScreenID, gameOverScreenID, endScreenID);
	// Set screen sources
	startCombo->setCurrentText(startScreenID.c_str());
	pauseCombo->setCurrentText(pauseScreenID.c_str());
	gameOverCombo->setCurrentText(gameOverScreenID.c_str());
	endCombo->setCurrentText(endScreenID.c_str());
	// Set window size
	windowWidthSpin->setValue(TheEditor::Instance().getWindowWidth());
	windowHeightSpin->setValue(TheEditor::Instance().getWindowHeight());
}

void QGameSettingsDialog::on_livesButton_clicked()
{
	browseImage(livesCombo);
}

void QGameSettingsDialog::on_healthButton_clicked()
{
	browseImage(healthCombo);
}

void QGameSettingsDialog::on_scoreButton_clicked()
{
	browseImage(scoreCombo);
}

void QGameSettingsDialog::on_keysButton_clicked()
{
	browseImage(keysCombo);
}

void QGameSettingsDialog::browseImage(QComboBox* cBox)
{
	QNewSpriteDialog d;
	if (d.exec())
	{
		QString id, source;
		d.getValues(id, source);

		// Check if there is already a texture with that name
		auto textureList = TheEditor::Instance().getTextures();
		if (textureList.find(id.toStdString()) != textureList.end())
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a texture with that ID.");
		}
		else
		{
			// Load new texture
			if (TheEditor::Instance().loadTexture(id.toStdString(), source.toStdString()))
			{
				// Add new texture ID to all combo boxes
				healthCombo->addItem(id);
				livesCombo->addItem(id);
				scoreCombo->addItem(id);
				keysCombo->addItem(id);
				startCombo->addItem(id);
				pauseCombo->addItem(id);
				gameOverCombo->addItem(id);
				endCombo->addItem(id);
				// Set new texture ID as current combo box text
				cBox->setCurrentText(id);
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Couldn't load texture");
			}
		}
	}
}

void QGameSettingsDialog::on_editorLevelList_currentItemChanged()
{
	QListWidgetItem *curItem = editorLevelList->currentItem();

	if (curItem)
	{
		// Show level name and source
		idLabel->setText(curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
	}
	else
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
	}
}

void QGameSettingsDialog::on_gameLevelList_currentItemChanged()
{
	QListWidgetItem *curItem = gameLevelList->currentItem();

	if (curItem)
	{
		// Show level name and source
		idLabel->setText(curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
	}
	else
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
	}
}

void QGameSettingsDialog::on_addLevelButton_clicked()
{
	// get editor level name and file
	QString levelName, levelFile;
	levelName = editorLevelList->currentItem()->text();
	levelFile = editorLevelList->currentItem()->data(Qt::UserRole).toString();
	// create new game levels list item
	auto newLevelItem = new QListWidgetItem(levelName, gameLevelList);
	newLevelItem->setData(Qt::UserRole, levelFile);
	gameLevelList->setCurrentItem(newLevelItem);
}

void QGameSettingsDialog::on_deleteLevelButton_clicked()
{
	QListWidgetItem *curItem = gameLevelList->currentItem();

	if (curItem)
	{
		// Delete from QListWidget
		gameLevelList->takeItem(gameLevelList->row(curItem));
		delete curItem;

		if (gameLevelList->count() > 0) gameLevelList->setCurrentRow(0);
		else on_gameLevelList_currentItemChanged();
	}
}

void QGameSettingsDialog::on_levelUpButton_clicked()
{
	QListWidgetItem *curItem = gameLevelList->currentItem();
	if (curItem)
	{
		int curRow = gameLevelList->row(curItem);
		// Check if current item is the first
		if (curRow)
		{
			// Swap position with previous item
			gameLevelList->takeItem(curRow);
			gameLevelList->insertItem(curRow - 1, curItem);
			gameLevelList->setCurrentItem(curItem);
		}
	}
}

void QGameSettingsDialog::on_levelDownButton_clicked()
{
	QListWidgetItem *curItem = gameLevelList->currentItem();
	if (curItem)
	{
		int curRow = gameLevelList->row(curItem);
		// Check if current item is the last
		if (curRow < gameLevelList->count() - 1)
		{
			// Swap position with next item
			QListWidgetItem *nextItem = gameLevelList->takeItem(curRow + 1);
			gameLevelList->insertItem(curRow, nextItem);
			gameLevelList->setCurrentItem(curItem);
		}
	}
}

void QGameSettingsDialog::on_startScreenButton_clicked()
{
	browseImage(startCombo);
}

void QGameSettingsDialog::on_pauseScreenButton_clicked()
{
	browseImage(pauseCombo);
}

void QGameSettingsDialog::on_gameOverScreenButton_clicked()
{
	browseImage(gameOverCombo);
}

void QGameSettingsDialog::on_endScreenButton_clicked()
{
	browseImage(endCombo);
}

void QGameSettingsDialog::getWindowSize(int &width, int &height)
{
	width = windowWidthSpin->value();
	height = windowHeightSpin->value();
}

const vector<pair<string, string>> QGameSettingsDialog::getGameLevels()
{
	// get game levels from game level list
	vector<pair<string, string>> gameLevels;
	for (int i = 0; i < gameLevelList->count(); i++)
	{
		QListWidgetItem* curItem = gameLevelList->item(i);
		string levelName = curItem->text().toStdString();
		string levelFile = curItem->data(Qt::UserRole).toString().toStdString();
		// Insert level 'i' into levels vector
		gameLevels.push_back(make_pair(levelName, levelFile));
	}
	return gameLevels;
}
