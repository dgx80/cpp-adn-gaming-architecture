#pragma once
#ifndef _DX_Circle_h
#define _DX_Circle_h

#include "base.h"
#include "Point.h"
#include "Vect2.h"

namespace DX
{
class Circle :
	public DX::base
{
public:
	Circle(void);
	virtual ~Circle(void);

	Circle( const Point & a_rOrigin, int a_nRay )
		: m_oOrigin(a_rOrigin)
		, m_oRay(a_rPower)
	{
	}

	void GetCenterPoint()
	{
	}

	//accessors

	//operators
	void operator+=(const Circle a_rOther)
	{
	}

	void operator-=(const Circle a_rOther)
	{
	}

	void operator=(const Circle a_rOther)
	{

	}

private:

	Point m_oOrigin;
	Vect2 m_nRay;
};
}

#endif