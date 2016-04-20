#pragma once
#ifndef _DX_Convertion_h
#define _DX_Convertion_h



#include <pf/pflib.h>
#include "DXDefine.h"
#include "Point.h"

namespace DX
{
namespace Toolbox
{
class Convertion
{
public:
	static void ObtainTVec2FromPoint(const DX::Point &a_rPoint, TVec2 &a_oVec)
	{
		a_oVec.x = static_cast<float>( a_rPoint.GetX() );
		a_oVec.y = static_cast<float>( a_rPoint.GetY() );
	}
};
}
}
#endif