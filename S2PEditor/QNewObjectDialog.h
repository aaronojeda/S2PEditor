#ifndef QNEWOBJECTDIALOG_H
#define QNEWOBJECTDIALOG_H

#include <QDialog>
#include "ui_QNewObjectDialog.h"
#include <QString>
#include "EditorParser.h"

class QTableWidget;

enum animTableColumn
{
	COLUMN_ROW,
	COLUMN_NFRAMES,
	COLUMN_FRAMETIME,
	COLUMN_NCOLUMNS = 3
};

enum animTableRow
{
	ROW_WALK,
	ROW_JUMP,
	ROW_DEATH,
	ROW_SHOOT,
	ROW_IDLE,
};

class QNewObjectDialog : public QDialog, public Ui::QNewObjectDialog
{
	Q_OBJECT
public:
	QNewObjectDialog(const QString &type, QWidget *parent = nullptr);
	~QNewObjectDialog();

public slots:
	GameObjCfg getValues();
	void setValues(GameObjCfg cfg);
	
private:
	QTableWidget* m_animTable{ nullptr };
	QString m_type;
	// Label to show selected sprite sheet
	QLabel* m_ssLabel;
	void setupAnimTable(QString type);
	void setSpValues(QString type);

private slots:
	// Automatically fills frame width, height and collider
	void on_spriteCombo_currentIndexChanged(QString);
	// GUI for definig frame bounding box
	void on_drawButton_clicked();
	// Open dialog for new texture addition
	void on_newSpriteButton_clicked();
	// Checks if mandatory fields have been filled
	void checkEmptyFields();
	// Open dialog for new sfxs
	void on_newSoundButton_clicked();
};

#endif // QNEWOBJECTDIALOG_H
