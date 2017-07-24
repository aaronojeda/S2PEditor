#include "QAddSoundDialog.h"
#include <QFileDialog>

QAddSoundDialog::QAddSoundDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Guard against pushing OK button with empty fields
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

	// Check if all fields have been filled
	connect(idEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
	connect(sourceEdit, SIGNAL(textChanged(QString)), this, SLOT(checkLineEdits()));
}

QAddSoundDialog::~QAddSoundDialog()
{

}

void QAddSoundDialog::on_browseButton_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Load sound", QString(),
	"Sound files(*.ogg *.mp3 *.wav);;All files(*)");

	if (!fileName.isEmpty())
	{
		sourceEdit->setText(fileName);
	}
}

void QAddSoundDialog::checkLineEdits()
{
	bool ok = !idEdit->text().isEmpty() && !sourceEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QAddSoundDialog::getValues(QString &id, QString &source)
{
	id = idEdit->text();
	source = sourceEdit->text();
}