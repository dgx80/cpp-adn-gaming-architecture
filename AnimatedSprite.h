#pragma once
#ifndef _DX_AnimatedSprite_h
#define _DX_AnimatedSprite_hg


#include "DXDefine.h"
#include "Image.h"

namespace DX
{
namespace Graphic
{
class AnimatedSprite :	public DX::Graphic::Image
{
public:
	AnimatedSprite(const DX::Point & oPosition = DX::Point(), const str & a_sFileName = "");
	virtual ~AnimatedSprite();

	virtual void Load(const str & a_sFileName);

	virtual void Play(const str & a_sAnimationName);
	virtual void Stop();
	virtual void Pause();


private:
 
	TAnimatedSpriteRef GetAnimatedSprite();


};
}//Graphic
}//DX
#endif