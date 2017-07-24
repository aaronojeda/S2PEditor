#include "QTilesetLabel.h"
#include <QPainter>
#include <QMouseEvent>
#include <QImage>
#include <QImageReader>
#include <QMessageBox>
#include "EditorController.h"

QTilesetLabel::QTilesetLabel() : 
QLabel(),
m_paintRect( 0, 0, 0, 0 ),
m_tileSelected(false),
m_row(0),
m_column(0),
m_scaleFactor(1.0)
{
}

void QTilesetLabel::paintEvent(QPaintEvent *e)
{
	QLabel::paintEvent(e);

	if (m_tileSelected)
	{
		QPainter painter(this);
		painter.setPen(QPen(Qt::red));
		painter.drawRect(m_paintRect);
	}
}

void QTilesetLabel::setZoom(double zoom)
{
	m_scaleFactor = zoom;
	scaleImage();
}

void QTilesetLabel::scaleImage()
{
	resize(m_scaleFactor * pixmap()->size());
	// Re-draw the rectangle surrounding selected tile, with the new dimensions
	if (m_tileSelected)
	{
		updateRect();
	}
}

void QTilesetLabel::mousePressEvent(QMouseEvent * event)
{
	// Check which button was pressed
	if (event->button() == Qt::LeftButton)
	{
		int x = event->pos().x();
		int y = event->pos().y();

		// Maths to deduce what tile have we selected
		m_row = y / ((m_tileset.tileHeight + m_tileset.spacing) * m_scaleFactor);
		m_column = x / ((m_tileset.tileWidth + m_tileset.spacing) * m_scaleFactor);
		// Change selected tile via the Editor Controller
		TheEditor::Instance().setTile(m_row, m_column);
		// Tile selected flag to true
		m_tileSelected = true;
	}
	else if (event->button() == Qt::RightButton)
	{
		// Tile selected tile to false
		m_tileSelected = false;
		//TheEditor::Instance().changeSelMode(0);
	}
	updateRect();
}

void QTilesetLabel::updateRect()
{
	// Calculate selected tile coordinates in pixels
	int rx = m_column*(m_tileset.tileWidth + m_tileset.spacing) + m_tileset.margin;
	int ry = m_row*(m_tileset.tileHeight + m_tileset.spacing) + m_tileset.margin;

	// Recalculate the selection rectangle considering current zoom
	m_paintRect = QRect(rx*m_scaleFactor, ry*m_scaleFactor,
		m_tileset.tileWidth*m_scaleFactor, 
		m_tileset.tileHeight*m_scaleFactor);

	// Manually call update to force Qt to draw the rectangle
	update();
}

void QTilesetLabel::setTileset(Tileset tileset)
{
	// Load tileset image into QTilesetLabel
	auto textures = TheEditor::Instance().getTextures();
	if (textures.find(tileset.textureID) != textures.end())
	{
		QImageReader reader(TheEditor::Instance().getTextures().at(tileset.textureID).c_str());
		//QImageReader reader(TheEditor::Instance().getLevelTextures().at(tileset.textureID).c_str());
		reader.setAutoTransform(true);
		const QImage image = reader.read();
		setPixmap(QPixmap::fromImage(image));
	}
	else
	{
		QString message = "Coudln't load tileset texture: '" + QString::fromStdString(tileset.textureID) + "'";
		QMessageBox::critical(this, "S2PEditor", message);
	}
	
	m_scaleFactor = 1.0;
	adjustSize();

	m_tileset = tileset;
}

// update selected tile
void QTilesetLabel::updateTile()
{
	// inform the editor about selected tile
	TheEditor::Instance().setTile(m_row, m_column);
}