#ifndef _DX_PythagoreSet_h
#define _DX_PythagoreSet_h

#include <math.h>
#include "DXDefine.h"
#include "Point.h"
// namespace
namespace DX
{
namespace Math
{
class PythagoreSet
{
public:
	PythagoreSet(const float &fHypothenuse, const Angle& oAngle )
	: m_fHypothenuse(fHypothenuse)
	{
		SetTeta(oAngle);
	}

	PythagoreSet(const Point &oSide = Point(0,0))
		: m_fHypothenuse(0.0f)
	{
		SetSide(oSide);
	}

	virtual ~PythagoreSet(){}

	void SetTeta( const Angle & val ) 
	{ 
		//note the hypothenuse doesn't change
		m_oTeta = val;
		UpdateSide(m_fHypothenuse, m_oTeta);
	}
	void SetHypothenuse( const float & val ) 
	{ 
		m_fHypothenuse = val;
		UpdateSide(m_fHypothenuse, m_oTeta);
	}
	void SetSide( const Point & val ) 
	{ 
		m_oSide = val;
		UpdateHypothenuse(m_oSide);
		UpdateTeta(m_oSide);
	}

	const Point& GetSide() const { return m_oSide; }
	const Angle& GetTeta() const { return m_oTeta; }
	const float& GetHypothenuse() const { return m_fHypothenuse; }

private:

	void UpdateSide(const float& fHypothenuse, const Angle& oTeta)
	{	
		m_oSide = Point::CalculatePointFrom(fHypothenuse, oTeta.GetRadian());
	}
	void UpdateHypothenuse(const Point& oSide)
	{
		oSide.CalculateHypothenuse(m_fHypothenuse);
	}
	void UpdateTeta(const Point& oSide)
	{
		float fRad = 0.0f;
		oSide.CalculateTeta(fRad);
		m_oTeta.SetRadian( fRad ); 
	}

	Point m_oSide;
	float m_fHypothenuse;
	Angle m_oTeta;
};
}// Math namespace end
}// DX namespace end
#endif


