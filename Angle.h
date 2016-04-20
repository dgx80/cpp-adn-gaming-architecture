#pragma once
#ifndef _DX_Angle_h
#define _DX_Angle_h

#include "DXDefine.h"
#include "base.h"

namespace DX
{
namespace Math
{ 
class Angle :
	public DX::base
{
public:
	Angle(void)
		: m_oDegre(0)
		, m_fRad(0.0f)
	{
	}
	Angle(const int &nDeg)
		: m_oDegre(nDeg)
		, m_fRad(0.0f)
	{
		UpdateRadianFromThisDegre();
	}

	virtual ~Angle(void){};


	void SetDegre(const int &oDeg)
	{
		m_oDegre = oDeg;
		UpdateRadianFromThisDegre();
	}
	void SetRadian(const float &fRad)
	{
		m_fRad = fRad;
		UpdateDegreFromThisRad();
	}
	const int &GetDegre() const{return m_oDegre;}
	const float &GetRadian() const{return m_fRad;}

protected:

private:

	void UpdateDegreFromThisRad();
	void UpdateRadianFromThisDegre();

	int m_oDegre;
	float m_fRad;
public:
	//operators surcharge
	virtual Angle &operator=( const int & a_rOther )
	{
		SetDegre( a_rOther );
		return *this;
	}
};
inline void Angle::UpdateDegreFromThisRad()
{
	m_oDegre = static_cast<int>(_DX_CONST_360 *  static_cast<double>(m_fRad) / (2*_DX_PI));
}
inline void Angle::UpdateRadianFromThisDegre()
{
	m_fRad = static_cast<float>((2*_DX_PI) * static_cast<double>(m_oDegre) / _DX_CONST_360);
}
}
}
#endif