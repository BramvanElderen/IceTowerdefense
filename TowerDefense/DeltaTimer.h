#ifndef _DELTATIMER_H_
#define _DELTATIMER_H_

#include <irrlicht.h>

class DeltaTimer
{
public:
	DeltaTimer(irr::ITimer* p_timer);
	~DeltaTimer();
	float GetDelta();
private:
	irr::ITimer* m_timer;
	int m_time;
};
#endif