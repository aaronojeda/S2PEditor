#include "Game.h"
#include "Camera.h"

Vector2D Camera::getPosition()
{
	if (m_pTarget != nullptr)	// If target isn't null
	{
		if (m_targetMode == mode::CENTER)
		{
			// The target position will be in the center of the camera
			Vector2D pos(m_pTarget->x() - (TheGame::Instance().getGameWidth() / 2),
				m_pTarget->y() - (TheGame::Instance().getGameHeight() / 2));

			// If camera has reached any map boundary, stop moving it in that axis
			if ( (pos.x() < 0))
			{
				// Left boundary reached
				pos.x(0);
			}
			else if (pos.x() > (TheGame::Instance().getMapWidth() - TheGame::Instance().getGameWidth()))
			{
				// Right boundary reached
				pos.x(TheGame::Instance().getMapWidth() - TheGame::Instance().getGameWidth());
			}
			if (pos.y() < 0)
			{
				// Top boundary reached
				pos.y(0);
			}
			else if (pos.y() > (TheGame::Instance().getMapHeight() - TheGame::Instance().getGameHeight()))
			{
				// Down boundary reached
				pos.y(TheGame::Instance().getMapHeight() - TheGame::Instance().getGameHeight());
			}

			return pos;
		}
		else // if (m_targetMode == mode::LEFT)
		{
			// The target position coincides with the camera's
			return *m_pTarget;
		}
	}
	else
	{
		// No target defined, so we set the camera position in the origin
		return{ 0, 0 };
	}
}

void Camera::setTarget(Vector2D* target, mode targetMode)
{
	m_pTarget = target; 
	m_targetMode = targetMode; 
}
