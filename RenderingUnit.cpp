#include "RenderingUnit.h"


#include "Pixel.h"

#include <assert.h>

// namespace
namespace DX
{
namespace Renderer
{
RenderingUnit::RenderingUnit()
{
}
void RenderingUnit::AddPixel(const DX::Graphic::Pixel &pix)
{
	m_stkPixel.PushBackAdn(pix);
}
void RenderingUnit::RemovePixel(const DX::Graphic::Pixel &pix)
{
	m_stkPixel.EraseAdn(pix);
}
void RenderingUnit::Draw()
{
	DrawPixel();
}
void RenderingUnit::DrawPixel()
{

	const DX::Graphic::Pixel* pix = m_stkPixel.FirstPixel();

	while(pix != NULL)
	{
		pix->Draw();
		pix = m_stkPixel.NextPixel();
	}

}
// close
}// end namespace Graphic
}// end namespace DX
