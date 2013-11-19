#include "Path.h"
#include <random>
#include <iostream>
#include <functional>

Path::Path(irr::core::dimension2d<irr::u32> p_gameDimensions)
{
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
	irr::core::vector2d<irr::u32> beginPoint = irr::core::vector2d<irr::u32>((irr::u32)Xresult,(irr::u32)Yresult);

	//Place random end point in a specified area	
	xEnd = (float)(X - (X * 0.05));
	xBegin = (float)(xEnd - (X * 0.15));
	yEnd = (float)(Y - (Y * 0.05));
	yBegin = (float)(yEnd - (Y * 0.15));
	Xresult = GenerateRandomFloat(xBegin, xEnd);
	Yresult = GenerateRandomFloat(yBegin, yEnd);
	irr::core::vector2d<irr::u32> endPoint = irr::core::vector2d<irr::u32>((irr::u32)Xresult,(irr::u32)Yresult);

	//Add the results to the gamePositions array
	m_gamePositions[0] = beginPoint;
	m_gamePositions[1] = endPoint;
}

float Path::GenerateRandomFloat(float p_lower, float p_upper)
{
	float result;	
	int r = rand();
	float fraction = ((float) r / RAND_MAX) * (p_upper - p_lower);
	result = p_lower + fraction;
	return result;
}
