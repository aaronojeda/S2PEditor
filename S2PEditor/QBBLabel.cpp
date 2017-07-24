#include "QBBLabel.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

QBBLabel::QBBLabel(QWidget *parent)
: QLabel(parent),
m_bb{0, 0, 0, 0}
{
	// set background darker than the parent widget, to see where the image starts and ends
	setAutoFillBackground(true);
	setBackgroundRole(QPalette::Dark);
}

QBBLabel::~QBBLabel()
{

}

void QBBLabel::paintEvent(QPaintEvent *e)
{
	QLabel::paintEvent(e);

	QPainter painter(this);
	painter.setPen(QPen(Qt::red));
	painter.drawRect(m_bb);
}

void QBBLabel::mousePressEvent(QMouseEvent *event)
{
	m_bb.setX(event->x());
	m_bb.setY(event->y());
	m_bb.setWidth(0);
	m_bb.setHeight(0);
	update();
}

void QBBLabel::mouseReleaseEvent(QMouseEvent *event)
{
	int aux;
	// Check if user started from right
	if (m_bb.width() < 0)
	{
		// setX may change the width, so we use an auxiliar variable
		aux = m_bb.width() * -1;
		m_bb.setX(event->x());
		m_bb.setWidth(aux);
	}
	// Check if user started from bottom
	if (m_bb.height() < 0)
	{
		aux = m_bb.height() * -1;
		m_bb.setY(event->y());
		m_bb.setHeight(aux);
	}

	update();
}

void QBBLabel::mouseMoveEvent(QMouseEvent *event)
{
	// Update bounding box size
	m_bb.setWidth(event->x() - m_bb.x());
	m_bb.setHeight(event->y() - m_bb.y());
	update();
}