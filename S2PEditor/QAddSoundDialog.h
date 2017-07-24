#ifndef QADDSOUNDDIALOG_H
#define QADDSOUNDDIALOG_H

#include <QDialog>
#include "ui_QAddSoundDialog.h"

class QAddSoundDialog : public QDialog, public Ui::QAddSoundDialog
{
	Q_OBJECT

public:
	QAddSoundDialog(QWidget *parent = 0);
	~QAddSoundDialog();

public slots:
	void getValues(QString& id, QString &source);

private slots:
	void on_browseButton_clicked();
	void checkLineEdits();
};

#endif // QADDSOUNDDIALOG_H
