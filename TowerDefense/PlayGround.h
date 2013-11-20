#ifndef _PLAYGROUND_H_
#define _PLAYGROUND_H_

#include <irrlicht.h>

#include "Terrain.h"
#include "Sky.h"
#include "Path.h"
#include "Wave.h"

class PlayGround
{
public:
	PlayGround(irr::scene::ISceneManager* p_sceneManager);
	~PlayGround();
	void StartNextWave();
	void Update(float p_deltaTime);
private:	
	void InitializeWaves(float p_numberOfWaves);

	irr::scene::ISceneManager* m_sceneManager;
	Terrain* m_terrain;
	Sky* m_skybox;
	Path* m_path;
	std::vector<Wave*> m_waves;
	irr::core::dimension2d<irr::u32> m_terrainDimensions; 

	int atWave;
	bool waveRunning;
};


#endif