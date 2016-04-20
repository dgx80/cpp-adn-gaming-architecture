#include "KineticParticule.h"

#include "SceneManager.h"
#include "Scene.h"

// namespace
namespace DX
{
namespace Physics
{
	using namespace Core;

KineticParticule::KineticParticule(const Point &oPosition, const float &fXSpeed,const float &fYSpeed,
								   const int &a_nPixPerMeter )
: Point(oPosition)
, m_nPixPerMeter(a_nPixPerMeter)
, m_fXSpeed(fXSpeed)
, m_fYSpeed(fYSpeed)
, m_oElapsedSinceLastMove(0,0)
, m_poScene(NULL)
{
	RefreshSpeedPerMiliSec();
}
KineticParticule::~KineticParticule()
{
	if(m_poScene)
	{
		m_poScene->RemoveToUpdate(this);
		m_poScene = NULL;
	}
}
void KineticParticule::Update(const int &a_nElapsedTime)
{
	if(!m_bXMove && !m_bYMove)
	{
		return;
	}
	else
	{
		if(m_bXMove)
		{
			m_oElapsedSinceLastMove += Point(a_nElapsedTime,0);
			int xMove = m_oPixSpeedPerSecond.GetX() * m_oElapsedSinceLastMove.GetX() / 1000;

			if(xMove != 0)
			{
				m_oElapsedSinceLastMove.SetX(0);
				SetX( GetX()+xMove );
			}
		}
		if(m_bYMove)
		{
			m_oElapsedSinceLastMove += Point(0,a_nElapsedTime);

			int yMove = m_oPixSpeedPerSecond.GetY() * m_oElapsedSinceLastMove.GetY() / 1000;
			
			if(yMove != 0)
			{
				m_oElapsedSinceLastMove.SetY(0);
				SetY( GetY()+yMove);
			}
		}
	}
}
void KineticParticule::SetPixPerMeter(const int &a_nPixPerMeter)
{
	m_nPixPerMeter = a_nPixPerMeter;
}
void KineticParticule::SetSpeed(const float &fX, const float &fY)
{
	m_fXSpeed = fX;
	m_fYSpeed = fY;
	RefreshSpeedPerMiliSec();
}
void KineticParticule::RefreshSpeedPerMiliSec()
{
	m_oPixSpeedPerSecond.SetX(static_cast<int>(m_nPixPerMeter * m_fXSpeed));
	m_oPixSpeedPerSecond.SetY(static_cast<int>(m_nPixPerMeter * m_fYSpeed));
	
	if(m_oPixSpeedPerSecond.GetX() != 0)
		m_bXMove = true;
	else
		m_bXMove = false;

	if(m_oPixSpeedPerSecond.GetY() != 0)
		m_bYMove = true;
	else
		m_bYMove = false;
	
	if(m_bXMove || m_bYMove)
	{
		SetParticuleType(kDx::knParticuleType_Dynamic);
	}
	else
	{
		SetParticuleType(kDx::knParticuleType_Static);
	}
}
void KineticParticule::SetParticuleType(DX::kDx::eParticuleType a_eParticuleType)
{
	m_eParticuleType = a_eParticuleType;
	if(IsSceneDependency())
	{
		if(!m_poScene)
		{
			m_poScene = Time::SceneManager::AddToUpdate(*this);
		}
	}
	else if(m_eParticuleType == DX::kDx::knParticuleType_Static)
	{
		if(m_poScene)
		{
			m_poScene->RemoveToUpdate(this);
			m_poScene = NULL;
		}
	}
}
bool KineticParticule::IsSceneDependency()
{
	if(m_eParticuleType == DX::kDx::knParticuleType_Dynamic)
	{
		return true;
	}
	return false;
}
}//Physics
}//DX