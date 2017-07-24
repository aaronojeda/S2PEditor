#ifndef QADDBCKDIALOG_H
#define QADDBCKDIALOG_H

#include <QDialog>
#include "ui_QAddBckDialog.h"

class QAddBckDialog : public QDialog, public Ui::QAddBckDialog
{
	Q_OBJECT

public:
	QAddBckDialog(QWidget *parent = 0);
	~QAddBckDialog();

private slots:
	void on_newImageButton_clicked();
	void checkEmptyFields();
};

#endif // QADDBCKDIALOG_H
