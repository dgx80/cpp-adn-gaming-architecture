#ifndef _DX_RollerPin_h
#define _DX_RollerPin_h

#include "DXDefine.h"
#include "Pixel.h"
#include "Angle.h"

// namespace
namespace DX
{
namespace Canevas
{
class RollerPin
	: public Graphic::Pixel
{
public:
	RollerPin(const Point & a_rOrigin = Point(), const int &a_nDegre = 0);
	virtual ~RollerPin(){}

	const int&		GetDegre() const { return m_oRotationAxis.GetDegre(); }
	const float&	GetRadian() const { return m_oRotationAxis.GetRadian(); }
	const float&	GetAngularFreq() const { return m_fAngularFreq; }

	virtual void SetDegre( const int &a_nDeg ); 
	virtual void SetRadian( const float &a_fRad );
	virtual void SetAngularFreq( const float & radSec );

	virtual void Update(const int &a_nElapsedTime);

protected:
	
	virtual bool IsSceneDependency();

private:

	Math::Angle m_oRotationAxis;

	// (rad /sec) = w
	float m_fAngularFreq;

	int m_nLastTimeBeforeRotation;
};
}// end namespace Canevas
}// end namespace DX
#endif


//********************************************************************************
//******Titre:
//****Details:
//*****Others:
