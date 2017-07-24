#include "QSoundsDialog.h"
#include "QAddSoundDialog.h"
#include <QMessageBox>

using namespace std;

QSoundsDialog::QSoundsDialog(const map<string, string> &soundMap,
	const map<string, string> &musicMap, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Fill sound list
	for (auto sound : soundMap)
	{
		QListWidgetItem *item = new QListWidgetItem(sound.first.c_str(), soundList);
		item->setData(Qt::UserRole, sound.second.c_str());
	}

	// Fill music list
	for (auto music : musicMap)
	{
		QListWidgetItem *item = new QListWidgetItem(music.first.c_str(), musicList);
		item->setData(Qt::UserRole, music.second.c_str());
	}
}

QSoundsDialog::~QSoundsDialog()
{

}

void QSoundsDialog::on_addSfxButton_clicked()
{
	addSound(soundList);
}

void QSoundsDialog::on_addMusicButton_clicked()
{
	addSound(musicList);
}

void QSoundsDialog::addSound(QListWidget *l)
{
	QAddSoundDialog d(this);
	if (d.exec())
	{
		QString soundID, soundSource;
		d.getValues(soundID, soundSource);
		// Check if sound with given id exists
		if (l->findItems(soundID, Qt::MatchExactly).size())
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a sound with that ID.");
		}
		else
		{
			// Add new sound to the list
			QListWidgetItem *item = new QListWidgetItem(soundID, l);
			item->setData(Qt::UserRole, soundSource);
			l->setCurrentItem(item);
		}
	}
}

void QSoundsDialog::on_deleteSfxButton_clicked()
{
	deleteSound(soundList);
}

void QSoundsDialog::on_deleteMusicButton_clicked()
{
	deleteSound(musicList);
}

void QSoundsDialog::deleteSound(QListWidget *l)
{
	QListWidgetItem *curItem = l->currentItem();

	if (curItem) {
		// Delete from QListWidget
		l->takeItem(l->row(curItem));
		delete curItem;

		if (l->count() > 0) l->setCurrentRow(0);
		else l->clearSelection();
	}
}

void QSoundsDialog::on_soundList_currentItemChanged()
{
	QListWidgetItem *curItem = soundList->currentItem();

	if (curItem)
	{
		// Show id, source and type
		idLabel->setText("ID: " + curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
		typeLine->setText("sfx");
	}
	else
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
		typeLine->clear();
	}
}

void QSoundsDialog::on_musicList_currentItemChanged()
{
	QListWidgetItem *curItem = musicList->currentItem();

	if (curItem)
	{
		// Show id, source and type
		idLabel->setText("ID: " + curItem->text());
		sourceLine->setText(curItem->data(Qt::UserRole).toString());
		typeLine->setText("music");
	}
	else
	{
		idLabel->setText("<No item selected>");
		sourceLine->clear();
		typeLine->clear();
	}
}