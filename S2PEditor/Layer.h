#pragma once

#include <string>

class Level;

// All layers types will derive from this abstract class
class Layer
{
public:
	virtual ~Layer() {}

	virtual void render() = 0;
	virtual void update(Level* pLevel) = 0;
	virtual std::string getLayerID() const = 0;
};