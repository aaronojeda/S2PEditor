#pragma once

#include <QtWidgets\qwidget.h>
#include <qtimer.h>

class QKeyEvent;

class QSDLCanvas : public QWidget
{
	Q_OBJECT

public:
	QSDLCanvas(QWidget* Parent);
	//QSDLCanvas(QWidget* Parent, const QSize& Size);
	~QSDLCanvas(){}

	// Overrided sizeHint
	virtual QSize sizeHint() const;
	// Set new size hint
	void setSizeHint(QSize size);
	
	// Initialize S2P Editor rendering in this widget window
	bool initEditor(std::string levelName, int width = -1, int height = -1, int tileSize = -1);

private:

	virtual QPaintEngine* paintEngine() const;
	virtual void keyPressEvent(QKeyEvent *k);
	virtual void keyReleaseEvent(QKeyEvent *k);
	//virtual void mousePressEvent(QMouseEvent * event);
	//virtual void mouseMoveEvent(QMouseEvent *event);

	QTimer m_UpdateTimer;
	bool m_Initialized;
	QSize m_sizeHint;

private slots:
	virtual void onUpdate();

signals:
	//void clicked(int x, int y);
};