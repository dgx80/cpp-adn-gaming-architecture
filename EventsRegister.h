#ifndef _DX_EventsRegister_h
#define _DX_EventsRegister_h

#include "DXDefine.h"
#include <list>

// namespace
namespace DX
{

class EventsRegister
{
public:
	EventsRegister(void);
	virtual ~EventsRegister(void);

	void AddUpdate(const Point& pt);
	void CancelUpdate(const Point& pt);

	void AddRendering(const Point& pt);
	void CancelRendering(const Point& pt);

	void Draw();
	void Update();

private:

//	PointStack m_DrawingStack;
//	PointStack m_UpdateStack;

};
}//DX
#endif