#include "InputHandler.h"
#include <iostream>
#include "Game.h"
#include "Vector2D.h"

InputHandler::InputHandler() : 
m_keystates(nullptr),
m_bJoysticksInitialized(false),
m_mousePosition(new Vector2D(0, 0)),
m_inputText(""),
m_maxTextLength(0)
{
	// We push our three mouse button states (defaulted to false) into the array
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

InputHandler::~InputHandler()
{
	// delete anything we created dynamically
	delete m_mousePosition;

	// loop through our SDL_Joystick* array and call SDL_JoystickClose on each iteration
	if (m_bJoysticksInitialized)
	{
		for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}

	// clear our arrays
	m_joystickValues.clear();
	m_joysticks.clear();
	m_buttonStates.clear();
	m_mouseButtonStates.clear();
}

void InputHandler::initializeJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			
			if (joy) // SDL_JoystickOpen(i) returns NULL if an error ocurred.
			{
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0))); // add our pair

				std::vector<bool> tempButtons;

				/* We use SDL_JoystickNumButtons to get the number of buttons for each of our joysticks.*/
				for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					/* We then push a value for each of these buttons into an array. We push false to start,
					as no buttons are pressed. */
					tempButtons.push_back(false);
				}

				/*This array is then pushed into our m_buttonStates array to be used with the getButtonState function.*/
				m_buttonStates.push_back(tempButtons);
			}
			else
			{
				std::cout << SDL_GetError();
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialized = true;

		std::cout << "Initialized " << m_joysticks.size() << " joystick(s)";
	}
	else
	{
		m_bJoysticksInitialized = false;
	}
}

void InputHandler::reset()
{
	m_mouseButtonStates[LEFT] = false;
	m_mouseButtonStates[RIGHT] = false;
	m_mouseButtonStates[MIDDLE] = false;
}

/* The update function will be called in each frame in the main game loop to
update the event state. */
void InputHandler::update()
{
	SDL_Event event;

	/* We pass in the event from the event loop into each function (apart from keys) so that
	we can handle them accordingly.*/
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance().quit();
			break;

		case SDL_JOYAXISMOTION:
			onJoystickAxisMove(event);
			break;

		case SDL_JOYBUTTONDOWN:
			onJoystickButtonDown(event);
			break;

		case SDL_JOYBUTTONUP:
			onJoystickButtonUp(event);
			break;

		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;

		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;

		case SDL_KEYDOWN:
			onKeyDown();
			break;

		case SDL_KEYUP:
			onKeyUp();
			break;

		case SDL_TEXTINPUT:
			onTextInput(event);
			break;

		default:
			break;
		}
	}
}

void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(NULL);
}

void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(NULL);
}

void InputHandler::onTextInput(SDL_Event& event)
{
	if ( (m_maxTextLength == 0) || (m_inputText.size() < m_maxTextLength) )
	{
		m_inputText += event.text.text;
	}
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePosition->x(event.motion.x);
	m_mousePosition->y(event.motion.y);
}

void InputHandler::onJoystickAxisMove(SDL_Event& event)
{
	int whichOne = event.jaxis.which; // get which controller
				
	// left stick move left or right
	if (event.jaxis.axis == 0)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->x(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->x(-1);
		}
		else
		{
			m_joystickValues[whichOne].first->x(0);
		}
	}
				
	// left stick move up or down
	if (event.jaxis.axis == 1)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->y(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].first->y(-1);
		}
		else
		{
			m_joystickValues[whichOne].first->y(0);
		}
	}
				
	// right stick move left or right
	if (event.jaxis.axis == 3)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->x(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->x(-1);
		}
		else
		{
			m_joystickValues[whichOne].second->x(0);
		}
	}
				
	// right stick move up or down
	if (event.jaxis.axis == 4)
	{
		if (event.jaxis.value > m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->y(1);
		}
		else if (event.jaxis.value < -m_joystickDeadZone)
		{
			m_joystickValues[whichOne].second->y(-1);
		}
		else
		{
			m_joystickValues[whichOne].second->y(0);
		}
	}
}

void InputHandler::onJoystickButtonDown(SDL_Event& event)
{
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event& event)
{
	int whichOne = event.jaxis.which;
	m_buttonStates[whichOne][event.jbutton.button] = false;
}

int InputHandler::xvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->x();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->x();
		}
	}
	return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->y();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->y();
		}
	}
	return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
	return m_buttonStates[joy][buttonNumber];
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	switch (TheGame::Instance().getMode())
	{
	case MODE_QT:
		return m_QKeyboardState[key];
		break;
	default:
	case MODE_GAME:
		if (m_keystates != 0)
		{
			return m_keystates[key];
		}
		else
		{
			return false;
		}
	}
}

void InputHandler::addQKeyState(SDL_Scancode key, bool state)
{
	// true = pressed; false = released
	m_QKeyboardState[key] = state;
}