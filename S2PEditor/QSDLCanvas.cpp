#include "QSDLCanvas.h"
#include <QKeyEvent>
#include <qDebug>
#include <QMessageBox>
#include "EditorController.h"
#include "InputHandler.h"

QSDLCanvas::QSDLCanvas(QWidget* Parent) :
QWidget(Parent),
m_Initialized(false)
{
	// We'll make the painting ourselves
	setAttribute(Qt::WA_PaintOnScreen);
	// Set strong focus to enable keyboard events to be received	
	setFocusPolicy(Qt::StrongFocus);
	// The canvas will always have the same size (level size)
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	// Setting timer interval to 0 will make it act as an idle event
	m_UpdateTimer.setInterval(0);
}

bool QSDLCanvas::initEditor(std::string levelName, int width, int height, int tileSize)
{
	if (!m_Initialized)
	{
		// Setup the timer to trigger a refresh at specified framerate
		connect(&m_UpdateTimer, SIGNAL(timeout()), this, SLOT(onUpdate()));
		// Init s2Dp framework and therefore SDL
		if (TheEditor::Instance().init((void*)winId(), levelName, width, height, tileSize))
		{
			m_UpdateTimer.start();
			m_Initialized = true;
			return true;
		}
		else
		{
			// S2P Editor initialization has failed
			QMessageBox::critical(this, "S2PEditor",
				"QSDLCanvas: S2P Editor initialization has failed.");
			return false;
		}
	}
	else
	{
		// S2P Editor can't be initialized twice
		QMessageBox::warning(this, "S2PEditor",
			"QSDLCanvas: S2P Editor has already been initialized.");
		return false;
	}
}

QPaintEngine* QSDLCanvas::paintEngine() const
{
	// We make the paintEvent function return a null paint engine. This functions works together with
	// the WA_PaintOnScreen flag to tell Qt that we're not using any of its built-in paint engines
	return nullptr;
}

void QSDLCanvas::onUpdate()
{
	TheEditor::Instance().update();
}

// Tells the Input Handler that a key has been pressed
void QSDLCanvas::keyPressEvent(QKeyEvent *k)
{
	// qDebug() << "Key pressed: " << QKeySequence(k->key()).toString() << "\n";	
	switch (k->key())
	{
	case Qt::Key_Escape:
		TheInputHandler::Instance().addQKeyState(SDL_SCANCODE_ESCAPE, true);
		break;
	case Qt::Key_Shift:
		TheInputHandler::Instance().addQKeyState(SDL_SCANCODE_LSHIFT, true);
		break;
	default:
		QString qs = QKeySequence(k->key()).toString();
		SDL_Scancode code = SDL_GetScancodeFromName(qs.toStdString().c_str());
		TheInputHandler::Instance().addQKeyState(code, true);
	}
}

// Tells the Input Handler that a key has been released
void QSDLCanvas::keyReleaseEvent(QKeyEvent *k)
{
	 //qDebug() << "Key released: " << QKeySequence(k->key()).toString()<< "\n";
	switch (k->key())
	{
	case Qt::Key_Escape:
		TheInputHandler::Instance().addQKeyState(SDL_SCANCODE_ESCAPE, false);
		break;
	case Qt::Key_Shift:
		TheInputHandler::Instance().addQKeyState(SDL_SCANCODE_LSHIFT, false);
		break;
	default:
		TheInputHandler::Instance().addQKeyState(
			SDL_GetScancodeFromName(QKeySequence(k->key()).toString().toUpper().toStdString().c_str()),
			false);
	}
}

QSize QSDLCanvas::sizeHint() const
{
	return m_sizeHint;
}

void QSDLCanvas::setSizeHint(QSize size)
{
	m_sizeHint = size;
}

//void QSDLCanvas::mousePressEvent(QMouseEvent * event)
//{
//	qDebug() << "Qt mouse input:" << event->x() << "," << event->y() << "\n";
//	qDebug() << "QSDLCanvas Size:" << size();
//	
//	EditorState* editor = dynamic_cast<EditorState*>(TheGame::Instance().getStateMachine()->currentState());
//	if (editor != nullptr)
//	{
//		if (event->button() == Qt::LeftButton)
//		{
//			editor->leftClicked(event->x(), event->y());
//		}
//		else if (event->button() == Qt::RightButton)
//		{
//			editor->rightClicked(event->x(), event->y());
//		}
//	}
//	emit clicked(event->x(), event->y());
//}

//void QSDLCanvas::mouseMoveEvent(QMouseEvent *event)
//{
//	qDebug() << "Qt mouse move:" << event->x() << "," << event->y() << "\n";
//}