#ifndef _DX_MouseView_h
#define _DX_MouseView_h

#include "Text.h"

#include "DXDefine.h"
#include <pf/pflib.h>

// namespace
namespace DX
{
namespace Debug
{
class MouseView
	: public Graphic::Text
{
public:
	MouseView();
	virtual ~MouseView(){}

	void OnMouseMove(const Point & pt);

protected:
	

private:

	Point m_oPos;
};
}// end namespace Debug
}// end namespace DX
#endif
