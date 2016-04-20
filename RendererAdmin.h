#ifndef _DX_RendererAdmin_h
#define _DX_RendererAdmin_h

#include "DXDefine.h"
#include "RenderingUnit.h"
// namespace
namespace DX
{
namespace Renderer
{
class RendererAdmin
{
public:
	friend class Pixel;

	RendererAdmin();
	virtual ~RendererAdmin(){}

	void Draw();

	RenderingUnit* UpdateRenderingPixel( const Graphic::Pixel & pix );


private:

	//tempory SingleUnit
	RenderingUnit m_oRenderingUnit;
};
}// end namespace Renderer
}// end namespace DX
#endif
