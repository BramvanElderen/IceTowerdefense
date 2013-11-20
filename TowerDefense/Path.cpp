#include "Path.h"
#include <random>
#include <iostream>
#include <functional>

Path::Path(irr::core::dimension2d<irr::u32> p_gameDimensions, Terrain* p_terrain)
{
	m_terrain = p_terrain;
	InitializePath(p_gameDimensions);
}

void Path::InitializePath(irr::core::dimension2d<irr::u32> p_gameDimensions)
{
	float X = (float)p_gameDimensions.Width;
	float Y = (float)p_gameDimensions.Height;

	//Init 4 points to determine rectangles on the field
	float xBegin; 
	float xEnd;
	float yBegin;
	float yEnd;

	//Place random start point in a specified area
	xBegin = (float)(X * 0.05);
	xEnd = (float)(xBegin + (X * 0.15));
	yBegin = (float)(Y * 0.05);
	yEnd = (float)(yBegin + (Y * 0.15));
	
	float Xresult = GenerateRandomFloat(xBegin, xEnd);
	float Yresult = GenerateRandomFloat(yBegin, yEnd);
	
	
	irr::core::vector3df beginPoint = irr::core::vector3df(Xresult, 0.f, Yresult);
	beginPoint = irr::core::vector3df(Xresult, m_terrain->GetTerrainHeight(beginPoint), Yresult);

	//Place random end point in a specified area	
	xEnd = (float)(X - (X * 0.05));
	xBegin = (float)(xEnd - (X * 0.15));
	yEnd = (float)(Y - (Y * 0.05));
	yBegin = (float)(yEnd - (Y * 0.15));
	Xresult = GenerateRandomFloat(xBegin, xEnd);
	Yresult = GenerateRandomFloat(yBegin, yEnd);
	irr::core::vector3df endPoint = irr::core::vector3df(Xresult, 0.f, Yresult);
	endPoint = irr::core::vector3df(Xresult, m_terrain->GetTerrainHeight(endPoint), Yresult);

	//Add the results to the gamePositions array
	m_gamePositions[0] = beginPoint;
	m_gamePositions[1] = endPoint;
}

irr::core::vector3df Path::FollowPath(irr::core::vector3df* p_currentPosition, float p_deltaTime)
{
	//Calculate distance to end point
	irr::core::vector3df distance = m_gamePositions[1] -  *p_currentPosition;
	//Calculate movementspeed
	float movementSpeed = 12.f / p_currentPosition->getDistanceFrom(m_gamePositions[1]);
	//calculate new position
	irr::core::vector3df newPosition = *p_currentPosition + distance * movementSpeed * p_deltaTime * 60;
	newPosition.Y = m_terrain->GetTerrainHeight(newPosition);
	irr::core::vector3df result = newPosition;
	return result;
}

float Path::GenerateRandomFloat(float p_lower, float p_upper)
{
	float result;	
	int r = rand();
	float fraction = ((float) r / RAND_MAX) * (p_upper - p_lower);
	result = p_lower + fraction;
	return result;
}

irr::core::vector3df Path::GetStartPosition()
{
	return m_gamePositions[0];
}