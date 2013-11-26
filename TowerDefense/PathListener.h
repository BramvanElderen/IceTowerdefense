#ifndef _PATHLISTENER_H_
#define _PATHLISTENER_H_

#include <irrlicht.h>

class PathListener
{
public:
	virtual irr::core::vector3df GetStartPosition() = 0;
	virtual irr::core::vector3df GetEndPosition() = 0;
	virtual irr::core::vector3df FollowPath(irr::core::vector3df* p_position, float p_deltatime) = 0;
	virtual irr::core::vector3df AdjustRotation(irr::core::vector3df* p_position) = 0;
};


#endif