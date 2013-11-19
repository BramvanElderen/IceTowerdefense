#ifndef _SKY_H_
#define _SKY_H_

#include <irrlicht.h>

class Sky
{
public:
	Sky();
	~Sky();
	void GenerateSky(irr::scene::ISceneManager* p_scenemanager);
private:
	irr::scene::ISceneNode* m_skydome;
	irr::scene::ISceneNode* m_skybox;
};

#endif