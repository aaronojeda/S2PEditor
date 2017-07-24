#include "QNewProjectDialog.h"
#include <QPushButton>

QNewProjectDialog::QNewProjectDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Guard aggainst pressing ok button with an empty name
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	connect(projectNameEdit, &QLineEdit::textChanged, this, &QNewProjectDialog::checkEmptyFields);
	connect(levelNameEdit, &QLineEdit::textChanged, this, &QNewProjectDialog::checkEmptyFields);
}

QNewProjectDialog::~QNewProjectDialog()
{

}

void QNewProjectDialog::on_projectNameEdit_textChanged()
{

}

void QNewProjectDialog::on_levelNameEdit_textChanged()
{
	bool ok = !levelNameEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QNewProjectDialog::getValues(QString &projectName, QString &levelName, int &levelWidth,
	int &levelHeight, int &levelTileSize)
{
	projectName = projectNameEdit->text();
	levelName = levelNameEdit->text();
	levelWidth = levelWidthSpin->value();
	levelHeight = levelHeightSpin->value();
	levelTileSize = tileSizeSpin->value();
}

void QNewProjectDialog::checkEmptyFields()
{
	bool ok = !levelNameEdit->text().isEmpty() && !projectNameEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}