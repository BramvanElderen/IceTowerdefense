#ifndef _TOWER__H__
#define __TOWER__H__

#include "Creature.h"
//#include "Projectile.h"
#include "Timer.h"

#include <list>
#include <cmath>


class Tower
{
public:
	/***
	 * @brief	Construct a new tower object.
	 * @param	p_sceneManager The irr::scene::ISceneManager used to store the SceneNode.
	 * @param	p_playgroundListener The PlaygroundListener to handle events.
	 * @param	p_position The position of the Tower
	 */
	Tower(irr::scene::ISceneManager* p_sceneManager, irr::core::vector3df p_position);

	~Tower();

	void SetShootingSpeed(float p_shootingSpeed);
	void SetShootingRange(float p_shootingRange);
	void SetShootingDamage(float p_shootingDamage);
	float GetShootingSpeed();
	float GetShootingRange();
	float GetShootingDamage();
	void SetMaterialFlags(irr::scene::ISceneNode* p_sceneNode = NULL);
	irr::core::vector3df GetPosition();
	void SetPosition(irr::core::vector3df& p_position);
	irr::scene::ISceneNode* GetSceneNode();

	/**
	 * @brief	Fires a Projetile at a Creature.
	 *			Searches the list for the closest creature. After that it creates a projectile with that creature as its target.
	 * @param std::list<Creature*>& List of creatures to search in and shoot at.
	 */
	void ShootAtNearestCreature(std::list<Creature*>&);
	
private:
	float m_shootingSpeed;
	float m_shootingRange;
	float m_shootingDamage;
	irr::scene::ISceneManager* m_sceneManager;
	irr::scene::ISceneNode* m_meshSceneNode;
	irr::scene::IAnimatedMesh* m_animatedMesh;
	irr::scene::ISceneNode* m_jointCrystal;

	Timer* m_timer;

	/**
	 * @brief	Searches for the Creature closest to the Tower.
	 * @param	p_creatureList The list contains the Creatures to search for.
	 * @return	Creature* The Creature that is closest to the Tower.
	 */
	Creature* SearchNearestCreature(std::list<Creature*>& p_creatureList);

	/**
	 * @brief	Creates a Projectile and sets the target to the Creature.
	 * @param	p_creature The Creature target for the Projectile.
	 */
	void ShootProjectileAtCreature(Creature* p_creature);
};


#endif