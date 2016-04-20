#pragma once
#ifndef _DX_Point_h
#define _DX_Point_h

#include "DXDefine.h"
#include "base.h"
#include <Math.h>

namespace DX
{
class Point : public DX::base
{
public:
	
	// Constructors
	Point(int x = 0, int y = 0);

	// Destructor
	virtual ~Point(void){};

	virtual void Update(const int &nElapsedTime);

	// Accessors
	const int& GetX()const{return m_nX;}
	const int& GetY()const{return m_nY;}
	
	virtual void SetPosition(const Point& a_oPos)
	{
		SetX(a_oPos.GetX());
		SetY(a_oPos.GetY());
	}
	virtual void SetX(const int &a_nX){m_nX = a_nX;}
	virtual void SetY(const int &a_nY){m_nY = a_nY;}

	const DX::Point &GetPosition() const{ return *this;}



	//static algo
	static Point CalculatePointFrom( const float &fHypothenuse, const float& fRad )
	{
		return Point(	static_cast<int>(fHypothenuse* cos( fRad )),static_cast<int>(fHypothenuse* sin( fRad ) ));
	}
	//template algo
	template <class T>
	inline void CalculateTeta(T& oTeta) const
	{
		oTeta = static_cast<T>( atan( GetY<float>()/GetY<float>() ) );
		//warning :=> oTeta is Rad value ...not degre
	}

	template <class T>
	inline void CalculateSquareSide(T& oRep) const
	{
		oRep = static_cast<T>(m_nX*m_nX + m_nY*m_nY);
		// :=> oRep = (x^2 + y^2)
	}
	template <class T>
	inline void CalculateHypothenuse(T& oRep) const
	{
		CalculateSquareSide<T>(oRep);
		// :=> oRep = (x^2 + y^2)
		oRep = sqrt(oRep);
	}


	//template accessors
	template <class T>
	T GetX()const{return static_cast<T>(m_nX);}
	
	template <class T>
	T GetY()const{return static_cast<T>(m_nY);}

	// Operators
	virtual Point& operator=( const DX::Point & a_rOther )
	{
		SetX(a_rOther.GetX());
		SetY(a_rOther.GetY());
		return *this;
	}
	virtual void operator+=( const DX::Point & a_rOther )
	{
		SetX(m_nX + a_rOther.GetX());
		SetY(m_nY + a_rOther.GetY());
	}
	virtual void operator-=( const DX::Point & a_rOther )
	{
		SetX(m_nX - a_rOther.GetX());
		SetY(m_nY - a_rOther.GetY());
	}
	virtual Point operator+( const DX::Point & a_rOther ) const 
	{
		return DX::Point( m_nX + a_rOther.GetX(), m_nY + a_rOther.GetY());
	}

protected:

private:
	int m_nX;
	int m_nY;
};
}
#endif