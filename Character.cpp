#include "Character.h"
#include "SceneManager.h"
#include "Scene.h"

namespace DX
{
namespace Game
{
Character::Character(const DX::Point &oPosition, const str &a_sFileName)
:AnimatedSprite(oPosition,a_sFileName)
, m_eCharacterState(knWait)
, m_fMaxSpeedWalk(2.0f)
, m_fMaxSpeedRun(5.0f)
{
	SetPixPerMeter(70);
	SetInputControlled(true);
}
Character::~Character()
{
}
void Character::SetInputControlled(bool IsControlled)
{
	if(IsControlled)
	{
		if(!IsSceneDependency())
		{
			SetScene(DX::Time::SceneManager::AddToUpdate(*this));
			GetScene()->AddToInputControlled(*this);
		}
		m_oInputControlled.bActivated = true;
	}
	else
	{
		m_oInputControlled.bActivated = false;
		if(!IsSceneDependency())
		{
			if(GetScene())
			{
				GetScene()->RemoveToUpdate(this);
				SetScene(NULL);
			}
		}
	}
}
bool Character::IsSceneDependency()
{
	if(m_oInputControlled.bActivated)
	{
		return true;
	}
	else
	{
		return DX::Graphic::AnimatedSprite::IsSceneDependency();
	}
}
void Character::Update(const int &a_nElapsedTime)
{
	Graphic::AnimatedSprite::Update(a_nElapsedTime);

	if(m_oDirectionalFlags.OrDirectionOpened())
		AddTimeWhitoutInput(a_nElapsedTime);

//	DEBUG_WRITE(("%d\n",m_oDirectionalCounter.GetShortestTimer()));
	if(m_oDirectionalCounter.GetShortestTimer() > 500)
	{
		StopCharacter();
	}
}
void Character::StopCharacter()
{
	SetCharacterState(knWait);
	m_oDirectionalCounter.SetAllCounter(0);
	m_oDirectionalFlags.SetAllDirectionalFlags(false);
}
void Character::GoUp()
{
	m_oDirectionalFlags.bDown = false;
}
void Character::GoDown()
{
	m_oDirectionalFlags.bUp = false;
}
void Character::GoLeft()
{
	m_oDirectionalFlags.bRight = false;
}
void Character::GoRight()
{
	m_oDirectionalFlags.bLeft = false;
}
void Character::Jump()
{
}

}//Game
}//DX