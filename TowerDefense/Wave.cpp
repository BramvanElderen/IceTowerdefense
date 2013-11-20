#include "Wave.h"


Wave::Wave(irr::scene::ISceneManager* p_sceneManager, int p_waveSize)
{
	//m_playgroundListener = p_playgroundListener;
	m_sceneManager = p_sceneManager;
	m_waveSize = p_waveSize;

	m_creaturesSpawned = 0;
	m_timer = new Timer();
}

Wave::~Wave()
{
	delete m_timer;
	m_timer = NULL;
}

void Wave::StartSpawning()
{
	m_creaturesSpawned = 0;
	m_timer->Start();
}

void Wave::ResetAndStopSpawning()
{
	m_creaturesSpawned = 0;
	m_timer->Reset();
}

bool Wave::SpawnCreature(Path* p_path)
{
	if (m_timer->IsRunning())
	{
		if (m_creaturesSpawned < m_waveSize)
		{
			if (m_timer->GetTime() == 1)
			{
				Creature* creature = new Creature(m_sceneManager, p_path);
				m_creatures.push_back(creature);
				m_timer->Reset();
				m_creaturesSpawned += 1;

				return true;
			}
			return true;
		}
		else
		{
			m_timer->Stop();
		}
	}

	return false;
}

void Wave::updateCreatures(float p_deltaTime)
{
	//Update creatures
	std::list<Creature*>::iterator itCreature = m_creatures.begin();
	std::list<Creature*>::iterator itCreatureEnd = m_creatures.end();
	Creature* creature;
	while (itCreature != itCreatureEnd)
	{
		creature = (*itCreature);
		++itCreature;
		creature->Update(p_deltaTime);		
	}
}



bool Wave::IsActive()
{
	return (m_timer->IsRunning());
}

bool Wave::AreAllCreaturesSpawned()
{
	return (m_creaturesSpawned >= m_waveSize);
}

int Wave::GetCreaturesSpawned()
{
	return m_creaturesSpawned;
}

void Wave::SetWaveSize(int p_waveSize)
{
	m_waveSize = p_waveSize;
}

int Wave::GetWaveSize()
{
	return m_waveSize;
}
