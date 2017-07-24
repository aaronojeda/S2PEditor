#include "QBckDialog.h"
#include "EditorController.h"
#include "QAddBckDialog.h"

using namespace std;

QBckDialog::QBckDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	
	// Add image label to layout
	m_image = new QLabel(this);
	scrollArea->setWidget(m_image);

	// Fill background vector
	m_bcks = TheEditor::Instance().getBackgrounds();

	// Fill background list
	for (auto bck : m_bcks)
	{
		QListWidgetItem *item = new QListWidgetItem(bck.name.c_str(), bckList);
	}
}

QBckDialog::~QBckDialog()
{

}

void QBckDialog::on_bckList_currentItemChanged()
{
	QListWidgetItem *curItem = bckList->currentItem();

	if (curItem)
	{
		for (auto bck : m_bcks)
		{
			if (bck.name == curItem->text().toStdString())
			{
				// Fill background fields
				nameLabel->setText(bck.name.c_str());
				imageIDEdit->setText(QString::fromStdString(bck.textureID));
				typeEdit->setText(QString::fromStdString(bck.type));
				speedXEdit->setText(QString::number(bck.xSpeed));
				speedYEdit->setText(QString::number(bck.ySpeed));
				// Show image
				string textureSource = TheEditor::Instance().getTextures().at(bck.textureID);
				QPixmap pixmap(QString::fromStdString(textureSource));
				m_image->setPixmap(pixmap);
			}
		}
	}
	else
	{
		nameLabel->setText("<No item selected>");
		imageIDEdit->clear();
		typeEdit->clear();
		speedXEdit->clear();
		speedYEdit->clear();
		m_image->clear();
	}
}

void QBckDialog::on_deleteButton_clicked()
{
	QListWidgetItem *curItem = bckList->currentItem();
	if (curItem) 
	{
		// Delete background from vector
		for (auto it = m_bcks.begin(); it != m_bcks.end();)
		{
			if (it->name == curItem->text().toStdString())
			{
				it = m_bcks.erase(it);
			}
			else
			{
				++it;
			}
		}

		// Delete from QListWidget
		bckList->takeItem(bckList->row(curItem));
		delete curItem;
	}
}

void QBckDialog::on_addButton_clicked()
{
	QAddBckDialog *d = new QAddBckDialog(this);
	if (d->exec())
	{
		// Create new bck config
		GameObjCfg newBck;
		newBck.type = d->typeCombo->currentText().toStdString();
		newBck.textureID = d->imageCombo->currentText().toStdString();
		newBck.xSpeed = d->xSpeedSpin->value();
		newBck.ySpeed = d->ySpeedSpin->value();
		// Add new bck config to the list and the vector
		newBck.name = newBck.textureID;
		m_bcks.push_back(newBck);
		QListWidgetItem *item = new QListWidgetItem(newBck.name.c_str(), bckList);
		//QListWidgetItem *item = new QListWidgetItem(newBckName, bckList);
		// Make current the new added bck
		bckList->setCurrentItem(item);
	}
}

vector<GameObjCfg> QBckDialog::getBcks()
{
	vector<GameObjCfg> bcks;
	// Fill bcks according to bckList order (m_bcks is unordered).
	for (auto row = 0; row < bckList->count(); row++)
	{
		QListWidgetItem *item = bckList->item(row);
		for (auto bck : m_bcks)
		{
			// Search bck in unordered vector m_bcks
			if (bck.name == item->text().toStdString())
			{
				bcks.push_back(bck);
			}
		}
	}
	// Return ordered vector
	return bcks;
}

void QBckDialog::on_upButton_clicked()
{
	QListWidgetItem *curItem = bckList->currentItem();
	if (curItem)
	{
		int curRow = bckList->row(curItem);
		// Check if current item is the first
		if (curRow)
		{
			// Swap position with previous item
			bckList->takeItem(curRow);
			bckList->insertItem(curRow - 1, curItem);
			bckList->setCurrentItem(curItem);
		}
	}
}

void QBckDialog::on_downButton_clicked()
{
	QListWidgetItem *curItem = bckList->currentItem();
	if (curItem)
	{
		int curRow = bckList->row(curItem);
		// Check if current item is the last
		if (curRow < bckList->count() - 1)
		{
			// Swap position with next item
			QListWidgetItem *nextItem = bckList->takeItem(curRow + 1);
			bckList->insertItem(curRow, nextItem);
			bckList->setCurrentItem(curItem);
		}
	}
}