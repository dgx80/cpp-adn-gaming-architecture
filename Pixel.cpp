#include "Pixel.h"

#include "SceneManager.h"
#include "Scene.h"
#include "RendererAdmin.h"
#include "RenderingUnit.h"

#include <pf/sprite.h>
#include <pf/drawspec.h>
#include <assert.h>
#include "Drawer.h"

namespace DX
{
namespace Graphic
{
	
Pixel::Pixel(const DX::Point &point, const float &fXSpeed,const float &fYSpeed, const int &a_nPixPerMeter)
: Physics::KineticParticule(point,fXSpeed,fYSpeed,a_nPixPerMeter)
	, m_pCurrentRenderingUnit(NULL)
	, m_bVisible(false)
{
	InitPixel();
}
Pixel::~Pixel()
{
	if( m_bVisible )
	{
		SetVisible(false);
	}
}

void Pixel::InitPixel()
{
	SetColor( Color(255,0,0,255));
}

void Pixel::Draw() const
{
	DX::Graphic::Drawer::DrawPixel(*this,m_oColor);
}
void Pixel::SetVisible(bool val)
{	
	if(val)
	{
		if(!m_bVisible)
		{
			m_pCurrentRenderingUnit = DX::Time::SceneManager::GetFocusScene().GetRenderer().UpdateRenderingPixel(*this);
		}
	}
	else
	{
		if(m_pCurrentRenderingUnit!= NULL)
		{
			m_pCurrentRenderingUnit->RemovePixel(*this);
			m_pCurrentRenderingUnit = NULL;
		}
	}

	m_bVisible = val;
}
void Pixel::SetColor(const DX::Graphic::Color &oCol)
{
		m_oColor = oCol;
}
} //Graphic
} //DX