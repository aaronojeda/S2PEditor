#include "QTexturesDialog.h"
#include "QNewSpriteDialog.h"
#include <QPixmap>
#include <QBoxLayout>
#include <QMessageBox>
#include "EditorController.h"

QTexturesDialog::QTexturesDialog(const std::map<std::string, std::string> &textureMap, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Add image label to layout
	m_image = new QLabel(this);
	scrollArea->setWidget(m_image);
		
	// Fill texture list
	for (auto texture : textureMap)
	{
		QListWidgetItem *item = new QListWidgetItem(texture.first.c_str(), textureList);
		item->setData(Qt::UserRole, texture.second.c_str());
	}
}

QTexturesDialog::~QTexturesDialog()
{

}

void QTexturesDialog::on_addButton_clicked()
{
	QNewSpriteDialog d(this);
	if (d.exec())
	{
		QString textureID, textureSource;
		d.getValues(textureID, textureSource);
		// Check if texture with given id exists
		if (textureList->findItems(textureID, Qt::MatchExactly).size())
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a texture with that ID.");
		}
		else
		{
			// Add new texture to the list
			QListWidgetItem *item = new QListWidgetItem(textureID, textureList);
			item->setData(Qt::UserRole, textureSource);
			textureList->setCurrentItem(item);
		}
	}
}

void QTexturesDialog::on_deleteButton_clicked()
{
	QListWidgetItem *curItem = textureList->currentItem();

	if (curItem) {
		// Delete from QListWidget
		textureList->takeItem(textureList->row(curItem));
		delete curItem;

		if (textureList->count() > 0) textureList->setCurrentRow(0);
		else on_textureList_currentItemChanged();
	}
}

void QTexturesDialog::on_textureList_currentItemChanged()
{
	QListWidgetItem *curItem = textureList->currentItem();

	if (curItem) 
	{
		// Show id, source and image
		idLabel->setText("ID: " + curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
		QPixmap pixmap(curItem->data(Qt::UserRole).toString()); 
		m_image->setPixmap(pixmap);
	}
	else 
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
		m_image->clear();
	}
}