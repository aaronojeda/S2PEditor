#ifndef QOBJECTSDOCK_H
#define QOBJECTSDOCK_H

#include <QDockWidget>
#include "ui_QObjectsDock.h"
#include <QString>
#include "EditorParser.h"	// Where struct GameObjCfg is

class QNewObjectDialog;

class QObjectsDock : public QDockWidget, public Ui::QObjectsDock
{
	Q_OBJECT

public:
	QObjectsDock(QWidget *parent = 0);
	~QObjectsDock();

	void update();
	void loadObjects(const std::map<std::string, GameObjCfg> &objects);
	QString currentObject();
	void clear();

private:
	// Create object with QNewObjectDialog values
	void createObject(QNewObjectDialog* d);

private slots:
	void on_nameCombo_currentIndexChanged(QString text);
	void on_editButton_clicked();
	void on_deleteButton_clicked();
	// Buttons for creating objects
	void on_playerButton_clicked();
	void on_leftRightButton_clicked();
	void on_flyingButton_clicked();
	void on_chaserButton_clicked();
	void on_flyingChaserButton_clicked();
	void on_scoreItemButton_clicked();
	void on_healthItemButton_clicked();
	void on_livesItemButton_clicked();
	void on_keyItemButton_clicked();
	void on_lockedDoorButton_clicked();
	void on_levelFinishButton_clicked();
	void on_checkPointButton_clicked();
};

#endif // QOBJECTSDOCK_H
