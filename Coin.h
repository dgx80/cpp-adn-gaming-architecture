#ifndef _DX_Coin_h
#define _DX_Coin_h

#include "DXDefine.h"
#include "Vect2.h"

// namespace
namespace DX
{
namespace Graphic
{
class Coin 
	: public Vect2
{
public:
	Coin()
		: Vect2() 
		, m_oSlaveVect(Point(),0,_DX_CONST_90)
	{
	}
	Coin(const int & width, const int & height)
		: Vect2(Point(),static_cast<float>(width),0)
		, m_oSlaveVect(Point(),static_cast<float>(height),_DX_CONST_90)
	{
	}
	virtual ~Coin(){}

	virtual void Draw()const
	{
		Vect2::Pixel::Draw();

		m_oSlaveVect.Draw();
	}

	const float &GetSlaveVect() const{ return m_oSlaveVect.GetLenght(); }

	void SetSlaveVect(const float &val){ m_oSlaveVect.SetLenght(val); }

	virtual void SetColor(const Graphic::Color & oCol)
	{ 
		Vect2::SetColor(oCol);
		m_oSlaveVect.SetColor(oCol);
	}

	void SetDegre(const int & nDeg)
	{
		SetDegre(nDeg);
		m_oSlaveVect.SetDegre(nDeg+_DX_CONST_90);
	}
private:

	Graphic::Vect2 m_oSlaveVect;

public:
	virtual Point &operator=( const Coin & a_rOther )
	{
		m_oSlaveVect.SetLenght(a_rOther.GetSlaveVect());
		return Pixel::operator =(a_rOther);
	}
	virtual Point &operator=( const Point & a_rOther )
	{
		m_oSlaveVect = a_rOther;
		return Pixel::operator =(a_rOther);
	}
};
}// Graphic namespace end
}// DX namespace end
#endif
