#ifndef _DX_Actions_h
#define _DX_Actions_h

#include "DXDefine.h"
#include "Pixel.h"

// namespace
namespace DX
{
namespace Actions
{
class Actions
	:public Graphic::Pixel
{
public:

	const	kDx::eTriggerType&	GetTriggerType() const { return m_eTriggerType; }
	void			SetTriggerType( const kDx::eTriggerType & val ) { m_eTriggerType = val; }

protected:
	Actions(const kDx::eTriggerType& trigType = kDx::knTriggerType_Loop);
	virtual ~Actions(){}
private:

	kDx::eTriggerType m_eTriggerType;
};
}// end namespace Actions
}// end namespace DX
#endif
