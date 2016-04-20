#ifndef _DX_ActionRotation_h
#define _DX_ActionRotation_h

#include "DXDefine.h"
#include "Actions.h"

// namespace
namespace DX
{
namespace Actions
{
class ActionRotation
	: public Actions
{
public:

	ActionRotation( const kDx::eTriggerType& trigType = kDx::knTriggerType_Loop,
					const kDx::eRotationType & rotType = kDx::knRotationType_Invalid, 
					const float& a_fHertz = 0.0f);

	virtual ~ActionRotation(){}

	const kDx::eRotationType&	GetRotationType() const { return m_eRotationType; }
	const float&			GetRadSec() const { return m_fRadSec; }
	const float&			GetHertz() const { return m_fHert; }
	
	void SetRotationType( const kDx::eRotationType & val ) { m_eRotationType = val; }
	void SetRadSec( const float & val );
	void SetHertz( const float & val );

private:
	

	kDx::eRotationType m_eRotationType;
	float m_fRadSec;
	float m_fHert;

};
}// end namespace Actions
}// end namespace DX
#endif
