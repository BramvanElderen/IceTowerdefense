#ifndef _PLAYGROUND_H_
#define _PLAYGROUND_H_

#include <irrlicht.h>

#include "Terrain.h"
#include "Sky.h"
#include "Path.h"

class PlayGround
{
public:
	PlayGround(irr::scene::ISceneManager* p_sceneManager);
	~PlayGround();
private:	
	void PlaceStartEndPoints();


	irr::scene::ISceneManager* m_sceneManager;
	Terrain* m_terrain;
	Sky* m_skybox;
	Path* m_path;
	irr::core::dimension2d<irr::u32> m_terrainDimensions; 
};


#endif