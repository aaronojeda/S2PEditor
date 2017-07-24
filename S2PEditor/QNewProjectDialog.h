#ifndef QNEWPROJECTDIALOG_H
#define QNEWPROJECTDIALOG_H

#include <QDialog>
#include "ui_QNewProjectDialog.h"

class QNewProjectDialog : public QDialog, public Ui::QNewProjectDialog
{
	Q_OBJECT

public:
	QNewProjectDialog(QWidget *parent = 0);
	~QNewProjectDialog();

	void getValues(QString &projectName, QString &levelName, int &levelWidth,
		int &levelHeight, int &levelTileSize);

private:
	void checkEmptyFields();

private slots:
	void on_projectNameEdit_textChanged();
	void on_levelNameEdit_textChanged();
};

#endif // QNEWPROJECTDIALOG_H
