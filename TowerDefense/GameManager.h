#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "PlayGround.h"
#include "Gui.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Start();
	void OnEvent(int);
	irr::IrrlichtDevice* GetDevice();
private:
	
	void SetupCamera();
	void SwitchCameraMode();
	
	irr::core::dimension2du m_resolution;
	irr::IrrlichtDevice* m_device;
	irr::scene::ISceneManager* m_sceneManager;
	irr::video::IVideoDriver* m_videoDriver;
	irr::scene::ICameraSceneNode* m_camera;
	irr::gui::IGUIEnvironment* m_guienv;

	PlayGround* m_playground;
	Gui* m_gui;
};
#endif