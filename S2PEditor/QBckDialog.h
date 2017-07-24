#ifndef QBCKDIALOG_H
#define QBCKDIALOG_H

#include <QDialog>
#include "ui_QBckDialog.h"
#include "EditorParser.h"	// To access GameObjCfg

class QLabel;

class QBckDialog : public QDialog, public Ui::QBckDialog
{
	Q_OBJECT

public:
	QBckDialog(QWidget *parent = 0);
	~QBckDialog();
	std::vector<GameObjCfg> getBcks();

private:
	QLabel *m_image;
	std::vector<GameObjCfg> m_bcks;

private slots:
	void on_bckList_currentItemChanged();
	void on_deleteButton_clicked();
	void on_addButton_clicked();
	void on_upButton_clicked();
	void on_downButton_clicked();
};

#endif // QBCKDIALOG_H
