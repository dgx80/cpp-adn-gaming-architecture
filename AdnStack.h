#ifndef _DX_AdnStack_h
#define _DX_AdnStack_h

#pragma once
#include "DXDefine.h"
#include <list>
#include <assert.h>


// namespace
namespace DX
{
namespace Core
{
template<typename T>
class AdnStack
{
public:
	AdnStack(void)
	{
	}
	virtual ~AdnStack(void){}

	inline void PushBackAdn( const T & adn )
	{
		const T * p = &adn;
		assert(p);

		if(!m_lpoAdn.empty())
		{
			std::list<const T *>::const_iterator iter = m_lpoAdn.begin();

			for( ; iter != m_lpoAdn.end();iter++)
			{
				if( *iter == p )
				{
					return;
				}
			}
		}
		m_lpoAdn.push_back(p);
	}
	inline void EraseAdn( const T & adn )
	{	
		const T * p = &adn;
		assert(p);

		std::list<const T*>::iterator iter;

		for( iter = m_lpoAdn.begin(); iter != m_lpoAdn.end();iter++)
		{
			if( *iter == p )
			{
				m_lpoAdn.erase(iter);
				break;
			}
		}
	}
	inline bool Empty()
	{
		return m_lpoAdn.empty();
	}
	inline int Count()
	{
		return static_cast<int>(m_lpoAdn.size());
	}

protected:

	std::list<const T*> m_lpoAdn;

};
}//Core
}//DX
#endif