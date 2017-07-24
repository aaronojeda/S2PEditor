#ifndef QBBLABEL_H
#define QBBLABEL_H

#include <QLabel>

class QBBLabel : public QLabel
{
	Q_OBJECT

public:
	QBBLabel(QWidget *parent);
	~QBBLabel();

	QRect getBB() { return m_bb; }

private:

	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	// Data members
	QRect m_bb;		// Collision bounding box
};

#endif // QBBLABEL_H
