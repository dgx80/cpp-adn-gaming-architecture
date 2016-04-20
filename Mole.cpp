#include "Mole.h"

#include "Data.h"
// namespace
namespace DX
{
using namespace Graphic;
using namespace Math;

namespace adn
{

Mole::Mole(const DX::Point &pos, const Prop &dim)
:Cell(pos, dim)
, m_oOriginOffset(DX::Point(0,0))
 {
	SetColor(Color::PalBlood());
	InitMole();
	SetDimension(dim);
	SetPosition(GetPosition());
}

void Mole::InitMole()
{
	using namespace DX::Data;

	int n = 0;
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++)
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
#ifdef _DEBUG_ADN_CELL
			dxString s;
			s.format("%d",n++);
			m_mCells[y][x].SetText(s);
#endif
		}
	}
}
void Mole::SetColor(const Graphic::Color &oCol)
{
	Cell::SetColor(oCol);
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			m_mCells[x][y].SetColor(oCol);
		}
	}
}
void Mole::RefreshCellPosition()
{
	DX::Point oTopLeft = GetPosition() + m_oOriginOffset;
	int xSide = GetWidth()/_DX_ADN_MOLE_CASE; 
	int	ySide = GetHeight()/_DX_ADN_MOLE_CASE;
	Point ptOffset;
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		ptOffset.SetX(xSide*x);
		
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			ptOffset.SetY(ySide*y);
			m_mCells[x][y].SetPosition( oTopLeft + ptOffset );
		}
	}
}
void Mole::Draw() const
{
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			m_mCells[x][y].Draw();
		}
	}
}
void Mole::SetDimension(const DX::Prop &dim)
{
	Cell::SetDimension(dim);
	
	int xSide = GetWidth()/_DX_ADN_MOLE_CASE; 
	int	ySide = GetHeight()/_DX_ADN_MOLE_CASE;
	Prop oProp(xSide,ySide);

	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			m_mCells[x][y].SetDimension(oProp);
		}
	}
	RefreshCellPosition();
}
void Mole::FractionateMole()
{
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			m_mCells[x][y].CreateMoleChild();
		}
	}
}
void Mole::FusionateMole()
{
	for( int x = 0; x < _DX_ADN_MOLE_CASE; x++ )
	{
		for( int y = 0; y < _DX_ADN_MOLE_CASE; y++ )
		{
			m_mCells[x][y].RemoveMoleChild();
		}
	}
}
void Mole::SetX(const int &a_nX)
{
	Cell::SetX(a_nX);
	RefreshCellPosition();
}
void Mole::SetY(const int &a_nY)
{
	Cell::SetY(a_nY);
	RefreshCellPosition();
}
// close
}// adn namespace end
}// DX namespace end
