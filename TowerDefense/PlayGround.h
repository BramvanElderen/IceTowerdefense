#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <irrlicht.h>

#include "Terrain.h"
#include "Sky.h"
#include "Path.h"
#include "Wave.h"
#include "Light.h"

/************************************************************************/
/* @brief This class manages the behaviour and positions of all the objects in the world.
/* @author Bram van Elderen
/************************************************************************/

class PlayGround
{
public:
	PlayGround(irr::scene::ISceneManager* p_sceneManager);
	~PlayGround();
	void StartNextWave();
	void Update(float p_deltaTime);
	int GetCurrentWave();
	int GetAmountOfActiveCreatures();
private:	
	void InitializeWaves(float p_numberOfWaves);

	irr::scene::ISceneManager* m_sceneManager;
	Terrain* m_terrain;
	Sky* m_skybox;
	Path* m_path;
	Light* m_sun;
	std::vector<Wave*> m_waves;
	irr::core::dimension2d<irr::u32> m_terrainDimensions; 

	int atWave;
	int m_numberOfWaves;
	bool waveRunning;
};


#endif