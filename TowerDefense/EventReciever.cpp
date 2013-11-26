#include "EventReciever.h"

EventReciever::EventReciever(irr::IrrlichtDevice* p_device, GameManagerInterface* p_gameManager)
{
	m_device = p_device;
	m_gameManager = p_gameManager;

}

EventReciever::~EventReciever()
{

}

bool EventReciever::OnEvent(const irr::SEvent& p_event)
{
	
	//TODO
	if (p_event.EventType == irr::EET_GUI_EVENT)
	{
		int id = p_event.GUIEvent.Caller->getID();
		if (p_event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
		{
			m_gameManager->OnEvent(id);
			return true;
		}
	}
	else if (p_event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
		irr::s32 keyInput = p_event.KeyInput.Key;

		if (keyInput == irr::KEY_ESCAPE && !p_event.KeyInput.PressedDown)
		{
			m_gameManager->OnEvent(EnumEvent::KEYPRESS_ESC);
			return true;
		}
		if (keyInput == irr::KEY_KEY_F && !p_event.KeyInput.PressedDown)
		{
			m_gameManager->OnEvent(EnumEvent::KEYPRESS_F);
			return true;
			

		}
	}
	else if (p_event.EventType == irr::EET_MOUSE_INPUT_EVENT)
	{
		if (p_event.MouseInput.isLeftPressed())
		{
			//m_gameManager->OnEvent(EnumEvent::BUTTON_QUIT);
		}				
	}
	return false;

}