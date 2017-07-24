#include "QBBDialog.h"
#include <QImageReader>
#include <QLayout>
#include <QPixmap>
#include <qdialogbuttonbox.h>

QBBDialog::QBBDialog(QWidget *parent, QPixmap frame)
: QDialog(parent),
m_frame(frame)
{
	// Label will show one frame of the sprite sheet
	m_label = new QBBLabel(this);
	QPixmap framePixmap(frame);
	m_label->setPixmap(framePixmap);
	
	QGridLayout *layout = new QGridLayout();
	layout->addWidget(m_label, 0, 0, Qt::AlignCenter);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	
	layout->addWidget(buttonBox, 1, 0);
	this->setLayout(layout);
}

QBBDialog::~QBBDialog()
{

}

QRect QBBDialog::getBB()
{
	QRect bb = m_label->getBB();
	// Fix borders if needed
	if (bb.x() < 0) bb.setX(0);
	if (bb.right() > m_frame.width() - 1) bb.setRight(m_frame.width() - 1);
	if (bb.y() < 0) bb.setY(0);
	if (bb.bottom() > m_frame.height() - 1)	bb.setBottom(m_frame.height() - 1);
	// Return bounding box
	return bb;
}