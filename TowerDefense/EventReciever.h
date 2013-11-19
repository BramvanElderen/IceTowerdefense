#ifndef _EVENTRECIEVER_H_
#define _EVENTRECIEVER_H_

#include "GameManager.h"

class EventReciever : public irr::IEventReceiver
{
public:
	EventReciever(irr::IrrlichtDevice* p_device, GameManager* p_gameManager);
	~EventReciever();
	virtual bool OnEvent(const irr::SEvent& p_event);

private:
	irr::IrrlichtDevice* m_device;
	GameManager* m_gameManager;
};
#endif