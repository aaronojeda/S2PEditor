#ifndef QCANVASCONTAINER_H
#define QCANVASCONTAINER_H

#include <QWidget>
#include "QSDLCanvas.h"

class QCanvasContainer : public QWidget
{
	Q_OBJECT

public:
	QCanvasContainer(QSDLCanvas *canvas, QWidget *parent);
	~QCanvasContainer();

	// Set new size hint
	void setSizeHint(QSize size);
	// Overrided sizeHint
	QSize sizeHint() const;

	// To change game width and height if needed
	//void newCanvasSize(QSize size);

private:
	QSize m_sizeHint;
};

#endif // QCANVASCONTAINER_H
