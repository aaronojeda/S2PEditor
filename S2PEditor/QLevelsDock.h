#ifndef QLEVELSDOCK_H
#define QLEVELSDOCK_H

#include <QDockWidget>
#include "ui_QLevelsDock.h"

class QLevelsDock : public QDockWidget, public Ui::QLevelsDock
{
	Q_OBJECT

public:
	QLevelsDock(QWidget *parent = 0);
	~QLevelsDock();
	void addLevel(QString id, QString source);
	void loadLevels(std::vector<std::pair<std::string, std::string>> levels);
	void update();

private slots:
	void on_deleteLevelButton_clicked();
	void on_levelUpButton_clicked();
	void on_levelDownButton_clicked();
	void on_levelList_currentItemChanged();
	void on_levelList_itemDoubleClicked(QListWidgetItem *item);
	void on_loadButton_clicked();

signals:
	void loadLevel(QString id, QString source);
	void deleteLevel(QString id, QString source);
	void saveAndLoad(QString id, QString source);
};

#endif // QLEVELSDOCK_H
