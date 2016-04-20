#include "RollerPin.h"

#include "Scene.h"
#include "SceneManager.h"

// namespace
namespace DX
{
namespace Canevas
{
RollerPin::RollerPin(const DX::Point &a_rOrigin, const int &a_nDegre)
: Graphic::Pixel(a_rOrigin)
, m_oRotationAxis(a_nDegre)
, m_fAngularFreq(0)
, m_nLastTimeBeforeRotation(0)
{

}
void RollerPin::SetDegre( const int & a_nDeg )
{
	m_oRotationAxis.SetDegre(  a_nDeg );
}
void RollerPin::SetRadian( const float &a_fRad )
{
		m_oRotationAxis.SetRadian( a_fRad );
}
void RollerPin::SetAngularFreq( const float & radSec ) 
{ 
	m_fAngularFreq = radSec;

	if( IsSceneDependency() )
	{
		if(!GetScene())
		{
			SetScene(Time::SceneManager::AddToUpdate(*this));
		}
	}
	else
	{
		if(GetScene())
		{
			GetScene()->RemoveToUpdate(this);
			SetScene(NULL);
		}
	}
}
bool RollerPin::IsSceneDependency()
{
	if( m_fAngularFreq!= 0.0f )
	{
		return true;
	}
	return KineticParticule::IsSceneDependency();
}
void RollerPin::Update(const int &a_nElapsedTime)
{
	m_nLastTimeBeforeRotation += a_nElapsedTime;
	float w = m_nLastTimeBeforeRotation * m_fAngularFreq / 1000;

	if(w != 0.0f)
	{
		SetRadian( m_oRotationAxis.GetRadian() + w);
		m_nLastTimeBeforeRotation = 0;
	}
	
	KineticParticule::Update(a_nElapsedTime);
}
// close
}// end namespace Canevas
}// end namespace DX
