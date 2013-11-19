#include "PlayGround.h"

PlayGround::PlayGround(irr::scene::ISceneManager* p_sceneManager)
{
	m_sceneManager = p_sceneManager;

	m_terrain = new Terrain();
	m_terrain->GenerateTerrain(m_sceneManager,40);
	m_terrainDimensions = m_terrain->GetTerrainDimensions();	
	m_skybox =  new Sky();
	m_skybox->GenerateSky(p_sceneManager);
	m_path = new Path(m_terrainDimensions);
}