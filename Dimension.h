#ifndef _DX_Dimension_h
#define _DX_Dimension_h

#include "DXDefine.h"
#include "Vect2.h"
#include "Pixel.h"
#include "Drawer.h"

// namespace
namespace DX
{
namespace Math
{
class Dimension
	: public Graphic::Pixel
{
public:
	Dimension(const int & width = 0, const int & height = 0)
		: Pixel()
		, m_oWidth(Point(),static_cast<float>(width),0)
		, m_oHeight(Point(),static_cast<float>(height),_DX_CONST_90)
	{
	}
	virtual ~Dimension(){}

	virtual void Draw()const
	{
		m_oWidth.Draw();
		m_oHeight.Draw();
	}
	virtual void DrawSymetric()const
	{
		const DX::Point &upRight = m_oWidth.GetDestination();
		const DX::Point &botLeft = m_oHeight.GetDestination();
		DX::Point pt(upRight.GetX(),botLeft.GetY());

		DX::Graphic::Drawer::DrawLine(upRight, pt ,GetColor());
		DX::Graphic::Drawer::DrawLine(botLeft, Point(pt.GetX(),pt.GetY()-1), GetColor() );
	}

	const float &GetWidth() const{ return m_oWidth.GetLenght(); }
	const float &GetHeight() const{ return m_oHeight.GetLenght(); }

	void SetWidth(const float &val) { m_oWidth.SetLenght(val); }
	void SetHeight(const float &val){ m_oHeight.SetLenght(val); }

	virtual void SetColor(const Graphic::Color & oCol)
	{ 
		Pixel::SetColor(oCol);
		m_oWidth.SetColor(oCol);
		m_oHeight.SetColor(oCol);
	}

	void SetDegre(const int & nDeg)
	{
		m_oWidth.SetDegre(nDeg);
		m_oHeight.SetDegre(nDeg+_DX_CONST_90);
	}
private:

	Graphic::Vect2 m_oWidth;
	Graphic::Vect2 m_oHeight;

public:
	virtual void SetX(const int &a_nX)
	{
		Point::SetX(a_nX);
		m_oWidth.SetX(a_nX);
		m_oHeight.SetX(a_nX);
	}
	virtual void SetY(const int &a_nY)
	{
		Point::SetY(a_nY);
		m_oWidth.SetY(a_nY);
		m_oHeight.SetY(a_nY);
	}

	Dimension &operator=( const Dimension & a_rOther )
	{
		m_oWidth.SetLenght(a_rOther.GetWidth());
		m_oHeight.SetLenght(a_rOther.GetHeight());

		SetX(a_rOther.GetX());
		SetY(a_rOther.GetY());
		return *this;
	}
};
}// end namespace Math
}// end namespace DX
#endif
