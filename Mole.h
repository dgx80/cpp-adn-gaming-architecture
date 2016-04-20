#ifndef _DX_Mole_h
#define _DX_Mole_h

#include "DXDefine.h"
#include "Cell.h"

// namespace
namespace DX
{
namespace adn
{
class Mole : public Cell
{
public:
	// Constructors
	Mole(const DX::Point &pos = DX::Point(), const Prop &dim = Prop( _DX_ADN_MOLE_SIDE,_DX_ADN_MOLE_SIDE));
	// Destructor
	virtual ~Mole(){}


	virtual void Draw() const;

	virtual void SetColor(const DX::Graphic::Color & oCol);	
	virtual void SetDimension( const Prop & dim );

	void SetMoleOriginOffset(const DX::Point& oOffset){m_oOriginOffset = oOffset;}

	void FractionateMole();
	void FusionateMole();

	virtual void SetX(const int &a_nX);
	virtual void SetY(const int &a_nY);

protected:

	void InitMole();

private:
	void RefreshCellPosition();

	Cell m_mCells[_DX_ADN_MOLE_CASE][_DX_ADN_MOLE_CASE];

	DX::Point m_oOriginOffset;
};
}// adn namespace end
}// DX namespace end
#endif
