#pragma once

#include <vector>
#include <map>
#include <SDL.h>

class Vector2D;

// An enum attribute to help us with the values of the mouse buttons
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	static InputHandler& Instance()
	{
		static InputHandler s_pInstance;
		return s_pInstance;
	}

	void reset();

	void update();

	void initializeJoysticks();

	bool joysticksInitialized() { return m_bJoysticksInitialized; }

	/* The joy parameter is the identifier (ID) of the joystick we want to use, 
	and the stick is 1 for the left stick and 2 for the right stick. */
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	/* We can grab the current button state with a function that looks up
	the correct button from the correct joystick. */
	bool getButtonState(int joy, int buttonNumber);

	// A function to access our mouse button states.
	bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }

	// Accessor to mouse position
	Vector2D* getMousePosition() { return m_mousePosition; }

	// Functions that check whether a key is down or not
	bool isKeyDown(SDL_Scancode key);
	bool isQKeyDown(SDL_Scancode key);

	std::string* getInputText() { return &m_inputText; }
	void setInputText(std::string text) { m_inputText = text; }
	void setMaxTextLength(int length) { m_maxTextLength = length; }

	void addQKeyState(SDL_Scancode key, bool state);

private:
	InputHandler();
	~InputHandler();

	// Delete the methods we don't want (new in C++ 11)
	InputHandler(const InputHandler&) = delete;
	InputHandler& operator=(const InputHandler&) = delete;

	// Joystick handling
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	const int m_joystickDeadZone = 10000;

	/* An array of Boolean values, so each controller (the first index into the array) 
	will have an array of Boolean values, one for each button on the controller.*/
	std::vector<std::vector<bool>> m_buttonStates;

	// Mouse handling. We declare a one dimensional array, as (almost sure) we won't handle multiple mouse devices.
	std::vector<bool> m_mouseButtonStates;

	// The position variable for our mouse.
	Vector2D* m_mousePosition;

	// A pointer to the array that will be returned from SDL_GetKeyboardState
	const Uint8* m_keystates;
	
	//std::vector<SDL_Scancode> m_keystatesFirst;

	// A string to handle user input
	std::string m_inputText;
	
	// Maximun length for user input text (0 = no length restriction)
	int m_maxTextLength;

	// Private functions to handle different event types

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	void onTextInput(SDL_Event& event);

	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	// handle joysticks events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);
	
	// To check keyboard state in level editor mode with Qt
	std::map<SDL_Scancode, bool> m_QKeyboardState;
};

typedef InputHandler TheInputHandler;
