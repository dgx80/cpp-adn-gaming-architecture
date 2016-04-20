#include "Vect2.h"

#include <math.h>
#include "Drawer.h"
#include "Convertion.h"


namespace DX
{
namespace Graphic
{

Vect2::Vect2( const Point & a_rOrigin, float a_fLenght, const int &a_nDegre )
: Canevas::RollerPin(a_rOrigin,a_nDegre)
, m_fLenght(a_fLenght)
{
	InitVect2();
}
Vect2::~Vect2(void)
{
}
void Vect2::InitVect2()
{
	UpdateDestination();
}

void Vect2::Draw() const
{
	DX::Graphic::Drawer::DrawLine(*this,m_oDest,GetColor());
}
void Vect2::SetLenght( const float &a_fPoint )
{
	m_fLenght = a_fPoint;
	UpdateDestination();
}
void Vect2::UpdateDestination()
{
	m_oDest = *this;

	UpdateDirection();
	m_oDest += m_oDirection;
}
void Vect2::UpdateDirection()
{
	m_oDirection = Point::CalculatePointFrom(m_fLenght,GetRadian());
}
void Vect2::SetDegre( const int & a_nDeg )
{
	Canevas::RollerPin::SetDegre(a_nDeg);
	UpdateDestination();
}
void Vect2::SetRadian( const float &a_fRad )
{
	Canevas::RollerPin::SetRadian(a_fRad);
	UpdateDestination();
}
}
}

