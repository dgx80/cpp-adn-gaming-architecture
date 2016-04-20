#include "ActionRotation.h"


// namespace
namespace DX
{
namespace Actions
{
ActionRotation::ActionRotation(const kDx::eTriggerType& trigType,
							   const kDx::eRotationType & rotType, 
							   const float& a_fHertz)
: Actions(trigType)
, m_eRotationType( rotType )
, m_fRadSec(0.0f)
, m_fHert(0.0f)
{
	SetHertz(a_fHertz);

}
void ActionRotation::SetHertz( const float & val ) 
{ 
	m_fRadSec = static_cast<float>(_DX_2PI* val);
	m_fHert = val;
}
void ActionRotation::SetRadSec(const float &val)
{ 
	m_fRadSec = val;
	m_fHert = static_cast<float>(val / _DX_2PI);
}
// close
}// end namespace Actions
}// end namespace DX
