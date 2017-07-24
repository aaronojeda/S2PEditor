#include "QTilesetsDock.h"
#include <QMessageBox>
#include <QImageReader>
#include <qDebug>
#include "QNewTilesetDialog.h"
#include "EditorController.h"
#include "QTilesetScrollArea.h"
#include "QTilesetLabel.h"

using namespace std;

QTilesetsDock::QTilesetsDock(QWidget *parent)
	: QDockWidget(parent)
{
	setupUi(this);

	// signal-slot connections
	connect(zoomSpin, SIGNAL(valueChanged(int)), this, SLOT(setLabelZoom(int)));
}

QTilesetsDock::~QTilesetsDock()
{

}

void QTilesetsDock::on_newButton_clicked()
{
	QNewTilesetDialog d(this);
	if (d.exec())
	{
		string name, textureID;
		int tileSize, margin, spacing;
		d.getValues(name, textureID, tileSize, margin, spacing);

		bool usedName = false;
		// Check if any tileset has the inserted name
		for (auto tileset : TheEditor::Instance().getTilesets())
		{
			if (tileset.name == name)
			{
				usedName = true;
			}
		}

		if (!usedName)
		{				
			// Create a new tileset with the values from the dialog
			Tileset tileset;
			tileset.name = name;
			tileset.textureID = textureID;
			tileset.tileWidth = tileSize;
			tileset.tileHeight = tileSize;
			tileset.margin = margin;
			tileset.spacing = spacing;

			string source = TheEditor::Instance().getTextures().at(textureID);
			// Deduce width and height from margin, spacing, tile size and source image size
			const QImage image = QImageReader(source.c_str()).read();
			tileset.width = (image.width() - tileset.margin) / (tileset.tileWidth + tileset.spacing);
			if (tileset.width == 0) tileset.width = 1;
			tileset.height = (image.height() - tileset.margin) / (tileset.tileHeight + tileset.spacing);
			if (tileset.height == 0) tileset.height = 1;
			// Calculate first global id
			auto tilesets = TheEditor::Instance().getTilesets();
			if (tilesets.size() != 0)
			{
				// last tileset firstgridid plus its number of tiles
				tileset.firstGridID = tilesets.back().firstGridID + tilesets.back().width * tilesets.back().height;
			}
			else
			{
				// no tilesets
				tileset.firstGridID = 1;
			}
			// Inform Editor Controller about the new tileset 
			TheEditor::Instance().addTileset(tileset);
			// Add new tileset to its corresponding QTilesetDock tab and make it current
			addTilesetTab(tileset);
			tilePicker->setCurrentIndex(tilesets.size());
		}
		else
		{
			QMessageBox::warning(0, "Invalid name",
				QString("There's already a tileset called '%1'").arg(name.c_str()));
		}
	}
}

void QTilesetsDock::on_zoomInButton_clicked()
{
	auto scrollArea = dynamic_cast<QTilesetScrollArea*>(tilePicker->currentWidget());
	if (scrollArea != nullptr)
	{
		auto tilesetLabel = dynamic_cast<QTilesetLabel*>(scrollArea->widget());
		if (tilesetLabel != nullptr)
		{
			// SpinBox valueChanged signal is connected with setZoom. Besides, setValue()
			// takes care of max and min values, already defined in initWidgets().
			zoomSpin->setValue(zoomSpin->value() + m_zoomStep);
		}
	}
}
void QTilesetsDock::on_zoomOutButton_clicked()
{
	auto scrollArea = dynamic_cast<QTilesetScrollArea*>(tilePicker->currentWidget());
	if (scrollArea != nullptr)
	{
		auto tilesetLabel = dynamic_cast<QTilesetLabel*>(scrollArea->widget());
		if (tilesetLabel != nullptr)
		{
			// SpinBox valueChanged signal is connected with setZoom. Besides, setValue()
			// takes care of max and min values, already defined in the initWidgets. 
			zoomSpin->setValue(zoomSpin->value() - m_zoomStep);
		}
	}
}

void QTilesetsDock::on_collisionCheckBox_stateChanged(int state)
{
	TheEditor::Instance().setCollisionTiles(state == Qt::Checked);
}

void QTilesetsDock::on_tilePicker_currentChanged(int current)
{
	// If we are coming from currentChanged(int) signal and there are no widgets left, current will be -1
	TheEditor::Instance().setCurrentTileset(current);
	// Apply zoom to the new tileset label
	setLabelZoom(zoomSpin->value());
	// Selected tile can be different when changing tileset
	updateTile();
}

void QTilesetsDock::on_tilePicker_tabCloseRequested(int tabIndex)
{
	// Check if index out of range.
	if (tabIndex < TheEditor::Instance().getTilesets().size())
	{
		// Remove tileset is an irreversible action, so ask the user
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("Do you really want to delete the tileset?");
		msgBox.setInformativeText("This is an irreversible action. "
			"All tiles of current tileset will be removed from every level.");
		// Set message box buttons. Default to 'No'
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::Yes);
		if (msgBox.exec() == QMessageBox::Yes)
		{
			// Inform that a tileset has been closed and remove tab
			emit tilesetClosed(tabIndex);
			tilePicker->removeTab(tabIndex);
		}
	}
	else
	{
		qDebug() << "Error: Tab index does not correspond to any tileset.";
	}
}

void QTilesetsDock::addTilesetTab(Tileset tileset)
{
	// Load tileset into QTilesetLabel tab
	QTilesetLabel* tilesetTab = new QTilesetLabel();
	tilesetTab->setScaledContents(true);
	tilesetTab->setTileset(tileset);
	QTilesetScrollArea* scroll = new QTilesetScrollArea(this);
	scroll->setWidget(tilesetTab);
	tilePicker->addTab(scroll, tileset.name.c_str());
	connect(scroll, SIGNAL(zoom(int)), this, SLOT(updateZoomBox(int)));
}

// Load current project tilesets, clearing previous ones
void QTilesetsDock::update()
{
	loadTilesets(TheEditor::Instance().getTilesets());
}

// Clear current tabs and load each tileset of 'tilesets' in a new one
void QTilesetsDock::loadTilesets(std::vector<Tileset> tilesets)
{
	// Clear tabs
	tilePicker->clear();
	// Load new tilesets
	if (!tilesets.empty())
	{
		// Load tilesets of current project into m_tilePicker tabs.
		for (auto tileset : tilesets)
		{
			addTilesetTab(tileset);
		}
		// First tileset will be the default
		setCurrentTileset(0);
	}
	else
	{
		// No tilesets
		setCurrentTileset(-1);
	}
}

void QTilesetsDock::setCurrentTileset(int current)
{
	// If we are coming from currentChanged(int) signal and there are no widgets left, current will be -1
	TheEditor::Instance().setCurrentTileset(current);
}

// Adds (or subtracts if negative) given value to zoom spinBox's.
void QTilesetsDock::updateZoomBox(int value)
{
	zoomSpin->setValue(zoomSpin->value() + value * m_zoomStep);
}

bool QTilesetsDock::collidable()
{
	return collisionCheckBox->isChecked();
}

void QTilesetsDock::setLabelZoom(int zoom)
{
	// get current scroll area
	auto scrollArea = dynamic_cast<QTilesetScrollArea*>(tilePicker->currentWidget());
	if (scrollArea != nullptr)
	{
		// get current tileset label
		auto tilesetLabel = dynamic_cast<QTilesetLabel*>(scrollArea->widget());
		if (tilesetLabel != nullptr)
		{
			// divide by 100 because QTilesetLabel zoom is from 0 to 1
			tilesetLabel->setZoom(double(zoom) / 100);
		}
	}
}

void QTilesetsDock::updateTile()
{
	// get current scroll area
	auto scrollArea = dynamic_cast<QTilesetScrollArea*>(tilePicker->currentWidget());
	if (scrollArea != nullptr)
	{
		auto tilesetLabel = dynamic_cast<QTilesetLabel*>(scrollArea->widget());
		if (tilesetLabel != nullptr)
		{
			// update selected tile
			tilesetLabel->updateTile();
		}
	}
}