#include "Sky.h"

Sky::Sky()
{
}

Sky::~Sky()
{
}

void Sky::GenerateSky(irr::scene::ISceneManager* p_scenemanager)
{
	irr::video::IVideoDriver* driver = p_scenemanager->getVideoDriver();
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
	m_skybox = p_scenemanager->addSkyBoxSceneNode(
		driver->getTexture("resources/textures/irrlicht2_up.jpg"),
		driver->getTexture("resources/textures/irrlicht2_dn.jpg"),
		driver->getTexture("resources/textures/irrlicht2_lf.jpg"),
		driver->getTexture("resources/textures/irrlicht2_rt.jpg"),
		driver->getTexture("resources/textures/irrlicht2_ft.jpg"),
		driver->getTexture("resources/textures/irrlicht2_bk.jpg"));
	
	irr::video::ITexture* skytexture;
	skytexture = driver->getTexture("resources/textures/skydome.jpg");
	m_skydome = p_scenemanager->addSkyDomeSceneNode(skytexture, 16, 8, 0.95f, 2.0f);
	m_skydome->setVisible(false);
	driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}