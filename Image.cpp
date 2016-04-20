#include "Image.h"

#include <pf/sprite.h>

namespace DX
{
namespace Graphic
{

Image::Image(const DX::Point & oPosition)
: Mole(oPosition)
, m_spSprite(TSpriteRef())
, m_ePositionType(kDx::POS_TOPLEFT)
, m_bDebugMole(false)
{
}
Image::~Image()
{
	m_spSprite = TSpriteRef();
}
void Image::Load(const str &/*a_sFileName*/)
{
	SetPositionType(m_ePositionType);
}
void Image::SetVisible(bool val)
{
	if(val != IsVisible())
	{
		if(m_spSprite != TSpriteRef())
		{
			m_spSprite->SetVisible(val);
		}
		Mole::SetVisible(val);
	}
}
void Image::Draw() const
{
	if(m_spSprite != TSpriteRef())
	{
		m_spSprite->Draw();
	}
	if(m_bDebugMole)
	{
		Mole::Draw();
	}
}
void Image::SetX(const int &a_nX)
{	
	if(m_spSprite != TSpriteRef())
	{
		m_spSprite->GetDrawSpec().mMatrix[2].x = static_cast<float>(a_nX + m_oImageOffset.GetX());
	}
	Mole::SetX(a_nX);
}
void Image::SetY(const int &a_nY)
{	
	if(m_spSprite != TSpriteRef())
	{
		m_spSprite->GetDrawSpec().mMatrix[2].y = static_cast<float>(a_nY + m_oImageOffset.GetY());
	}
	Mole::SetY(a_nY);
}
void Image::SetPositionType(DX::kDx::ePositionType a_ePositionType)
{
	m_ePositionType = a_ePositionType;
	int w = GetProportion().width;
	int h = GetProportion().height;

	switch( m_ePositionType )
	{
	case kDx::POS_TOPLEFT:
		m_oImageOffset = DX::Point((w/2),(h/2));
		SetMoleOriginOffset(DX::Point(0,0));
		break;
	case kDx::POS_TOPCENTER:
		m_oImageOffset = DX::Point(0,(h/2));
		SetMoleOriginOffset( DX::Point(-(w/2),0) );
		break;
	case kDx::POS_TOPRIGHT:
		m_oImageOffset = DX::Point(-(w/2),(h/2));
		SetMoleOriginOffset( DX::Point(-(w),0) );
		break;
	case kDx::POS_CENTERLEFT:
		m_oImageOffset = DX::Point((w/2),0);
		SetMoleOriginOffset( DX::Point(0,-(h/2)) );
		break;
	case kDx::POS_CENTER:
		m_oImageOffset = DX::Point(0,0);
		SetMoleOriginOffset( DX::Point(-(w/2),-(h/2)) );
		break;
	case kDx::POS_CENTERRIGHT:
		m_oImageOffset = DX::Point(-(w/2),0);
		SetMoleOriginOffset( DX::Point(-(w),-(h/2)) );
		break;
	case kDx::POS_BOTTOMLEFT:
		m_oImageOffset = DX::Point((w/2),-(h/2));
		SetMoleOriginOffset( DX::Point(0,-(h)) );
		break;
	case kDx::POS_BOTTOMCENTER:
		m_oImageOffset = DX::Point(0,-(h/2));
		SetMoleOriginOffset( DX::Point(-(w/2),-(h)) );
		break;
	case kDx::POS_BOTTOMRIGHT:
		m_oImageOffset = DX::Point(-(w/2),-(h/2));
		SetMoleOriginOffset( DX::Point(-(w),-(h)) );
		break;
	}
}
}//Graphic
}//DX	