#include "RendererAdmin.h"



#include <assert.h>

// namespace
namespace DX
{
namespace Renderer
{
RendererAdmin::RendererAdmin()
{
}

void RendererAdmin::Draw()
{
	m_oRenderingUnit.Draw();
}
RenderingUnit* RendererAdmin::UpdateRenderingPixel( const Graphic::Pixel & pix )
{
	m_oRenderingUnit.AddPixel(pix);
	return &m_oRenderingUnit;
}

// close
}// end namespace Renderer
}// end namespace DX
