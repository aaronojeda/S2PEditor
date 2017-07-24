#ifndef QTEXTURESDIALOG_H
#define QTEXTURESDIALOG_H

#include <QDialog>
#include "ui_QTexturesDialog.h"
#include <string>

class QTexturesDialog : public QDialog, public Ui::QTexturesDialog
{
	Q_OBJECT

public:
	// textureMap <id, source>
	QTexturesDialog(const std::map<std::string, std::string> &textureMap, QWidget *parent = 0);
	~QTexturesDialog();

private:
	QLabel *m_image;

private slots:
	void on_addButton_clicked();
	void on_deleteButton_clicked();
	void on_textureList_currentItemChanged();
};

#endif // QTEXTURESDIALOG_H
