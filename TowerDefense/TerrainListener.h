#ifndef _TERRAINLISTENER_H_
#define _TERRAINLISTENER_H_

#include <irrlicht.h>

class TerrainListener
{
public:
	virtual irr::f32 GetTerrainHeight(irr::core::vector3df p_position) = 0;
};

#endif