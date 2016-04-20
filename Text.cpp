#include "Text.h"

#include <pf/textsprite.h>
// namespace
namespace DX
{
namespace Graphic
{
Text::Text()
: Pixel()
{
	m_prTx = TTextSprite::Create( kDx::_DX_SCREEN_WIDTH,kDx::_DX_SCREEN_HEIGHT,5,"",18,TColor(1,1,1,1));
}
void Text::Draw() const
{
	m_prTx->Draw();
}
void Text::SetColor(const DX::Graphic::Color &oCol)
{
	Pixel::SetColor(oCol);
	m_prTx->SetColor(oCol.GetPFColor());
}
// close
}// Graphic namespace end
}// DX namespace end
