#ifndef QNEWSPRITEDIALOG_H
#define QNEWSPRITEDIALOG_H

#include <QDialog>
#include "ui_QNewSpriteDialog.h"
#include <QString>

class QNewSpriteDialog : public QDialog, public Ui::QNewSpriteDialog
{
	Q_OBJECT

public:
	QNewSpriteDialog(QWidget *parent = 0);
	~QNewSpriteDialog();

public slots:
	void getValues(QString& id, QString &source);

private slots:
	void on_browseButton_clicked();
	void checkLineEdits();
};

#endif // QNEWSPRITEDIALOG_H
