#include "AnimatedSprite.h"
#include "SceneManager.h"
#include <pf/animatedsprite.h>

namespace DX
{
namespace Graphic
{
AnimatedSprite::AnimatedSprite(const DX::Point &oPosition, const str &a_sFileName)
:Image(oPosition)
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
AnimatedSprite::~AnimatedSprite()
{
}
void AnimatedSprite::Load(const str &a_sFileName)
{
	TAnimatedTextureRef tex = DX::Time::SceneManager::GetAssetMap().GetAnimatedTexture(a_sFileName);
	ASSERT(tex != TTextureRef());
	TAnimatedSpriteRef anmsprite = TAnimatedSprite::Create(0);
	ASSERT(anmsprite != TAnimatedSpriteRef());

	anmsprite->SetTexture(tex);

	SetSprite(anmsprite);
	
	SetDimension( DX::Prop(tex->GetWidth(),tex->GetHeight()) );
	Image::Load(a_sFileName);
}
void AnimatedSprite::Play(const str &a_sAnimationName)
{
	GetAnimatedSprite()->Play(a_sAnimationName);
}
void AnimatedSprite::Stop()
{
	GetAnimatedSprite()->Stop();
}
void AnimatedSprite::Pause()
{
//	GetAnimatedSprite()->Pause();
}
TAnimatedSpriteRef AnimatedSprite::GetAnimatedSprite()
{
	TAnimatedSpriteRef ref = GetSprite()->GetCast<TAnimatedSprite>();

	ASSERT(ref != TAnimatedSpriteRef());
	return ref;
}
}//Graphic
}//DX