#include "QNewSpriteDialog.h"
#include <QFileDialog>

QNewSpriteDialog::QNewSpriteDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Guard against pushing OK button with empty fields
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

	// Check if all fields have been filled
	connect(idEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
	connect(sourceEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
}

QNewSpriteDialog::~QNewSpriteDialog()
{

}

void QNewSpriteDialog::on_browseButton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Load image", QString(),
		"Picture Files (*.png)");

	if (!fileName.isEmpty())
	{
		sourceEdit->setText(fileName);
	}
}

void QNewSpriteDialog::checkLineEdits()
{
	bool ok = !idEdit->text().isEmpty() && !sourceEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QNewSpriteDialog::getValues(QString &id, QString &source)
{
	id = idEdit->text();
	source = sourceEdit->text();
}