#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <irrlicht.h>

#include "Terrain.h"
#include "Sky.h"
#include "Path.h"
#include "Wave.h"
#include "Light.h"
#include "Tower.h"

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
	void CreateTower(irr::core::vector2di p_position);
	void SellTower(irr::core::vector2di p_position);
	Tower* GetTowerAtPosition(irr::core::vector2di p_position);
	void Update(float p_deltaTime);
	int GetCurrentWave();
	int GetAmountOfActiveCreatures();
private:	
	void InitializeWaves(float p_numberOfWaves);

	irr::scene::ISceneManager* m_sceneManager;
	irr::scene::ITriangleSelector* m_selector;
	Terrain* m_terrain;
	Sky* m_skybox;
	Path* m_path;
	Light* m_sun;
	std::vector<Wave*> m_waves;
	std::list<Tower*> m_towers;
	irr::core::dimension2d<irr::u32> m_terrainDimensions; 

	int atWave;
	int m_numberOfWaves;
	bool waveRunning;
};


#endif