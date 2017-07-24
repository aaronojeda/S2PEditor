#ifndef QSOUNDSDIALOG_H
#define QSOUNDSDIALOG_H

#include <QDialog>
#include "ui_QSoundsDialog.h"

class QSoundsDialog : public QDialog, public Ui::QSoundsDialog
{
	Q_OBJECT

public:
	QSoundsDialog(const std::map<std::string, std::string> &soundMap,
		const std::map<std::string, std::string> &musicMap, QWidget *parent = 0);
	~QSoundsDialog();

private:
	void addSound(QListWidget *l);
	void deleteSound(QListWidget *l);

private slots:
	void on_addSfxButton_clicked();
	void on_deleteSfxButton_clicked();
	void on_addMusicButton_clicked();
	void on_deleteMusicButton_clicked();
	void on_soundList_currentItemChanged();
	void on_musicList_currentItemChanged();
};

#endif // QSOUNDSDIALOG_H
