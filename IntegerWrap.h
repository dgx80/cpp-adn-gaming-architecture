#pragma once
#ifndef _DX_IntegerWrap_h
#define _DX_IntegerWrap_h

#include "base.h"

namespace DX
{
namespace CORE
{
class IntegerWrap :
	public DX::base
{
public:

	virtual const int &GetValue()const {return m_nValue; }
	virtual void SetValue(int n){m_nValue = n; }

	bool operator ==(int n){return ( m_nValue == n ); }
	bool operator !=(int n){return (m_nValue != n);}
	
	IntegerWrap operator +(const IntegerWrap & a_rOther){return IntegerWrap(m_nValue + a_rOther.GetValue());}
	IntegerWrap operator -(const IntegerWrap & a_rOther){return IntegerWrap(m_nValue - a_rOther.GetValue());}
	IntegerWrap operator /(const IntegerWrap & a_rOther){return IntegerWrap(m_nValue / a_rOther.GetValue());}
	IntegerWrap operator *(const IntegerWrap & a_rOther){return IntegerWrap(m_nValue * a_rOther.GetValue());}

	void operator +=(const IntegerWrap & a_rOther){m_nValue += a_rOther.GetValue();}
	void operator -=(const IntegerWrap & a_rOther){m_nValue -= a_rOther.GetValue();}
	void operator *=(const IntegerWrap & a_rOther){m_nValue *= a_rOther.GetValue();}
	void operator /=(const IntegerWrap & a_rOther){m_nValue /= a_rOther.GetValue();}


protected:
	IntegerWrap() : m_nValue(0){}
	IntegerWrap(int n) : m_nValue(n){}

	virtual ~IntegerWrap(void){};


public:

	int m_nValue;
};
}
}
#endif