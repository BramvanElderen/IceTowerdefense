#include "PlayGround.h"

PlayGround::PlayGround(irr::scene::ISceneManager* p_sceneManager)
{
	m_sceneManager = p_sceneManager;

	m_terrain = new Terrain();
	m_terrain->GenerateTerrain(m_sceneManager,40);
	m_terrainDimensions = m_terrain->GetTerrainDimensions();
	m_skybox =  new Sky();
	m_skybox->GenerateSky(p_sceneManager);
	m_path = new Path(m_terrainDimensions, (TerrainListener*)m_terrain);
	m_sun = new Light(p_sceneManager);
	m_numberOfWaves = 2;
	InitializeWaves(m_numberOfWaves);
}

void PlayGround::StartNextWave()
{
	if (!waveRunning)
	{
		if (atWave != m_numberOfWaves)
		{
			m_path->GeneratePath(m_terrainDimensions);
			m_waves[0]->StartSpawning();
			atWave += 1;
			waveRunning = true;	
		}
	}
}

void PlayGround::Update(float p_deltaTime)
{
	if (waveRunning)
	{
		m_waves[0]->SpawnCreature((PathListener*)m_path);
		m_waves[0]->updateCreatures(p_deltaTime);
		if (m_waves[0]->GetWaveSize() == 0 && m_waves[0]->IsCreatureSpawned())
		{
			delete m_waves[0];
			m_waves.erase(m_waves.begin());
			waveRunning = false;
		}
	}
}

int PlayGround::GetCurrentWave()
{
	return atWave;
}

int PlayGround::GetAmountOfActiveCreatures()
{
	if (waveRunning)
	{
		return m_waves[0]->GetWaveSize();
	}
	return 0;
}



void PlayGround::InitializeWaves(float p_numberOfWaves)
{
	if (p_numberOfWaves >= 1)
	{
		m_waves.push_back(new Wave(m_sceneManager, 10));
	}

	if (p_numberOfWaves >= 2)
	{
		m_waves.push_back(new Wave(m_sceneManager, 15));
	}

	if (p_numberOfWaves >= 3)
	{
		m_waves.push_back(new Wave(m_sceneManager, 30));
	}

	if (p_numberOfWaves >= 4)
	{
		m_waves.push_back(new Wave(m_sceneManager, 50));
	}

	int remainingWaves = p_numberOfWaves - m_waves.size();
	if (remainingWaves > 0)
	{
		for (int i = 0; i<remainingWaves; ++i)
		{
			m_waves.push_back(new Wave(m_sceneManager,70));
		}
	}
	atWave = 0;
	waveRunning = false;
}