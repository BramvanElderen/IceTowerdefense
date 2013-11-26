#ifndef _EVENTRECIEVER_H_
#define _EVENTRECIEVER_H_

#include <irrlicht.h>
#include "GameManagerInterface.h"
#include "Enum.h"

class EventReciever : public irr::IEventReceiver
{
public:
	EventReciever(irr::IrrlichtDevice* p_device, GameManagerInterface* p_gameManager);
	~EventReciever();
	virtual bool OnEvent(const irr::SEvent& p_event);

private:
	irr::IrrlichtDevice* m_device;
	GameManagerInterface* m_gameManager;
};
#endif