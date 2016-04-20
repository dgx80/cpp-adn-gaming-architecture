#pragma once
#ifndef _DX_Degre_h
#define _DX_Degre_h

#include "IntegerWrap.h"

namespace DX
{
namespace Math
{ 
class Degre :
	public DX::CORE::IntegerWrap
{
public:
	Degre(void){};
	Degre(int nDeg): CORE::IntegerWrap(nDeg){}
	virtual ~Degre(void){};

};
}
}
#endif