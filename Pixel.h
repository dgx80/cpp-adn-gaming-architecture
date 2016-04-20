#pragma once
#ifndef _DX_Pixel_h
#define _DX_Pixel_h

#include "KineticParticule.h"
#include "DXDefine.h"

#include <pf/pflib.h>
#include "Color.h"

namespace DX
{
namespace Graphic
{
	class Pixel : public Physics::KineticParticule
{
public:

	//constructors/destructors
	Pixel(const Point & point = Point(), const float &fXSpeed=0.0f,const float &fYSpeed=0.0f,
		const int &a_nPixPerMeter = 10);
	virtual ~Pixel();

	const Color& GetColor() const { return m_oColor; }

	virtual void SetColor(const Color & oCol);

	void SetVisible(bool val = false);
	bool IsVisible() { return m_bVisible;}

	virtual void Draw()const;

protected:
	

	virtual void InitPixel();
private:


	Color m_oColor;
	bool m_bVisible;
	DX::Renderer::RenderingUnit *m_pCurrentRenderingUnit;

public:

};

} //Graphic
} //DX

#endif