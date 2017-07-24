#include "QObjectsDock.h"
#include <QMessageBox>
#include "EditorController.h"
#include "QNewObjectDialog.h"

QObjectsDock::QObjectsDock(QWidget *parent)
	: QDockWidget(parent)
{
	setupUi(this);
}

QObjectsDock::~QObjectsDock()
{
}

void QObjectsDock::on_nameCombo_currentIndexChanged(QString text)
{
	// Text can be empty if we came from Delete
	if (!text.isEmpty())
	{
		TheEditor::Instance().setObject(text.toStdString());
	}
	else
	{
		// No more object configs in combo box. If we don't clear the object,
		// left click on canvas will still add previous object.
		TheEditor::Instance().clearObject();
	}
}

// Load current project objects, clearing previous ones
void QObjectsDock::update()
{
	loadObjects(TheEditor::Instance().getObjectCfgs());
}

// Clear objects combobox and load new objects in 'objects' map
void QObjectsDock::loadObjects(const std::map<std::string, GameObjCfg> &objects)
{
	// Clear combo box's previous data
	nameCombo->clear();
	// update combo box
	for (auto obj : objects)
	{
		nameCombo->addItem(QString::fromStdString(obj.first));
	}
}

void QObjectsDock::clear()
{
	nameCombo->clear();
}

void QObjectsDock::on_leftRightButton_clicked()
{
	createObject(new QNewObjectDialog("LeftRight", this));
}

void QObjectsDock::on_flyingButton_clicked()
{
	createObject(new QNewObjectDialog("Flying", this));
}

void QObjectsDock::on_playerButton_clicked()
{
	createObject(new QNewObjectDialog("Player", this));
}

void QObjectsDock::on_chaserButton_clicked()
{
	createObject(new QNewObjectDialog("Chaser", this));
}

void QObjectsDock::on_flyingChaserButton_clicked()
{
	createObject(new QNewObjectDialog("FlyingChaser", this));
}

void QObjectsDock::on_scoreItemButton_clicked()
{
	createObject(new QNewObjectDialog("ScoreItem", this));
}

void QObjectsDock::on_healthItemButton_clicked()
{
	createObject(new QNewObjectDialog("HealthItem", this));
}

void QObjectsDock::on_livesItemButton_clicked()
{
	createObject(new QNewObjectDialog("LivesItem", this));
}

void QObjectsDock::on_keyItemButton_clicked()
{
	createObject(new QNewObjectDialog("KeyItem", this));
}

void QObjectsDock::on_lockedDoorButton_clicked()
{
	createObject(new QNewObjectDialog("LockedDoor", this));
}

void QObjectsDock::on_levelFinishButton_clicked()
{
	createObject(new QNewObjectDialog("LevelFinish", this));
}

void QObjectsDock::on_checkPointButton_clicked()
{
	createObject(new QNewObjectDialog("CheckPoint", this));
}

void QObjectsDock::createObject(QNewObjectDialog* d)
{
	// Create object configuration with the values of the dialog
	if (d->exec())
	{
		// Get new object attributes
		GameObjCfg object = d->getValues();

		auto objCfgs = TheEditor::Instance().getObjectCfgs();
		// Add object to inserted objects (if new) and make current
		if (objCfgs.find(object.name) == objCfgs.end())
		{
			// The object config name is new, so we add it to map and make it current
			TheEditor::Instance().addObjCfg(d->nameEdit->text().toStdString(), object);
			nameCombo->addItem(d->nameEdit->text());
		}
		else
		{
			// Object config already exists. Show dialog to overwrite it or not
			QMessageBox msgBox;
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.setText("Object " + d->nameEdit->text() + " already exists.");
			msgBox.setInformativeText("Are you sure you want to overwrite it?");
			// Set message box buttons. Default to 'No'
			msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
			msgBox.setDefaultButton(QMessageBox::No);
			if (msgBox.exec() == QMessageBox::Yes)
			{
				// Overwrite previous object config
				TheEditor::Instance().addObjCfg(object.name, object);
			}
		}
		// Make new (or overwritten) config current and report Editor
		nameCombo->setCurrentText(d->nameEdit->text());
		TheEditor::Instance().setObject(object.name);
	}
}

void QObjectsDock::on_editButton_clicked()
{
	// Check if any configuration is selected
	if (!nameCombo->currentText().isEmpty())
	{
		// Create dialog with object values
		auto objCfgs = TheEditor::Instance().getObjectCfgs();
		auto obj = objCfgs.at(nameCombo->currentText().toStdString());
		QNewObjectDialog *d = new QNewObjectDialog(QString::fromStdString(obj.type), this);
		d->setWindowTitle("Edit object");
		d->setValues(obj);
		// Create edited object config the usual way
		createObject(d);
	}
}

void QObjectsDock::on_deleteButton_clicked()
{
	// Delete selected object configuration
	if (!nameCombo->currentText().isEmpty())
	{
		// Ask for confirmation
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.setText("Configuration '" + nameCombo->currentText() + "' will be deleted.");
		msgBox.setInformativeText("Are you sure you want to permanently delete it?\n");
		// Set message box buttons. Default to 'No'
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		if (msgBox.exec() == QMessageBox::Yes)
		{
			// If the user confirms, delete object from std::map and combo box
			TheEditor::Instance().deleteObjCfg(nameCombo->currentText().toStdString());
			nameCombo->removeItem(nameCombo->currentIndex());
		}
	}
}

QString QObjectsDock::currentObject()
{
	return nameCombo->currentText();
}
