#include "Quadrilatere.h"


// namespace
namespace DX
{
namespace Graphic
{
Quadrilatere::Quadrilatere(const DX::Point &pos,const Prop & dim)
: Canevas::RollerPin(pos)
{
	SetDimension(dim);
	SetX(GetX());
	SetY(GetY());
}
void Quadrilatere::Draw() const
{
	Pixel::Draw();
	m_oDim.Draw();
	m_oDim.DrawSymetric();
}
void Quadrilatere::SetDimension( const Prop & dim )
{ 
	m_oDim = Math::Dimension(dim.width,dim.height); 	
	m_oProportion = dim;
}
void Quadrilatere::SetDegre( const int &a_nDeg )
{
	Canevas::RollerPin::SetDegre(a_nDeg);
	m_oDim.SetDegre(a_nDeg);
}
void Quadrilatere::SetColor(const Color & oCol)
{
	Pixel::SetColor(oCol);
	m_oDim.SetColor(oCol);
}
void Quadrilatere::SetX(const int &a_nX)
{
	Point::SetX(a_nX);
	m_oDim.SetX(a_nX);
	m_oTransversalPt.SetX( m_oDim.GetX() + m_oTransversalTrigoSet.GetSide().GetX());
}
void Quadrilatere::SetY(const int &a_nY)
{
	Point::SetY(a_nY);
	m_oDim.SetY(a_nY);
	m_oTransversalPt.SetY( m_oDim.GetY() + m_oTransversalTrigoSet.GetSide().GetY());
}
// close
}// end namespace Graphic
}// end namespace DX
