#include "PlayGround.h"

PlayGround::PlayGround(irr::scene::ISceneManager* p_sceneManager)
{
	m_sceneManager = p_sceneManager;

	m_terrain = new Terrain();
	m_terrain->GenerateTerrain(m_sceneManager,40);
	m_terrainDimensions = m_terrain->GetTerrainDimensions();	
	m_skybox =  new Sky();
	m_skybox->GenerateSky(p_sceneManager);
	m_path = new Path(m_terrainDimensions, m_terrain);
	InitializeWaves(2);
}

void PlayGround::InitializeWaves(float p_numberOfWaves)
{
	for (int i = 0; i<p_numberOfWaves; i++)
	{
		m_waves.push_back(new Wave(m_sceneManager, 10));
	}
	atWave = 0;
	waveRunning = false;
}

void PlayGround::StartNextWave()
{
	//if (!waveRunning)
	//{
	//	std::list<Wave*>::iterator itWave = m_waves.begin();
	//	std::list<Wave*>::iterator itWaveEnd = m_waves.end();
	//	Wave* wave;
	//	int loopCount = 0;
	//	while (itWave != itWaveEnd)
	//	{
	//		if (loopCount == atWave)
	//		{
	//			wave = *itWave;
	//			wave->StartSpawning();
	//			waveRunning = true;
	//			++atWave;
	//			return;
	//		}
	//		++loopCount;
	//		++itWave;	
	//	}
	//}
	m_waves[0]->StartSpawning();

}

void PlayGround::Update(float p_deltaTime)
{
	//if (waveRunning)
	//{
	//	std::list<Wave*>::iterator itWave = m_waves.begin();
	//	std::list<Wave*>::iterator itWaveEnd = m_waves.end();
	//	Wave* wave;
	//	int loopCount = 0;
	//	while (itWave != itWaveEnd)
	//	{
	//		if (loopCount == (atWave-1))
	//		{
	//			wave = *itWave;
	//			if(!wave->SpawnCreature(m_path))
	//			{
	//				waveRunning = false;
	//			}
	//			itWave = itWaveEnd;
	//		} else
	//		{
	//			++loopCount;
	//			++itWave;
	//		}	
	//	}
	//	wave = *m_waves.begin();
	//	wave->updateCreatures(p_deltaTime);

	//}
	m_waves[0]->SpawnCreature(m_path);
	m_waves[0]->updateCreatures(p_deltaTime);

}