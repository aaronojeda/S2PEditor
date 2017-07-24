#include "QAddBckDialog.h"
#include <qDebug>
#include <QMessageBox>
#include "QNewSpriteDialog.h"
#include "EditorController.h"

QAddBckDialog::QAddBckDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	// Load Type range of values
	typeCombo->addItem("ParallaxBck");
	typeCombo->addItem("StaticBck");
	typeCombo->addItem("MovingBck");

	// Load level textures to QComboBox
	for (auto texture : TheEditor::Instance().getTextures())
	{
		imageCombo->addItem(texture.first.c_str());
	}

	// Guard against pushing OK button with empty fields
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	connect(typeCombo, SIGNAL(currentTextChanged(QString)), this, SLOT(checkEmptyFields()));
	connect(imageCombo, SIGNAL(currentTextChanged(QString)), this, SLOT(checkEmptyFields()));
	// To check the first time
	checkEmptyFields();
}

QAddBckDialog::~QAddBckDialog()
{

}

void QAddBckDialog::on_newImageButton_clicked()
{
	QNewSpriteDialog *d = new QNewSpriteDialog(this);
	if (d->exec())
	{
		QString id, source;
		d->getValues(id, source);

		// Load new texture
		auto textures = TheEditor::Instance().getTextures();
		bool loadImage = true;
		if (textures.find(id.toStdString()) != textures.end())
		{
			// There is already an image with the given id
			// Object config already exists. Show dialog to overwrite it or not
			QMessageBox msgBox;
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setText("Texture '" + id + "' already exists.");
			msgBox.setInformativeText("Are you sure you want to overwrite it?");
			// Set message box buttons. Default to 'No'
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if (msgBox.exec() == QMessageBox::No)
			{
				loadImage = false;
			}
		}
		// loadImage is true is the id is new or the user wants to overwrite
		if (loadImage)
		{
			// Overwrite previous texture
			if (TheEditor::Instance().loadTexture(id.toStdString(), source.toStdString()))
			{
				// Add new texture ID to combo box
				imageCombo->addItem(id);
				imageCombo->setCurrentText(id);;
			}
			else
			{
				QMessageBox::critical(this, "S2PEditor",
					"Couldn't load texture with the given image\n");
			}
		}
		
	}


}

void QAddBckDialog::checkEmptyFields()
{
	bool ok = !typeCombo->currentText().isEmpty() && !imageCombo->currentText().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}