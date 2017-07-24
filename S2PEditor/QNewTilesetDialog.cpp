#include "QNewTilesetDialog.h"
#include <QFileDialog>
#include <QImageReader>
#include <QDebug>
#include <QMessageBox>
#include "QNewSpriteDialog.h"
#include "EditorController.h"


using namespace std;

QNewTilesetDialog::QNewTilesetDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Load level textures to QComboBox
	for (auto texture : TheEditor::Instance().getTextures())
	{
		textureIDCombo->addItem(texture.first.c_str());
	}

	// Guard against pushing OK button with empty fields
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	connect(nameEdit, SIGNAL(textChanged(QString)), this, SLOT(checkEmptyFields()));
	connect(textureIDCombo, SIGNAL(currentTextChanged(QString)), this, SLOT(checkEmptyFields()));
}

QNewTilesetDialog::~QNewTilesetDialog()
{

}

void QNewTilesetDialog::getValues(string& name, string& textureID, int& tileSize, int& margin, int& spacing)
{
	name = nameEdit->text().toStdString();
	textureID = textureIDCombo->currentText().toStdString();
	tileSize = sizeSpin->value();
	margin = marginSpin->value();
	spacing = spacingSpin->value();
}

void QNewTilesetDialog::on_newTextureButton_clicked()
{
	QNewSpriteDialog *d = new QNewSpriteDialog(this);
	if (d->exec())
	{
		QString id, source;
		d->getValues(id, source);

		// Check if there is already a texture with that name
		auto textureList = TheEditor::Instance().getTextures();
		if (textureList.find(id.toStdString()) != textureList.end())
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a texture with that ID.");
		}
		else
		{
			// Load new texture
			if (TheEditor::Instance().loadTexture(id.toStdString(), source.toStdString()))
			{
				// Add new texture ID to line edit and combo box
				textureIDCombo->addItem(id);
				textureIDCombo->setCurrentText(id);;
			}
			else
			{
				qDebug() << "Can't load texture with the given image.";
			}
		}
	}
}

void QNewTilesetDialog::checkLineEdits()
{
	bool ok = !nameEdit->text().isEmpty();
	//bool ok = !nameEdit->text().isEmpty() && !sourceEdit->text().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QNewTilesetDialog::checkEmptyFields()
{
	bool ok = !nameEdit->text().isEmpty() && !textureIDCombo->currentText().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}