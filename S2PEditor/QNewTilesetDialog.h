#ifndef QNewTilesetDialog_H
#define QNewTilesetDialog_H

#include <QDialog>
#include "ui_QNewTilesetDialog.h"
#include <string>

class QNewTilesetDialog : public QDialog, public Ui::QNewTilesetDialog
{
	Q_OBJECT

public:
	QNewTilesetDialog(QWidget *parent = 0);
	~QNewTilesetDialog();
	void getValues(std::string& name, std::string& textureID, int& tileSize, int &margin, int& spacing);

private slots:
	void on_newTextureButton_clicked();
	void checkLineEdits();
	void checkEmptyFields();
};

#endif // QNewTilesetDialog_H
