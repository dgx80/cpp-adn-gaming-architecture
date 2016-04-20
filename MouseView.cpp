#include "MouseView.h"



// namespace
namespace DX
{
namespace
{
	const DX::Point c_oPos = DX::Point(kDx::_DX_SCREEN_WIDTH-50,15);
	const char * c_szFormat = "(%d, %d)";
}
namespace Debug
{
MouseView::MouseView()
: Text()
{
	SetPosition( c_oPos );
}

void MouseView::OnMouseMove(const Point &pt)
{
	m_oPos = pt;
	str s = "";
	s.format(c_szFormat,m_oPos.GetX(),m_oPos.GetY() );
	SetText( s.c_str() );
}
// close
}// end namespace Debug
}// end namespace DX
