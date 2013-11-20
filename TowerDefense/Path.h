#ifndef _PATH_H_
#define _PATH_H_

#include <irrlicht.h>

#include "Terrain.h"

class Path
{
public:
	Path(irr::core::dimension2d<irr::u32> p_gameDimensions, Terrain* p_terrain);
	~Path();
	void InitializePath(irr::core::dimension2d<irr::u32> p_gameDimensions);
	irr::core::vector3df FollowPath(irr::core::vector3df* p_currentPosition, float p_deltaTime);
	irr::core::vector3df GetStartPosition();
private:
	float GenerateRandomFloat(float p_lower, float p_upper);

	irr::core::vector3df m_gamePositions[2];
	Terrain* m_terrain;

};
#endif