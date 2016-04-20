#ifndef _DX_PixelStack_h
#define _DX_PixelStack_h

#pragma once
#include "AdnStack.h"
#include "Pixel.h"

// namespace
namespace DX
{
namespace Core
{
class PixelStack : public AdnStack<Graphic::Pixel>
{
public:
	PixelStack()
		: m_iCurrentIter(m_lpoAdn.begin())
	{
	}
	virtual ~PixelStack(void){}


	const Graphic::Pixel* FirstPixel()
	{
		if(Empty())
		{
			return NULL;
		}
		m_iCurrentIter = m_lpoAdn.begin();
		return *m_iCurrentIter;
	}

	const Graphic::Pixel* NextPixel()
	{
		if(++m_iCurrentIter == m_lpoAdn.end())
			return NULL;
		return *(m_iCurrentIter);
	}

private:

	std::list<const Graphic::Pixel*>::const_iterator m_iCurrentIter;

};
}//Core
}//DX
#endif