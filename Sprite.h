#pragma once
#ifndef _DX_Sprite_h
#define _DX_Sprite_h

#include "Image.h"
#include "DXDefine.h"

#include <pf/pflib.h>


namespace DX
{
namespace Graphic
{
class Sprite :	public Image
{
public:
	Sprite(const DX::Point & oPosition = DX::Point(), const str & a_sFileName = "");
	virtual ~Sprite();	

	virtual void Load(const str & a_sFileName);

	virtual void SetX(const int &a_nX);
	virtual void SetY(const int &a_nY);


private:

};
}//Graphic
}//DX
#endif