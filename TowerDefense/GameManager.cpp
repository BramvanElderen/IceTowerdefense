#include "GameManager.h"

GameManager::GameManager()
{
	m_resolution = irr::core::dimension2du(1280, 720);
	m_device = irr::createDevice(irr::video::EDT_DIRECT3D9,m_resolution, 16, false, false, false, 0);
	m_device->setWindowCaption(L"Tower Defense");

	m_sceneManager = m_device->getSceneManager();
	m_videoDriver = m_device->getVideoDriver();
	SetupCamera();

	m_playground = new PlayGround(m_sceneManager);
	
	m_guienv = m_sceneManager->getGUIEnvironment();
	m_gui = new Gui(m_guienv);
	
	m_deltaTimer = new DeltaTimer(m_device->getTimer());

}

void GameManager::Start()
{
	m_sceneManager->addCubeSceneNode();
	while (m_device->run())
	{
		//TIMER FOR PATH/CREATURES/PROJECTILES AND WHATEVER
		m_playground->Update(m_deltaTimer->GetDelta());
		m_videoDriver->beginScene(true, true, irr::video::SColor(255,100,101,140));


		m_sceneManager->drawAll();
		m_gui->UpdateGui(0,0,m_videoDriver->getFPS(),0,0);
		m_videoDriver->endScene();
	}
}

void GameManager::OnEvent(int p_event)
{
	switch (p_event)
	{
	case EnumEvent::KEYPRESS_ESC:
		m_gui->UpdateMenu();
		break;
	case EnumEvent::KEYPRESS_F:
		SwitchCameraMode();
		break;
	case EnumEvent::BUTTON_CLEAR:
		//TODO
		break;
	case EnumEvent::BUTTON_CONTROLS:
		m_gui->UpdateControlsMenu();
		break;
	case EnumEvent::BUTTON_MENU:
		m_gui->UpdateMenu();
		break;
	case EnumEvent::BUTTON_QUIT:
		m_device->closeDevice();
		break;
	case EnumEvent::BUTTON_SELL:
		//TODO
		break;
	case EnumEvent::BUTTON_STARTGAME:
		m_playground->StartNextWave();
		break;
	case EnumEvent::BUTTON_TOWER:
		//TODO
		break;
	//end switch case
	}
}

void GameManager::SetupCamera()
{
	m_camera = m_sceneManager->addCameraSceneNodeFPS(0,100.0f,5.f);
	m_camera->setPosition(irr::core::vector3df(1000.0f, 3000.0f, -1000.0f));
	m_camera->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
	m_camera->setTarget(irr::core::vector3df(1000.f,0,1000.f));
	m_camera->setFarValue(50000);
	m_camera->setInputReceiverEnabled(false);
}

void GameManager::SwitchCameraMode()
{
	if (m_camera->isInputReceiverEnabled())
	{
		m_camera->setInputReceiverEnabled(false);
		m_device->getCursorControl()->setVisible(true);
	} 
	else if (!m_camera->isInputReceiverEnabled())
	{
		m_camera->setInputReceiverEnabled(true);
		m_device->getCursorControl()->setVisible(false);
	}
}

irr::IrrlichtDevice* GameManager::GetDevice()
{
	return m_device;
}

