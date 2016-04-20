#ifndef _DX_PointStack_h
#define _DX_PointStack_h

#pragma once
#include "AdnStack.h"


// namespace
namespace DX
{
namespace Core
{
class PointStack : public AdnStack<Point>
{
public:
	PointStack(void)
		: m_iCurrentIter(m_lpoAdn.begin())
	{
	}
	virtual ~PointStack(void){}


	const Point* FirstPoint()
	{
		m_iCurrentIter = m_lpoAdn.begin();
		return *m_iCurrentIter;
	}

	const Point* NextPoint()
	{
		if(m_iCurrentIter == m_lpoAdn.end())
			return NULL;
		return *(++m_iCurrentIter);
	}

private:

	std::list<const Point*>::const_iterator m_iCurrentIter;

};
}//Core
}//DX
#endif