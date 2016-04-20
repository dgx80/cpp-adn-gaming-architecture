#pragma once
#ifndef _DX_Vect2_h
#define _DX_Vect2_h

#include "RollerPin.h"

namespace DX
{
namespace Graphic
{
class Vect2 :
	public Canevas::RollerPin
{
public:
	
	virtual ~Vect2(void);

	Vect2( const Point & a_rOrigin = Point(0,0), float a_fLenght = 0.0f, const int &a_nDegre = 0);


	virtual void Draw()const;

	//accessors
	const Point & GetDestination() const {return m_oDest;}
	const float &GetLenght() const {return m_fLenght;}

	const Point& GetDirection() const { return m_oDirection; }

	void SetDestination( const Point & a_rPoint ){m_oDest = a_rPoint;}
	void SetLenght( const float &a_fPoint );

	virtual void SetDegre( const int &a_nDeg );
	virtual void SetRadian( const float &a_fRad );

	virtual void SetX(const int &a_nX)
	{
		RollerPin::SetX(a_nX);
		m_oDest.SetX(GetX() + m_oDirection.GetX());
	}
	virtual void SetY(const int &a_nY)
	{
		RollerPin::SetY(a_nY);
		m_oDest.SetY(GetY() + m_oDirection.GetY());
	}
	//operators
protected:

	virtual void InitVect2();

private:
	inline void RefreshDestination()
	{
		m_oDest.SetX(GetX() + m_oDirection.GetX());
		m_oDest.SetY(GetY() + m_oDirection.GetY());
	}

	void UpdateDestination();
	void UpdateDirection();

	float m_fLenght;
	Point m_oDest;

	Point m_oDirection;
};
}
}
#endif