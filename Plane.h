#ifndef _DX_Plane_h
#define _DX_Plane_h

#include "DXDefine.h"
#include "Cell.h"
#include <vector>

// namespace
namespace DX
{
namespace adn
{
	class Plane : public Cell
{
public:
	// Constructors
	Plane();
	// Destructor
	virtual ~Plane(){}

	void CreatePlanarCells( const Math::Proportion & oCellsCount = Math::Proportion(4,4) , 
							const Math::Proportion & oCellDim = Math::Proportion(8,8) );


private:

	CellsMap m_mCells;

};
}// adn namespace end
}// DX namespace end
#endif
