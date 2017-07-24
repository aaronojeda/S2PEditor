#ifndef QNEWLEVELDIALOG_H
#define QNEWLEVELDIALOG_H

#include <QDialog>
#include "ui_QNewLevelDialog.h"

class QNewLevelDialog : public QDialog, public Ui::QNewLevelDialog
{
	Q_OBJECT

public:
	QNewLevelDialog(QWidget *parent = 0);
	~QNewLevelDialog();

	void disableCancelButton();

public slots:
	void getValues(QString &levelName, int &levelWidth, int &levelHeight, int &tileSize);
private slots:
	void on_levelNameEdit_textChanged();
};

#endif // QNEWLEVELDIALOG_H
