#include "Cell.h"
#include "Mole.h"

// namespace
namespace DX
{
	using namespace Graphic;
	using namespace Math;
namespace adn
{

int Cell::s_CellsCounter = 0;

Cell::Cell(const Point &pos, const Prop &dim)
	: Quadrilatere( pos, dim )
	, m_oPinPointSet(pos,dim)
	, m_poMoleChild(NULL)
#ifdef _DEBUG_ADN_CELL
	, m_oDebugData(0,0)
#endif
{

#ifdef _DEBUG_ADN_CELL
	dxString s;
	s.format("%d",s_CellsCounter);
	m_oText.SetText(s.c_str());
	m_oText.SetColor(DX::Graphic::Color(255,0,0,255));
	s_CellsCounter++;
	SetColor(Color::PalSea());
	DEBUG_WRITE(("%d\n", s_CellsCounter));
#endif //_DEBUG_ADN_CELL
	SetX(GetX());
	SetY(GetY());

}
Cell::~Cell()
{
	RemoveMoleChild();
	
#ifdef _DEBUG_ADN_CELL
	s_CellsCounter--;
#endif
}

void Cell::Draw()const
{
#ifdef _DEBUG_ADN_CELL
	Quadrilatere::Draw();
#endif

	if( m_poMoleChild )
	{
		m_poMoleChild->Draw();
	}
#ifdef _DEBUG_ADN_CELL
	m_oText.Draw();
#endif 
}
bool Cell::OnMouseDown(const DX::Point &/*oPoint*/)
{
	return false;
}
bool Cell::OnMouseUp(const DX::Point &/*oPoint*/)
{
	return false;
}
bool Cell::OnKeyDown(char key, uint32_t flags)
{
	return false;
}
bool Cell::OnMouseMove(const DX::Point &/*oPoint*/)
{
	return false;
}
void  Cell::SetDimension(const DX::Prop &dim)
{
	Graphic::Quadrilatere::SetDimension(dim);
	
	m_oPinPointSet.SetProportion(dim);
	m_oPinPointSet.UpdateSet(*this);

	if(m_poMoleChild)
	{
		m_poMoleChild->SetDimension(dim);
	}
#ifdef _DEBUG_ADN_CELL
	m_oText.SetPosition(m_oPinPointSet.m_aPoint[kDx::POS_CENTER]);
#endif 


}
void Cell::SetX(const int &a_nX)
{
	Graphic::Quadrilatere::SetX(a_nX);
	m_oPinPointSet.UpdateSet(*this);
	if( m_poMoleChild )
	{
		m_poMoleChild->SetX(a_nX);
	}
#ifdef _DEBUG_ADN_CELL
	m_oText.SetX( m_oPinPointSet.m_aPoint[kDx::POS_CENTER].GetX());
#endif

}
void Cell::SetY(const int &a_nY)
{
	Graphic::Quadrilatere::SetY(a_nY);
	m_oPinPointSet.UpdateSet(*this);
	
	if( m_poMoleChild )
	{
		m_poMoleChild->SetY(a_nY);
	}
#ifdef _DEBUG_ADN_CELL
	m_oText.SetY( m_oPinPointSet.m_aPoint[kDx::POS_CENTER].GetY());
#endif
}
void Cell::CreateMoleChild()
{
	if( !m_poMoleChild )
	{
		m_poMoleChild = new Mole(*this, GetProportion());
	}
	else
	{
		m_poMoleChild->FractionateMole();
	}
}
void Cell::RemoveMoleChild()
{
	if( m_poMoleChild )
	{
		m_poMoleChild->FusionateMole();
		delete m_poMoleChild;
	}
}
void Cell::SetColor(const Graphic::Color &oCol)
{
	Graphic::Quadrilatere::SetColor(oCol);
}
#ifdef _DEBUG_ADN_CELL
void Cell::CreateDebugData()
{
}
#endif
// close
}// adn namespace end
}// DX namespace end
