#ifndef _PATH_H_
#define _PATH_H_

#include <irrlicht.h>

#include "TerrainListener.h"
#include "PathListener.h"

class Path : public PathListener
{
public:
	Path(irr::core::dimension2d<irr::u32> p_gameDimensions, TerrainListener* p_terrain);
	~Path();
	void GeneratePath(irr::core::dimension2d<irr::u32> p_gameDimensions);
	irr::core::vector3df FollowPath(irr::core::vector3df* p_currentPosition, float p_deltaTime);
	irr::core::vector3df AdjustRotation(irr::core::vector3df* p_currentPosition);
	irr::core::vector3df GetStartPosition();
	irr::core::vector3df GetEndPosition();
private:
	float GenerateRandomFloat(float p_lower, float p_upper);

	irr::core::vector3df m_gamePositions[2];
	TerrainListener* m_terrain;

};
#endif