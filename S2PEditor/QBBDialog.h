#ifndef QBBDIALOG_H
#define QBBDIALOG_H

#include <QDialog>
#include "QBBLabel.h"

class QBBDialog : public QDialog
{
	Q_OBJECT

public:
	QBBDialog(QWidget *parent, QPixmap frame);
	~QBBDialog();

	QRect getBB();

private:
	QBBLabel *m_label;
	QPixmap m_frame;
};

#endif // QBBDIALOG_H
