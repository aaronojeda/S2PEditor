#ifndef S2PEditor_H
#define S2PEditor_H

#include <QMainWindow>
#include "ui_S2PEditor.h"

class QSDLCanvas;
class QTilesetsDock;
class QObjectsDock;
class QLevelsDock;
class QListWidgetItem;
class QCanvasScrollArea;

class S2PEditor : public QMainWindow
{
	Q_OBJECT

public:
	S2PEditor(QWidget *parent = 0);
	~S2PEditor();
private slots:
	void on_actionOpen_triggered();
	void on_actionExit_triggered();
	void on_actionRun_triggered();
	void on_actionStop_triggered();
	void on_actionAddLevel_triggered();
	void on_actionSaveAs_triggered();
	void on_actionTextures_triggered();
	void on_actionSounds_triggered();
	void on_actionMusic_triggered();
	void on_actionBackgrounds_triggered();
	void on_actionSelectObject_triggered();
	void on_actionSelectTile_triggered();
	void on_actionGameSettings_triggered();
	void on_actionExportProject_triggered();
	void on_actionSaveProject_triggered();
	void on_actionNewProject_triggered();
	void on_actionCreateGame_triggered();
	void on_actionAboutS2PEditor_triggered();
	/////////// Nuevas ///////////
	void loadProject(QString projectFile);
	bool loadLevel(QString id, QString source);
	void saveAndLoadLevel(QString id, QString source);
	void deleteLevel(QString id, QString source);
	void removeTileset(int index);
	void disableActions();
	void enableActions();


private:
	Ui::S2PEditorClass ui;

	// Editor window
	QSDLCanvas* m_SDLCanvas;
	// Scroll area that contains editor window
	QCanvasScrollArea * m_canvasArea;
	// Editor tilesets dock
	QTilesetsDock* m_tilesetsDock{ nullptr };
	// Editor objects dock
	QObjectsDock* m_objectsDock{ nullptr };
	// Editor levels dock
	QLevelsDock* m_levelsDock{ nullptr };
	
	QString m_appName;			// Application name
	QString m_levelSource;		// Current level source
	QString m_levelName;		// Current level name
	QString m_projectSource;	// Current project source
	QString m_projectName;		// Current project name

	// Document with info about last edited project and level
	std::string m_lastEdited;

	bool initEditor();
	bool initCanvas();
	void initObjectsDock();
	void initTilesetsDock();
	void initLevelsDock();
	void updateLastEdited();	
	void saveProject();
	void updateWindowTitle();
	void copyRecursively(QString srcDirPath, QString dstDirPath);

	// Overwrite
	void closeEvent(QCloseEvent *event);
};

#endif // S2PEditor_H
