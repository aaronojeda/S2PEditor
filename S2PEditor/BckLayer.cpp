#include "BckLayer.h"

const std::string BckLayer::s_bckLayerID = "BACKGROUND";

void BckLayer::update(Level* pLevel)
{
	for (auto bck : m_gameObjects)
	{
		bck->update();
	}
}

void BckLayer::render()
{
	for (auto bck : m_gameObjects)
	{
		bck->draw();
	}
}
