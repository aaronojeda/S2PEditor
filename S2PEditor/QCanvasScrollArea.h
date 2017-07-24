#ifndef QCANVASSCROLLAREA_H
#define QCANVASSCROLLAREA_H

#include <QScrollArea>

class QCanvasScrollArea : public QScrollArea
{
	Q_OBJECT

public:
	QCanvasScrollArea(QWidget *parent);
	~QCanvasScrollArea();
	void setScrollBarsDisabled(bool disabled);
	// canvas size has changed
	void canvasResized();
private:
	void resizeEvent(QResizeEvent* event);
	void scrollContentsBy(int dx, int dy);

	//void mousePressEvent(QMouseEvent *event);

private slots:
	void hScroll(int);
	void vScroll(int);
};

#endif // QCANVASSCROLLAREA_H
