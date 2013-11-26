#include "Light.h"

Light::Light(irr::scene::ISceneManager* p_sceneManager)
{
	m_light = p_sceneManager->addLightSceneNode(0,irr::core::vector3df(-3000.f,3000.f,0),irr::video::SColorf(1.0f, 0.6f, 0.7f, 1.0f));
	m_light->setRadius(30000);
	
}

Light::~Light()
{

}