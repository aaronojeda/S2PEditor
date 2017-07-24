#include "QCanvasContainer.h"
#include <QVBoxLayout>

QCanvasContainer::QCanvasContainer(QSDLCanvas *canvas, QWidget *parent)
	: QWidget(parent)
{
	// This widget will contain QSDLCanvas
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(canvas);
	setLayout(layout);
}

QCanvasContainer::~QCanvasContainer()
{

}

QSize QCanvasContainer::sizeHint() const
{
	return m_sizeHint;
}

void QCanvasContainer::setSizeHint(QSize size)
{
	m_sizeHint = size;
}

//void QCanvasContainer::newCanvasSize(QSize size)
//{
//	// INFO: A veces se ejecutarán ambas, ésta y resizeEvent, pero es necesario que estén las dos.
//	if (widget() != nullptr)
//	{
//		int w = std::min(widget()->width(), width());
//		int h = std::min(widget()->height(), height());
//		// Inform editor about new viewable area
//		TheEditor::Instance().setViewArea(w, h);
//	}
//}