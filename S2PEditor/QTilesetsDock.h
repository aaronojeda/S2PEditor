#ifndef QTILESETSDOCK_H
#define QTILESETSDOCK_H

#include <QDockWidget>
#include "ui_QTilesetsDock.h"
#include "Level.h"

class QTilesetsDock : public QDockWidget, public Ui::QTilesetsDock
{
	Q_OBJECT

public:
	QTilesetsDock(QWidget *parent = 0);
	~QTilesetsDock();

	void update();
	void loadTilesets(std::vector<Tileset> tilesets);
	bool collidable();

private:
	int m_zoomStep{ 10 };

	void addTilesetTab(Tileset tileset);
	void updateTile();

private slots:
	void on_newButton_clicked();
	void on_zoomInButton_clicked();
	void on_zoomOutButton_clicked();
	void on_collisionCheckBox_stateChanged(int state);
	void on_tilePicker_currentChanged(int current);
	void on_tilePicker_tabCloseRequested(int tabIndex);
	void updateZoomBox(int value);
	void setCurrentTileset(int current);
	void setLabelZoom(int zoom);

signals:
	void tilesetClosed(int index);
};

#endif // QTILESETSDOCK_H
