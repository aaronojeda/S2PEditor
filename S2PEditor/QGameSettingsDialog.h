#ifndef QGAMESETTINGSDIALOG_H
#define QGAMESETTINGSDIALOG_H

#include <QDialog>
#include "ui_QGameSettingsDialog.h"

class QGameSettingsDialog : public QDialog, public Ui::QGameSettingsDialog
{
	Q_OBJECT

public:
	QGameSettingsDialog(QWidget *parent = 0);
	~QGameSettingsDialog();

	void getMaxValues(int &maxHealth, int &maxLives, int &maxScore, int &maxKeys);
	void getInitValues(int &InitHealth, int &InitLives, int &InitScore, int &InitKeys);
	void getHUDIcons(std::string &healthIcon, std::string &livesIcon, std::string &scoreIcon, std::string &keysIcon);
	void getScreenTextureIDs(std::string &start, std::string &pause, std::string &gameOver, std::string &end);
	void getWindowSize(int &width, int &height);
	const std::vector<std::pair<std::string, std::string>> getGameLevels();
	void setValues();

private:
	void browseImage(QComboBox *cBox);

	private slots:
	// HUD
	void on_livesButton_clicked();
	void on_healthButton_clicked();
	void on_scoreButton_clicked();
	void on_keysButton_clicked();
	// Show seleceted level's name and source
	void on_editorLevelList_currentItemChanged();
	// Show seleceted level's name and source
	void on_gameLevelList_currentItemChanged();
	// Add one of th editor levels to game levels
	void on_addLevelButton_clicked();
	// Delete a level from game levels
	void on_deleteLevelButton_clicked();
	// Swap level position with the level before
	void on_levelUpButton_clicked();
	// Swap level position with the level later
	void on_levelDownButton_clicked();
	// Screens
	void on_startScreenButton_clicked();
	void on_pauseScreenButton_clicked();
	void on_gameOverScreenButton_clicked();
	void on_endScreenButton_clicked();
};

#endif // QGAMESETTINGSDIALOG_H
