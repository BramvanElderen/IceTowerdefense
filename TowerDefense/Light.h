#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <irrlicht.h>

class Light
{
public:
	Light(irr::scene::ISceneManager* p_sceneManager);
	~Light();

private:
	irr::scene::ILightSceneNode* m_light;
};
#endif 
