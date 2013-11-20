#ifndef __GAME__CREATURE__H__
#define __GAME__CREATURE__H__

#include <irrlicht.h>

#include "Path.h"
#include "Terrain.h"
class Creature
{
public:
	Creature(irr::scene::ISceneManager* p_sceneManager, Path* p_path);
	~Creature();
	void DecreaseHealthPoints(double p_healthPoints);
	double GetHealthPoints();
	irr::core::aabbox3d<irr::f32> GetBoundingbox();
	void Update(float p_deltaTime);

	//Universal methods //TODO entity class
	void SetMaterialFlags(irr::scene::ISceneNode* p_sceneNode = NULL);
	irr::core::vector3df GetPosition();
	void SetPosition(irr::core::vector3df& p_position);
	irr::scene::ISceneNode* GetSceneNode();
private:
    double m_healthPoints;
	irr::scene::ISceneManager* m_sceneManager;
	irr::scene::ISceneNode* m_meshSceneNode;
	irr::scene::IAnimatedMesh* m_animatedMesh;
	Path* m_path;

};


#endif