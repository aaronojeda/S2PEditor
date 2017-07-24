#pragma once

#include <QLabel>
#include "Level.h"

class QMouseEvent;
class QPaintEvent;

class QTilesetLabel :	public QLabel
{
	Q_OBJECT
public:
	QTilesetLabel();
	~QTilesetLabel(){}

	void setTileset(Tileset tileset);
	void updateTile();

public slots:
	void setZoom(double zoom);

private:
	// Override
	void mousePressEvent(QMouseEvent * event);
	void paintEvent(QPaintEvent *e);

	// Custom
	void scaleImage();
	void updateRect();

	// Data members
	QRect m_paintRect;		// to highlight selected area
	bool m_tileSelected;	// to know if something is selected
	double m_scaleFactor;	// zoom factor
	Tileset m_tileset;		// tileset to show
	int m_row;				// Selected tile's row
	int m_column;			// Selected tile's column
};
