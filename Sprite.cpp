#include "Sprite.h"

#include <pf/sprite.h>

namespace DX
{
namespace Graphic
{
Sprite::Sprite(const DX::Point & oPosition, const str & a_sFileName)
: Image(oPosition)
{
	if(a_sFileName != "")
	{
		Load(a_sFileName);
	}
	else
	{
		SetPositionType(GetPositionType());
	}
	SetX(GetX());
	SetY(GetY());
}
Sprite::~Sprite()
{

}
void Sprite::Load(const str &a_sFileName)
{
	TTextureRef tex = TTexture::Get(a_sFileName);
	ASSERT(tex != TTextureRef());
	TSpriteRef sprite = TSprite::Create(0,tex);
	ASSERT(sprite != TSpriteRef());
	SetSprite(sprite);
	
	SetDimension( DX::Prop(tex->GetWidth(),tex->GetHeight()) );
	Image::Load(a_sFileName);
	
}
void Sprite::SetX(const int &a_nX)
{	
	Image::SetX(a_nX);
}
void Sprite::SetY(const int &a_nY)
{	
	Image::SetY(a_nY);
}

}//Graphic
}//DX	