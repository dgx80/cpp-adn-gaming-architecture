#pragma once
#ifndef _DX_Image_h
#define _DX_Image_h

#include "Mole.h"
#include "DXDefine.h"

#include <pf/pflib.h>


namespace DX
{
namespace Graphic
{
class Image :	public DX::adn::Mole
{
public:
	Image(const DX::Point & oPosition = DX::Point());
	virtual ~Image();

	virtual void SetVisible(bool val = false);
	

	virtual void Load(const str & a_sFileName);

	virtual void SetX(const int &a_nX);
	virtual void SetY(const int &a_nY);

	virtual void Draw() const;
	
	void				SetPositionType(kDx::ePositionType a_ePositionType);
	kDx::ePositionType	GetPositionType()									{return m_ePositionType;}


protected:
	void SetSprite(TSpriteRef ref){m_spSprite = ref;}
	TSpriteRef GetSprite(){return m_spSprite;}
	

private:

	kDx::ePositionType m_ePositionType;
	DX::Point m_oImageOffset;
	bool m_bDebugMole;
	TSpriteRef m_spSprite;

};
}//Graphic
}//DX
#endif