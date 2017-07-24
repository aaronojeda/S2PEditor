#include "QNewObjectDialog.h"
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QMessageBox>
#include "EditorController.h"
#include "QBBDialog.h"
#include "QNewSpriteDialog.h"
#include "QAddSoundDialog.h"

using namespace std;

QNewObjectDialog::QNewObjectDialog(const QString &type, QWidget *parent)
: QDialog(parent),
m_animTable{ new QTableWidget(this) }
{
	setupUi(this);

	// Set object type
	typeEdit->setText(type);

	// Set spriteSheet label as scroll area widget
	m_ssLabel = new QLabel(this);
	spriteSheetSArea->setWidget(m_ssLabel);

	// Load project textures to QComboBox
	for (auto texture : TheEditor::Instance().getTextures())
	{
		spriteCombo->addItem(texture.first.c_str());
	}

	// Load sound effects to comboBox
	for (auto sfx : TheEditor::Instance().getSfxs())
	{
		soundCombo->addItem(sfx.first.c_str());
		sound2Combo->addItem(sfx.first.c_str());
	}
	// Let the user leave the box empty
	soundCombo->addItem("");
	sound2Combo->addItem("");

	// Change special values and sounds depending on type
	setSpValues(type);
	
	// Setup animation table and add it to the layout
	setupAnimTable(type);
	QVBoxLayout *animLayout = new QVBoxLayout();
	animLayout->addWidget(m_animTable);
	m_animBox->setLayout(animLayout);

	// Guard against pushing OK button with empty fields
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
	connect(nameEdit, SIGNAL(textChanged(QString)), this, SLOT(checkEmptyFields()));
	connect(spriteCombo, SIGNAL(currentTextChanged(QString)), this, SLOT(checkEmptyFields()));
}

QNewObjectDialog::~QNewObjectDialog()
{
}

void QNewObjectDialog::on_drawButton_clicked()
{
	map<string, string> textures = TheEditor::Instance().getTextures();
	if (textures.find(spriteCombo->currentText().toStdString()) != textures.end())
	{
		QPixmap spriteSheet(textures[spriteCombo->currentText().toStdString()].c_str());
		// Crop first frame of the sprite sheet
		QRect firstFrame(0, 0, widthSpin->value(), heightSpin->value());
		QBBDialog *d = new QBBDialog(this, spriteSheet.copy(firstFrame));
		if (d->exec())
		{
			// Bounding box rectangle
			QRect bb = d->getBB();
			xBSpin->setValue(bb.x());
			yBSpin->setValue(bb.y());
			wBSpin->setValue(bb.width());
			hBSpin->setValue(bb.height());
		}
	}
	else
	{
		// Inform the user that a texture ID has to be selected to draw the collider
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setText("Sprite has not been selected.");
		msgBox.setInformativeText("You have to select a texture ID for the object\n"
			"in order to draw the bounding box.");
		msgBox.exec();
	}
}

void QNewObjectDialog::on_newSpriteButton_clicked()
{
	QNewSpriteDialog *d = new QNewSpriteDialog(this);
	if (d->exec())
	{
		QString id, source;
		d->getValues(id, source);

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
				// Add new texture ID to combo box
				spriteCombo->addItem(id);
				spriteCombo->setCurrentText(id);;
			}
			else
			{
				qDebug() << "Can't load texture with the given image.";
			}
		}
	}
}

void QNewObjectDialog::on_newSoundButton_clicked()
{
	QAddSoundDialog *d = new QAddSoundDialog(this);
	if (d->exec())
	{
		QString id, source;
		d->getValues(id, source);

		// Check if sound with given id exists
		auto soundList = TheEditor::Instance().getSfxs();
		if (soundList.find(id.toStdString()) != soundList.end())
		{
			QMessageBox::warning(this, "S2PEditor",
				"There is already a sound with that ID.");
		}
		else
		{
			// Load new sound effect
			if (TheEditor::Instance().loadSfx(id.toStdString(), source.toStdString()))
			{
				// Add new sound ID to combo boxes
				soundCombo->addItem(id);
				sound2Combo->addItem(id);
			}
		}
	}
}


GameObjCfg QNewObjectDialog::getValues()
{
	GameObjCfg object;
	object.name = nameEdit->text().toStdString();
	object.type = typeEdit->text().toStdString();
	object.textureID = spriteCombo->currentText().toStdString();
	object.frameHeight = heightSpin->value();
	object.frameWidth = widthSpin->value();
	object.xSpeed = xSpeedSpin->value();
	object.ySpeed = ySpeedSpin->value();
	object.value = valueSpin->value();
	object.value2 = value2Spin->value();
	object.value3 = value3Spin->value();
	object.collider = { xBSpin->value(), yBSpin->value(), wBSpin->value(), hBSpin->value() };
	object.soundID = soundCombo->currentText().toStdString();
	object.sound2ID = sound2Combo->currentText().toStdString();

	// Store animation names depending on type
	vector<string> animNames;
	if (object.type == "LeftRight" || object.type == "Flying" ||
		object.type == "Chaser" || object.type == "FlyingChaser")
	{
		animNames.push_back("idle");
		animNames.push_back("walk");
	}
	else if (object.type == "Player")
	{
		animNames.push_back("idle");
		animNames.push_back("walk");
		animNames.push_back("jump");
		animNames.push_back("death");
	}
	else if (object.type == "ScoreItem" || object.type == "HealthItem" || 
		object.type == "LivesItem" || object.type == "KeyItem" ||
		object.type == "LockedDoor" || object.type == "LevelFinish" ||
		object.type == "CheckPoint")
	{
		animNames.push_back("idle");
	}

	// Fill object animations
	for (auto i = 0; i < animNames.size(); i++)
	{
		QAnimStruct currentAnim;
		currentAnim.row = qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_ROW))->value();
		currentAnim.nFrames = qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_NFRAMES))->value();
		currentAnim.frameTime = qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_FRAMETIME))->value();
		object.animations.insert({ animNames[i], currentAnim });
	}

	return object;
}

void QNewObjectDialog::setValues(GameObjCfg cfg)
{
	// Fill the dialog with the attributes of the object config
	nameEdit->setText(cfg.name.c_str());
	typeEdit->setText(cfg.type.c_str());
	spriteCombo->setCurrentText(cfg.textureID.c_str());
	widthSpin->setValue(cfg.frameWidth);
	heightSpin->setValue(cfg.frameHeight);
	xBSpin->setValue(cfg.collider.x);
	yBSpin->setValue(cfg.collider.y);
	wBSpin->setValue(cfg.collider.w);
	hBSpin->setValue(cfg.collider.h);
	xSpeedSpin->setValue(cfg.xSpeed);
	ySpeedSpin->setValue(cfg.ySpeed);
	valueSpin->setValue(cfg.value);
	value2Spin->setValue(cfg.value2);
	value3Spin->setValue(cfg.value3);
	soundCombo->setCurrentText(cfg.soundID.c_str());
	sound2Combo->setCurrentText(cfg.sound2ID.c_str());
	// Store animation names depending on type
	vector<string> animNames;
	if (cfg.type == "LeftRight" || cfg.type == "Flying"	|| 
		cfg.type == "Chaser" || cfg.type == "FlyingChaser")
	{
		animNames.push_back("idle");
		animNames.push_back("walk");
	}
	else if (cfg.type == "Player")
	{
		animNames.push_back("idle");
		animNames.push_back("walk");
		animNames.push_back("jump");
		animNames.push_back("death");
	}
	else if (cfg.type == "ScoreItem" || cfg.type == "HealthItem"
		|| cfg.type == "LivesItem" || cfg.type == "KeyItem"
		|| cfg.type == "LockedDoor" || cfg.type == "LevelFinish"
		|| cfg.type == "CheckPoint")
	{
		animNames.push_back("idle");
	}

	// Fill animation table
	for (auto i = 0; i < animNames.size(); i++)
	{
		QAnimStruct anim = cfg.animations[animNames[i]];
		qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_ROW))->setValue(anim.row);
		qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_NFRAMES))->setValue(anim.nFrames);
		qobject_cast<QSpinBox*>(m_animTable->cellWidget(i, COLUMN_FRAMETIME))->setValue(anim.frameTime);
	}
}

void QNewObjectDialog::setupAnimTable(QString type)
{
	vector<string> animations;

	// Get animations depending on type
	if (type == "LeftRight" || type == "Flying" ||
		type == "Chaser" || type == "FlyingChaser")
	{
		animations.push_back("Idle");
		animations.push_back("Walk");
	}
	else if (type == "Player")
	{
		animations.push_back("Idle");
		animations.push_back("Walk");
		animations.push_back("Jump");
		animations.push_back("Death");
	}
	else if (type == "ScoreItem" || type == "HealthItem" 
		|| type == "LivesItem" || type == "KeyItem"
		|| type == "LockedDoor" || type == "LevelFinish"
		|| type == "CheckPoint")
	{
		animations.push_back("Idle");
	}

	// Create animation table with appropriate size
	m_animTable->setRowCount(animations.size());
	m_animTable->setColumnCount(COLUMN_NCOLUMNS);

	// Fill column headers
	m_animTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Row"));
	m_animTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Number"));
	m_animTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Speed"));
	// Fill table rows (i.e. animations) and columns (i.e. animation parameters)
	for (auto i = 0; i < animations.size(); i++)
	{
		// Add animation row
		m_animTable->setVerticalHeaderItem(i, new QTableWidgetItem(animations[i].c_str()));
		// Add animation parameters
		QSpinBox *rowBox = new QSpinBox(m_animTable);			// row
		QSpinBox *nFramesBox = new QSpinBox(m_animTable);		// number of frames
		nFramesBox->setMinimum(1);
		nFramesBox->setMaximum(999);
		QSpinBox *frameTimeBox = new QSpinBox(m_animTable);	// interval between frames
		frameTimeBox->setMaximum(99999);
		m_animTable->setCellWidget(i, COLUMN_ROW, rowBox);
		m_animTable->setCellWidget(i, COLUMN_NFRAMES, nFramesBox);
		m_animTable->setCellWidget(i, COLUMN_FRAMETIME, frameTimeBox);
	}
}

void QNewObjectDialog::checkEmptyFields()
{
	bool ok = !nameEdit->text().isEmpty() && !spriteCombo->currentText().isEmpty();
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void QNewObjectDialog::on_spriteCombo_currentIndexChanged(QString textureID)
{
	// Get width and height of the new selected texture
	int textureWidth = TheEditor::Instance().getTextureWidth(textureID.toStdString());
	int textureHeight = TheEditor::Instance().getTextureHeight(textureID.toStdString());
	// Fill frame width, height and collider with default values equals to image size
	widthSpin->setValue(textureWidth);
	heightSpin->setValue(textureHeight);
	// xBSpin and yBSpin are already 0 so we only change wB and hB
	wBSpin->setValue(textureWidth);
	hBSpin->setValue(textureHeight);
	// Show new sprite sheet 
	string spriteSource = TheEditor::Instance().getTextures().at(textureID.toStdString());
	QPixmap pixmap(QString::fromStdString(spriteSource));
	m_ssLabel->setPixmap(pixmap);
}

void QNewObjectDialog::setSpValues(QString type)
{
	QString spValue, spValue2, spValue3, spSound, spSound2;
	// Make all widgets invisible initially
	xSpeedLabel->setVisible(false);
	xSpeedSpin->setVisible(false);
	ySpeedLabel->setVisible(false);
	ySpeedSpin->setVisible(false);
	value2Label->setVisible(false);
	value2Spin->setVisible(false);
	value3Label->setVisible(false);
	value3Spin->setVisible(false);
	sound2Label->setVisible(false);
	sound2Combo->setVisible(false);
	// make visible certain widgets depending on type and change labels' text
	if (type == "Player")
	{
		xSpeedLabel->setVisible(true);
		xSpeedSpin->setVisible(true);
		ySpeedLabel->setVisible(true);
		ySpeedSpin->setVisible(true);
		value2Label->setVisible(true);
		value2Spin->setVisible(true);
		value3Label->setVisible(true);
		value3Spin->setVisible(true);
		sound2Label->setVisible(true);
		sound2Combo->setVisible(true);
		spValue = "Invincible";
		spValue2 = "Jump height";
		spValue3 = "Jump speed";
		spSound = "Death";
		spSound2 = "Jump";

	}
	// Enemies
	else if (type == "LeftRight" || type == "Flying" ||
		type == "Chaser" || type == "FlyingChaser")	
	{
		xSpeedLabel->setVisible(true);
		xSpeedSpin->setVisible(true);
		ySpeedLabel->setVisible(true);
		ySpeedSpin->setVisible(true);
		value2Label->setVisible(true);
		value2Spin->setVisible(true);
		sound2Label->setVisible(true);
		sound2Combo->setVisible(true);
		spValue = "Damage";
		spValue2 = "Health";
		spSound = "Hurt";
		spSound2 = "Attack";
		// If is a chaser enemy, add distance radius
		if (type == "Chaser" || type == "FlyingChaser")
		{
			value3Label->setVisible(true);
			value3Spin->setVisible(true);
			spValue3 = "Radius";
		}
	}
	// Items & doors
	else if (type == "ScoreItem" || type == "HealthItem" ||
		type == "LivesItem" || type == "KeyItem" || type == "LockedDoor")
	{
		spSound = "Pick";
		if (type == "ScoreItem")
		{
			spValue = "Score";
		}
		else if (type == "HealthItem")
		{
			spValue = "Health";
		}
		else if (type == "LivesItem")
		{
			spValue = "Lives";
		}
		else if (type == "KeyItem")
		{
			spValue = "Keys";
		}
		else if (type == "LockedDoor")
		{
			spValue = "Keys";
			spSound = "Open";
		}
	}
	// CheckPoint & EOL
	else if (type == "LevelFinish" || type == "CheckPoint")
	{
		valueGroupBox->setVisible(false);
		spSound = "Reached";
	}

	// Set each label's text depending on type
	valueLabel->setText(spValue);
	value2Label->setText(spValue2);
	value3Label->setText(spValue3);
	soundLabel->setText(spSound);
	sound2Label->setText(spSound2);
}