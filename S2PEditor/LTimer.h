#pragma once

#include <SDL.h>

// Class code extracted from LazyFoo.net tutorials

class LTimer
{
public:
	//Initializes variables
	LTimer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();
	void reset();

	// Gets the timer's ticks
	Uint64 getTicks();
	// Gets the timer's milliseconds
	float getMs();

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint64 mStartTicks;

	//The ticks stored when the timer was paused
	Uint64 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};

