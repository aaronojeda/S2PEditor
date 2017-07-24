#ifndef __SDLPlatformer__Camera__
#define __SDLPlatformer__Camera__

#include <iostream>
#include "Vector2D.h"

// C++ 11: enum class allows to avoid conflict with other enum names (in mouseButtons we have another left)
enum class mode
{
	CENTER,
	LEFT
};

class Camera
{
public:

	static Camera& Instance()
	{
		static Camera s_pInstance;
		return s_pInstance;
	}

	// Target: global target position. Mode: target position relative to the camera (CAM_CENTER or CAM_LEFT) 
	void setTarget(Vector2D* target, mode targetMode = mode::CENTER);

	Vector2D getPosition();
	
private:

	Camera() : m_pTarget(nullptr), m_targetMode(mode::CENTER)
	{
	}

	~Camera(){};

	// Delete the methods we don't want (new in C++ 11)
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;

	// the camera's target
	Vector2D* m_pTarget;

	// target position relative to the camera (center for PlayState and left for EditorState)
	mode m_targetMode;
};

typedef Camera TheCamera;

#endif /* defined(__SDLPlatformer__Camera__) */