#include "QTilesetScrollArea.h"
#include "qstackedwidget.h"

QTilesetScrollArea::QTilesetScrollArea(QWidget *parent)
	: QScrollArea(parent)
{
}

QTilesetScrollArea::~QTilesetScrollArea()
{

}

void QTilesetScrollArea::wheelEvent(QWheelEvent* event)
{
	if (event->modifiers() & Qt::ControlModifier)
	{
		QPoint numDegrees = event->angleDelta() / 8;

		if (!numDegrees.isNull())
		{
			QPoint numSteps = numDegrees / 15;
			emit zoom(numSteps.y());
		}
	}
	else
	{
		QScrollArea::wheelEvent(event);
	}
}
