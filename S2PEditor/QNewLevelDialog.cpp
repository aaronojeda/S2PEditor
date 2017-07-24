#include "QNewLevelDialog.h"
#include <QPushButton>

QNewLevelDialog::QNewLevelDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Guard aggainst pressing ok button with an empty name
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

QNewLevelDialog::~QNewLevelDialog()
{

}

void QNewLevelDialog::on_levelNameEdit_textChanged()
{
	bool ok = !levelNameEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QNewLevelDialog::getValues(QString &levelName, int &levelWidth, int &levelHeight, int &tileSize)
{
	levelName = levelNameEdit->text();
	levelWidth = levelWidthSpin->value();
	levelHeight = levelHeightSpin->value();
	tileSize = tileSizeSpin->value();
}

void QNewLevelDialog::disableCancelButton()
{
	buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
}