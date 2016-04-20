#pragma once
#ifndef _DX_Color_h
#define _DX_Color_h

#include "base.h"
#include <pf/pflib.h>

namespace DX
{
namespace Graphic
{
class Color :
	public DX::base
{
public:
	Color()
        : r(255)
        , g(255)
        , b(255)
        , a(255)
    {
    };
    Color(int red, int green, int blue, int alpha)
        : r(red)
        , g(green)
        , b(blue)
        , a(alpha)
    {
    }

    void SetPFColor( const TColor & a_oPFColor )
    {
        a = static_cast<int>( a_oPFColor.a * 255 );
        r = static_cast<int>( a_oPFColor.r * 255 );
        g = static_cast<int>( a_oPFColor.g * 255 );
        b = static_cast<int>( a_oPFColor.b * 255 );
    }
    void SetColor( const Color & a_oColor )
    {
        a = a_oColor.a;
        r = a_oColor.r;
        g = a_oColor.g;
        b = a_oColor.b;
    }
    TColor GetPFColor() const
    {
        TColor oColor = TColor( static_cast<TReal>(r)/255, static_cast<TReal>(g)/255,static_cast<TReal>(b)/255,static_cast<TReal>(a)/255);
        return oColor;
    }
    bool IsColor( int a_r, int a_g, int a_b, int a_a )
    {
        return( r == a_r, g == a_g, b == a_b, a == a_a );
    }

	int r;
    int g;
    int b;
    int a;

	static Color PalBlood()
	{
		return Color(130,87,67,200);
	}
	static Color PalSea()
	{
		return Color(200,200,240,255);
	}
	static Color PalBlue()
	{
		return Color(0,0,255,255);
	}
	static Color PalRed()
	{
		return Color(255,0,0,255);
	}
	static Color PalGreen()
	{
		return Color(0,255,0,255);
	}
	static Color PalWhite()
	{
		return Color(255,255,255,255);
	}

};
} //Graphic
} //DX
#endif