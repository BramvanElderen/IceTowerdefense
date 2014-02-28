#include "Light.h"

Light::Light(irr::scene::ISceneManager* p_sceneManager, int p_lightType, irr::core::dimension2d<irr::u32> p_terrainDimensions)
{
	switch (p_lightType)
	{
	case EnumLight::LIGHT_NORMAL:
		m_light = p_sceneManager->addLightSceneNode(0,irr::core::vector3df(-3000.f,3000.f,0),irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f));
		m_light->setRadius(30000);
		m_light->enableCastShadow(true);
		break;
	case EnumLight::LIGHT_AMBIENT:
		m_light = p_sceneManager->addLightSceneNode(0,irr::core::vector3df((p_terrainDimensions.Width/2),5000, (p_terrainDimensions.Height/2)));
		m_light->setRadius(30000);
		m_light->enableCastShadow(false);
		break;
	}	
}

Light::~Light()
{

}

void Light::SetPosition(irr::core::vector3df p_position)
{
	m_light->setPosition(p_position);
}

irr::core::vector3df Light::GetPosition()
{
	return m_light->getPosition();
}