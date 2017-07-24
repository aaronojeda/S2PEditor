#ifndef __LoaderParams__
#define __LoaderParams__

#include <string>
#include <map>
#include "Animation.h"

class LoaderParams
{
public:
	LoaderParams(int x, int y, int xSpeed, int ySpeed, 
		std::map<std::string, Animation> animations, int value = 0, 
		std::string soundID = "", std::string sound2ID = "", 
		int value2 = 0, int value3 = 0);

	// Getters used by GameObject constructors
	int getX() const;
	int getY() const;
	int getXSpeed() const;
	int getYSpeed() const;
	int getValue() const;
	int getValue2() const;
	int getValue3() const;
	void getValues(int &v, int &v2, int &v3) const;
	std::map<std::string, Animation> getAnimations() const;
	//int getJumpSpeed() const;
	//int getJumpHeight() const;
	std::string getSoundID() const;
	std::string getSound2ID() const;

private:
	int m_x;
	int m_y;
	int m_xSpeed;
	int m_ySpeed;
	int m_value;
	int m_value2;
	int m_value3;
	std::map<std::string, Animation> m_animations;
	//int m_jumpHeight;
	//int m_jumpSpeed;
	std::string m_soundID;
	std::string m_sound2ID;
};

#endif /* defined(__Game__) */