#ifndef _DX_Proportion_h
#define _DX_Proportion_h

#include "DXDefine.h"


// namespace
namespace DX
{
namespace Math
{
class Proportion
{
public:
	// Constructors
	Proportion(int w = 0, int h = 0)
		: width(w)
		, height(h)
	{}
	// Destructor
	virtual ~Proportion(){}

	int width;
	int height;
private:
};
}// Math namespace end
}// DX namespace end
#endif
