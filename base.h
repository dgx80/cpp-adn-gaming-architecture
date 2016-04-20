#pragma once
#ifndef _DX_Base_h
#define _DX_Base_h

#include <stdlib.h>

namespace DX
{
class base
{

private:
	static int s_nCounter;
	int m_nId;
	
public:
	base(void);
	virtual ~base(void);

	int GetId(){ return m_nId;}
};
}
#endif