#include "Creature.h"

Creature::Creature(irr::scene::ISceneManager* p_sceneManager,
	Path* p_path)	
{
	m_sceneManager = p_sceneManager;
	m_meshSceneNode = NULL;
	m_animatedMesh = NULL;
	
	m_meshSceneNode = p_sceneManager->addEmptySceneNode();
	irr::scene::ISceneNode* sceneNodeTemp = NULL;
	irr::core::aabbox3d<irr::f32>* boundingbox = new irr::core::aabbox3d<irr::f32>(irr::core::vector3df(-2.0f, -2.0f, -2.0f), irr::core::vector3df(2.0f, 2.0f, 2.0f));

	//Head
	m_animatedMesh = p_sceneManager->getMesh("resources/models/creature/goomba/goombawalk2.7H.x");
	sceneNodeTemp = p_sceneManager->addAnimatedMeshSceneNode(m_animatedMesh, m_meshSceneNode);
	SetMaterialFlags(sceneNodeTemp);

	//Body
	m_animatedMesh = p_sceneManager->getMesh("resources/models/creature/goomba/goombawalk2.7L.x");
	sceneNodeTemp = p_sceneManager->addAnimatedMeshSceneNode(m_animatedMesh, m_meshSceneNode);
	SetMaterialFlags(sceneNodeTemp);

	//Left Foot
	m_animatedMesh = p_sceneManager->getMesh("resources/models/creature/goomba/goombawalk2.7LF.x");
	sceneNodeTemp = p_sceneManager->addAnimatedMeshSceneNode(m_animatedMesh, m_meshSceneNode);
	SetMaterialFlags(sceneNodeTemp);

	//Right Foot
	m_animatedMesh = p_sceneManager->getMesh("resources/models/creature/goomba/goombawalk2.7RF.x");
	sceneNodeTemp = p_sceneManager->addAnimatedMeshSceneNode(m_animatedMesh, m_meshSceneNode);
	SetMaterialFlags(sceneNodeTemp);

	m_meshSceneNode->setScale(irr::core::vector3df(1.5f));
	m_animatedMesh->setBoundingBox(*boundingbox);
	m_healthPoints = 20;
	m_meshSceneNode->setDebugDataVisible(irr::scene::EDS_BBOX);

	m_path = p_path;
	SetPosition(m_path->GetStartPosition());
}

Creature::~Creature()
{
	m_meshSceneNode->remove();
}

void Creature::Update(float p_deltaTime)
{	

	irr::core::vector3df* position = &GetPosition();
	irr::core::vector3df newPosition = m_path->FollowPath(position,p_deltaTime);
	SetPosition(newPosition);
}

void Creature::DecreaseHealthPoints(double p_healthPoints)
{
	m_healthPoints -= p_healthPoints;
}

double Creature::GetHealthPoints()
{
	return m_healthPoints;
}

void Creature::SetMaterialFlags(irr::scene::ISceneNode* p_sceneNode)
{
	if (p_sceneNode == NULL)
	{
		p_sceneNode = m_meshSceneNode;
	}

	p_sceneNode->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
	p_sceneNode->setMaterialFlag(irr::video::E_MATERIAL_FLAG::EMF_ANTI_ALIASING, true);
	p_sceneNode->setMaterialType(irr::video::E_MATERIAL_TYPE::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
}

irr::core::vector3df Creature::GetPosition()
{
	return m_meshSceneNode->getPosition();
}

void Creature::SetPosition(irr::core::vector3df& p_vector)
{
	m_meshSceneNode->setPosition(p_vector);
}

irr::scene::ISceneNode* Creature::GetSceneNode()
{
	return m_meshSceneNode;
}