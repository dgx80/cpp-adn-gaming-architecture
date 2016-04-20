#ifndef _DX_PinPointSet_h
#define _DX_PinPointSet_h

#include "DXDefine.h"
#include "Point.h"

//Cette classe est un conteneur de 9 points dans un carrer pour avoir constamment
//en memoire les extremiter et la demi longueur.
// namespace
namespace DX
{
namespace Canevas
{
class PinPointSet
{
public:
	// Constructors
	PinPointSet(const Point &pos = Point(),const Prop &val = Prop(64,64))
		: m_Proportion(val)
	{
		UpdateSet(pos);
#ifdef _DEBUG_PIN_POINT_SET
		int min = 0;
		int max = 9;

		for(int i = min; i < max;i++)
		{
			m_aPoint[i].SetColor(Graphic::Color::PalBlood());
		}
#endif
	}
	// Destructor
	virtual ~PinPointSet(){}

	const Prop& GetProportion() {return m_Proportion;}
	void SetProportion(const Prop& oProportion) {m_Proportion = oProportion;}

	void UpdateSet( const Point& oPtTopLeft)
	{
		using namespace DX::kDx;

		int x1,x2,x3,y1,y2,y3;
		x1 = oPtTopLeft.GetX();
		y1 = oPtTopLeft.GetY();

		x2 = x1 + m_Proportion.width/2;
		y2 = y1 + m_Proportion.height/2;

		x3 = x1 + m_Proportion.width;
		y3 = y1 + m_Proportion.height;


		m_aPoint[POS_TOPLEFT]		= Point(x1, y1);
		m_aPoint[POS_TOPCENTER]		= Point(x2, y1);
		m_aPoint[POS_TOPRIGHT]		= Point(x3, y1);
		m_aPoint[POS_CENTERLEFT]	= Point(x1, y2);
		m_aPoint[POS_CENTER]		= Point(x2, y2);
		m_aPoint[POS_CENTERRIGHT]	= Point(x3, y2);
		m_aPoint[POS_BOTTOMLEFT]	= Point(x1, y3);
		m_aPoint[POS_BOTTOMCENTER]	= Point(x2, y3);
		m_aPoint[POS_BOTTOMRIGHT]	= Point(x3, y3);
	}

#ifdef _DEBUG_PIN_POINT_SET
	void SetVisible(bool val = false)
	{
		int min = 0;
		int max = 9;

		for(int i = min; i < max;i++)
		{
			m_aPoint[i].SetVisible(val);
		}
	}
	DX::Graphic::Pixel m_aPoint[DX::kDx::POS_COUNT];
#else
	Point m_aPoint[DX::kDx::POS_COUNT];
#endif
	Prop m_Proportion;

};
}// Canevas namespace end
}// DX namespace end
#endif
