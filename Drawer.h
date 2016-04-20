#pragma once
#ifndef _DX_Drawer_h
#define _DX_Drawer_h

#include <pf/pflib.h>
#include "DXDefine.h"
#include "Color.h"

namespace DX
{
namespace Graphic
{
class Drawer 
{
public:

	static void DrawLine( const DX::Point & ptO,const DX::Point & ptD, const DX::Graphic::Color & rColor = Color() );
	static void DrawLine( const DX::Graphic::Vect2 & oVec , const DX::Graphic::Color & rColor = Color());
	static void DrawPixel( const DX::Point & Pt, const DX::Graphic::Color & rColor = Color() );

};
}//Graphic
}//DX
#endif