#include "QLevelsDock.h"
#include "EditorController.h"
#include <QDebug>
#include <QMessageBox>

QLevelsDock::QLevelsDock(QWidget *parent)
	: QDockWidget(parent)
{
	setupUi(this);
}

QLevelsDock::~QLevelsDock()
{

}

void QLevelsDock::on_levelUpButton_clicked()
{
	QListWidgetItem *curItem = levelList->currentItem();
	if (curItem)
	{
		int curRow = levelList->row(curItem);
		// Check if current item is the first
		if (curRow)
		{
			// Swap position with previous item
			levelList->takeItem(curRow);
			levelList->insertItem(curRow - 1, curItem);
			levelList->setCurrentItem(curItem);
		}
	}
}

void QLevelsDock::on_levelDownButton_clicked()
{
	QListWidgetItem *curItem = levelList->currentItem();
	if (curItem)
	{
		int curRow = levelList->row(curItem);
		// Check if current item is the last
		if (curRow < levelList->count() - 1)
		{
			// Swap position with next item
			QListWidgetItem *nextItem = levelList->takeItem(curRow + 1);
			levelList->insertItem(curRow, nextItem);
			levelList->setCurrentItem(curItem);
		}
	}
}

void QLevelsDock::on_deleteLevelButton_clicked()
{
	QListWidgetItem *curItem = levelList->currentItem();

	if (curItem)
	{
		if (levelList->count() > 1)
		{
			// Action can't be reverted. Confirm deletion
			QMessageBox msgBox;
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setText("Are you sure that you want to permanently delete level '" +	curItem->text() + "'?");
			msgBox.setInformativeText("Project will be saved. This action cannot be reverted.");
			// Set message box buttons. Default to 'No'
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if (msgBox.exec() == QMessageBox::Yes)
			{
				// Emit signal so S2PEditor can properly delete the level
				emit deleteLevel(curItem->text(), curItem->data(Qt::UserRole).toString());

				// Delete from QListWidget
				levelList->takeItem(levelList->row(curItem));
				delete curItem;
				levelList->setCurrentRow(0);
			}
		}
		else
		{
			QMessageBox::information(this, "S2PEditor",
				"There has to be at least one level in the project.");
		}
	}
}

void QLevelsDock::on_levelList_currentItemChanged()
{
	QListWidgetItem *curItem = levelList->currentItem();

	if (curItem)
	{
		// Show level name and source
		idLabel->setText(curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
	}
	else
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
	}
}

void QLevelsDock::addLevel(QString id, QString source)
{
	auto item = new QListWidgetItem(id, levelList);
	item->setData(Qt::UserRole, source);
	levelList->setCurrentItem(item);
}

void QLevelsDock::update()
{
	loadLevels(TheEditor::Instance().getLevels());
}

void QLevelsDock::loadLevels(std::vector<std::pair<std::string, std::string>> levels)
{
	// Clear current levels in level list
	levelList->clear();
	// Load each level into an item of the list
	for (auto level : levels)
	{
		QListWidgetItem *item = new QListWidgetItem(level.first.c_str(), levelList);
		item->setData(Qt::UserRole, level.second.c_str());
	}
}

void QLevelsDock::on_levelList_itemDoubleClicked(QListWidgetItem *item)
{
	emit loadLevel(item->text(), item->data(Qt::UserRole).toString());
}

void QLevelsDock::on_loadButton_clicked()
{
	auto *curItem = levelList->currentItem();

	if (curItem)
	{
		// Show level name and source
		emit saveAndLoad(curItem->text(), curItem->data(Qt::UserRole).toString());
	}
}
