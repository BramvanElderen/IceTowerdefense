#ifndef __GAME__WAVE__H__
#define __GAME__WAVE__H__

//#include "Game/Creature.h"
#include "Timer.h"

#include <vector>
#include <list>
#include <time.h>
#include <iostream>
#include <irrlicht.h>

#include "Creature.h"

class Wave
{
public:
	Wave(irr::scene::ISceneManager* p_sceneManager, int p_waveSize);
	~Wave();
	void StartSpawning();
	bool SpawnCreature(PathListener* p_path);
	int GetWaveSize();
	void updateCreatures(float p_deltaTime);
	bool IsCreatureSpawned();

private:
	irr::scene::ISceneManager* m_sceneManager;
	int m_waveSize;
	int m_creaturesSpawned;		
	Timer* m_timer;
	std::list<Creature*> m_creatures;
	bool m_creatureIsSpawned;
};

#endif