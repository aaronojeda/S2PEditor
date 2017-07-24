#ifndef QTILESETSCROLLAREA_H
#define QTILESETSCROLLAREA_H

#include <QScrollArea>
#include <QWheelEvent>

class QTilesetScrollArea : public QScrollArea
{
	Q_OBJECT

public:
	QTilesetScrollArea(QWidget *parent);
	~QTilesetScrollArea();

private:
	virtual void wheelEvent(QWheelEvent* event);

signals:
	void zoom(int value);
};

#endif // QTILESETSCROLLAREA_H
