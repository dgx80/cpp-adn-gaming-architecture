#ifndef _DX_Text_h
#define _DX_Text_h

#include "DXDefine.h"
#include <pf/pflib.h>
#include "Pixel.h"

// namespace
namespace DX
{
namespace Graphic
{
class Text : public Pixel
{
public:
	// Constructors
	Text();
	// Destructor
	virtual ~Text(){}


	virtual void Draw()const;

	void SetLineHeight(int h = 12) { m_prTx->SetLineHeight(h); }
	void SetText(const char * tx) { m_prTx->SetText( tx );}
	virtual void SetColor(const Color & oCol);

	virtual void SetX(const int &a_nX)
	{
		m_prTx->GetDrawSpec().mMatrix[2].x = static_cast<TReal>(a_nX);
		Pixel::SetX(a_nX);
	}

	virtual void SetY(const int &a_nY)
	{
		m_prTx->GetDrawSpec().mMatrix[2].y = static_cast<TReal>(a_nY);
		Pixel::SetY(a_nY);
	}

//	void SetLabel( const std::string & val ) { m_sLabel = val; }

private:

	TTextSpriteRef m_prTx;

};
}// Graphic namespace end
}// DX namespace end
#endif
