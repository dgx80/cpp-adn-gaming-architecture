#ifndef _DX_Cell_h
#define _DX_Cell_h

#include "DXDefine.h"
#include "Quadrilatere.h"
#include "PinPointSet.h"

#ifdef _DEBUG_ADN_CELL
#include "Text.h"
#include "Data.h"
#endif //_DEBUG_ADN_CELL

// namespace
namespace DX
{
namespace adn
{
	class Cell : public DX::Graphic::Quadrilatere
{
public:
	// Constructors
	Cell(const Point &pos = Point(), const Prop &dim = Prop(_DX_ADN_CELL_SIDE,_DX_ADN_CELL_SIDE));
	// Destructor
	virtual ~Cell();

	virtual void Draw()const;
	virtual bool OnMouseMove(const Point& oPoint);
	virtual bool OnMouseDown(const Point& oPoint);
	virtual bool OnMouseUp(const Point& oPoint);
	virtual bool OnKeyDown(char key, uint32_t flags);

	virtual void SetDimension( const Prop & dim ); 
	virtual void SetColor(const DX::Graphic::Color & oCol);

	void CreateMoleChild();
	void RemoveMoleChild();

#ifdef _DEBUG_ADN_CELL
	void CreateDebugData();
	void SetText(const dxString& s)
	{
		m_oText.SetText(s.c_str());
	}
#endif

	virtual void SetX(const int &a_nX);
	virtual void SetY(const int &a_nY);

private:

#ifdef _DEBUG_ADN_CELL
	DX::Graphic::Text m_oText;
	DX::Data::DataTable m_oDebugData;
#endif 

	
	DX::Canevas::PinPointSet m_oPinPointSet;

	Mole *m_poMoleChild;
	static int s_CellsCounter;
};
}// adn namespace end
}// DX namespace end
#endif
