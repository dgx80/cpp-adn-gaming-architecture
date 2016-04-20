#ifndef _DX_Quadrilatere_h
#define _DX_Quadrilatere_h

#include "RollerPin.h"
#include "Dimension.h"
#include "Vect2.h"
#include "PythagoreSet.h"

// namespace
namespace DX
{
namespace Graphic
{
class Quadrilatere : public Canevas::RollerPin
{
public:
	Quadrilatere(const DX::Point &pos = DX::Point(), const Prop & dim = Prop(0,0));
	
	virtual ~Quadrilatere(){}

	virtual void SetDimension( const Prop & dim ); 
	virtual void Draw()const;
	
	virtual void SetDegre( const int &a_nDeg );
	virtual void SetColor(const Color & oCol);

	const int & GetHeight() const{return m_oProportion.height;}
	const int & GetWidth()const{return m_oProportion.width;}

	const Prop & GetProportion(){ return m_oProportion;}

	virtual void SetX(const int &a_nX);
	virtual void SetY(const int &a_nY);

private:
	Prop m_oProportion;
	Math::Dimension m_oDim;
	DX::Math::PythagoreSet m_oTransversalTrigoSet;
	Point m_oTransversalPt;
};
}// end namespace Graphic
}// end namespace DX
#endif



