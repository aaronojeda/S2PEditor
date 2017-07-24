#include "LoaderParams.h"

using namespace std;

LoaderParams::LoaderParams(int x, int y, int xSpeed, int ySpeed, 
	map<string, Animation> animations, int value, 
	string soundID, string sound2ID,
	int value2, int value3) :
m_x{ x },
m_y{ y },
m_value{ value },
m_xSpeed{ xSpeed },
m_ySpeed{ ySpeed },
m_animations{ animations },
//m_jumpHeight{ jumpHeight },
//m_jumpSpeed{ jumpSpeed },
m_soundID{ soundID },
m_sound2ID{ sound2ID },
m_value2{ value2 },
m_value3{ value3 }
{}

int LoaderParams::getX() const 
{ 
	return m_x; 
}

int LoaderParams::getY() const 
{
	return m_y; 
}

int LoaderParams::getXSpeed() const
{
	return m_xSpeed;
}

int LoaderParams::getYSpeed() const
{
	return m_ySpeed;
}

int LoaderParams::getValue() const
{
	return m_value;
}

int LoaderParams::getValue2() const
{
	return m_value2;
}

int LoaderParams::getValue3() const
{
	return m_value3;
}

void LoaderParams::getValues(int &v, int &v2, int &v3) const
{
	v = m_value;
	v2 = m_value2;
	v3 = m_value3;
}


std::map<std::string, Animation> LoaderParams::getAnimations() const
{
	return m_animations; 
}

//int LoaderParams::getJumpHeight() const
//{
//	return m_jumpHeight;
//}
//
//int LoaderParams::getJumpSpeed() const
//{
//	return m_jumpSpeed;
//}

string LoaderParams::getSoundID() const
{
	return m_soundID;
}

string LoaderParams::getSound2ID() const
{
	return m_sound2ID;
}