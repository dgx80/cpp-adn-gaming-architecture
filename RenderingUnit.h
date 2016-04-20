#ifndef _DX_RenderingUnit_h
#define _DX_RenderingUnit_h

#include "DXDefine.h"
#include "PixelStack.h"

// namespace
namespace DX
{
namespace Renderer
{
class RenderingUnit
{
public:
	friend class RendererAdmin;
	friend class Graphic::Pixel;

	RenderingUnit();
	virtual ~RenderingUnit(){}

	void Draw();


private:

	void AddPixel( const DX::Graphic::Pixel & pix );
	void RemovePixel( const DX::Graphic::Pixel & pix );

	void DrawPixel();

	Core::PixelStack m_stkPixel;
};
}// end namespace Renderer
}// end namespace DX
#endif
