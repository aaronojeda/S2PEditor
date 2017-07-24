#pragma once
#include "ObjectLayer.h"

class BckLayer :
	public ObjectLayer
{
public:
	virtual void render();
	virtual void update(Level* pLevel);
	virtual std::string getLayerID() const { return s_bckLayerID; }
private:
	static const std::string s_bckLayerID;
};

