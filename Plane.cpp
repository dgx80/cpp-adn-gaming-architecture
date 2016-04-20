#include "Plane.h"


// namespace
namespace DX
{
namespace adn
{
Plane::Plane()
{
}
void Plane::CreatePlanarCells(	const Math::Proportion & oCellsCount, 
								const Math::Proportion & oCellDim)
{
	m_mCells.reserve(oCellsCount.height);

	for( int y = 0; y < oCellsCount.height; y++ )
	{
		CellsList oLst;
		oLst.reserve(oCellsCount.width);

		for( int x = 0; x < oCellsCount.width; x++ )
		{
			oLst.push_back(Cell( Point(), oCellDim ) );
		}
		m_mCells.push_back( oLst );
	}
}
// close
}// adn namespace end
}// DX namespace end
