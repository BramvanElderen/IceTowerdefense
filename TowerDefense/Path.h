#ifndef _PATH_H_
#define _PATH_H_

#include <irrlicht.h>

class Path
{
public:
	Path(irr::core::dimension2d<irr::u32> p_gameDimensions);
	~Path();
	void InitializePath(irr::core::dimension2d<irr::u32> p_gameDimensions);
private:
	float GenerateRandomFloat(float p_lower, float p_upper);

	irr::core::vector2d<irr::u32> m_gamePositions[2];


};
#endif