#ifndef __TERRAIN__H__
#define __TERRAIN__H__

#include <irrlicht.h>
#include "TerrainListener.h"

class Terrain : public TerrainListener
{
public:
	/**
	 *@brief Constructor
	 */
	Terrain();
	/**
	 *@brief Destructor
	 */
	~Terrain();

	irr::scene::ITriangleSelector* GenerateTerrain(irr::scene::ISceneManager* p_sceneManager, float p_scale);
	irr::f32 GetTerrainHeight(irr::core::vector3df p_position);
	irr::core::dimension2d<irr::u32> GetTerrainDimensions();
private:
	irr::scene::ITerrainSceneNode* m_terrain;
	irr::core::dimension2d<irr::u32> m_terrainDimensions;
};


#endif