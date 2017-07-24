#include "QCanvasScrollArea.h"
#include <qdebug.h>
#include <QScrollBar>
#include <algorithm>
#include "EditorController.h"
#include "QSDLCanvas.h"
#include "qevent.h"

QCanvasScrollArea::QCanvasScrollArea(QWidget *parent)
	: QScrollArea(parent)
{
	QScrollBar* h = horizontalScrollBar();
	QScrollBar* v = verticalScrollBar();

	// Conections
	connect(h, &QScrollBar::valueChanged, this, &QCanvasScrollArea::hScroll);
	connect(v, &QScrollBar::valueChanged, this, &QCanvasScrollArea::vScroll);
}

QCanvasScrollArea::~QCanvasScrollArea()
{
}

void QCanvasScrollArea::resizeEvent(QResizeEvent* event)
{
	// If the scroll area contains a widget, resize it and report the Editor
	if (widget() != nullptr)
	{
		int w = std::min(widget()->width(), width());
		int h = std::min(widget()->height(), height());
		// Inform editor about new viewable area and re-calculate parallax bck scroll
		TheEditor::Instance().setViewArea(w, h);
		TheEditor::Instance().updateBckScroll();
	}

	horizontalScrollBar()->setValue(0);
	verticalScrollBar()->setValue(0);

	auto osize = event->oldSize();

	QScrollArea::resizeEvent(event);
}

// Update camera position when horizontal scroll occurs
void QCanvasScrollArea::hScroll(int value)
{
	TheEditor::Instance().hScroll(value);
}

// Update camera position when vertical scroll occurs
void QCanvasScrollArea::vScroll(int value)
{
	TheEditor::Instance().vScroll(value);
}

// We disable automatic scrolling (do nothing), because we are updating camera position ourselves.
void QCanvasScrollArea::scrollContentsBy(int dx, int dy)
{
}

void QCanvasScrollArea::setScrollBarsDisabled(bool disabled)
{
	horizontalScrollBar()->setDisabled(disabled);
	verticalScrollBar()->setDisabled(disabled);
}

void QCanvasScrollArea::canvasResized()
{
	// In the resizeEvent we do the changes we need, so we force one
	auto event = new QResizeEvent(this->size(), this->size());
	resizeEvent(event);
}