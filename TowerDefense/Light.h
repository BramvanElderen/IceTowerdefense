#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <irrlicht.h>
#include "Enum.h"

class Light
{
public:
	Light(irr::scene::ISceneManager* p_sceneManager, int p_lightType, irr::core::dimension2d<irr::u32> p_terrainDimensions);
	~Light();
	void SetPosition(irr::core::vector3df p_position);
	irr::core::vector3df GetPosition();
private:
	irr::scene::ILightSceneNode* m_light;
};
#endif 
