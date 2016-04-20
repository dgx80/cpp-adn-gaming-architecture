#include "RPGCharacter.h"

namespace DX
{
namespace Game
{
RPGCharacter::RPGCharacter(const DX::Point &oPosition, const str &a_sFileName)
:Character(oPosition,a_sFileName)
{
	m_oDirectionalFlags.SetAllDirectionalFlags(false);
}
RPGCharacter::~RPGCharacter()
{
}
void RPGCharacter::Update(const int &a_nElapsedTime)
{
	Character::Update(a_nElapsedTime);
}
void RPGCharacter::StopCharacter()
{
	Character::StopCharacter();
	SetSpeed(0,0);
}
bool RPGCharacter::OnMouseMove(const DX::Point &pt)
{
	return Character::OnMouseMove(pt);
}
bool RPGCharacter::OnMouseDown(const DX::Point &pt)
{	
	return Character::OnMouseDown(pt);
}
bool RPGCharacter::OnMouseUp(const DX::Point &pt)
{
	return Character::OnMouseUp(pt);
}
bool RPGCharacter::OnKeyDown(char key, uint32_t flags)
{
	DEBUG_WRITE(("yes"));
	if(key == kDx::knInputKey_UP)
	{
		GoUp();
	}
	else if(key == kDx::knInputKey_DOWN)
	{
		GoDown();
	}
	else if(key == kDx::knInputKey_LEFT)
	{
		GoLeft();
	}
	else if(key == kDx::knInputKey_RIGHT)
	{	
		GoRight();
	}
	return Character::OnKeyDown(key,flags);
}
void RPGCharacter::GoUp()
{
	Character::GoUp();
	if(!m_oDirectionalFlags.bUp)
	{
		//animation
		if( !m_oDirectionalFlags.OrDirectionOpened())
		{
			SetCharacterState(knWalk);
//			Play("up");
		}
		
		m_oDirectionalFlags.bUp = true;
		SetSpeed(GetSpeedX(),-GetMaxSpeedWalk());
	}
	m_oDirectionalCounter.nUp = 0;
	
}
void RPGCharacter::GoDown()
{
	Character::GoDown();

	if(!m_oDirectionalFlags.bDown)
	{
		//animation
		if( !m_oDirectionalFlags.OrDirectionOpened())
		{
			SetCharacterState(knWalk);
//			Play("down");
		}

		m_oDirectionalFlags.bDown = true;
		SetSpeed(GetSpeedX(),GetMaxSpeedWalk());
	}
	m_oDirectionalCounter.nDown = 0;
}
void RPGCharacter::GoLeft()
{
	Character::GoLeft();

	if(!m_oDirectionalFlags.bLeft)
	{
		//animation
		if( !m_oDirectionalFlags.OrDirectionOpened())
		{
			SetCharacterState(knWalk);
//			Play("left");
		}
		m_oDirectionalFlags.bLeft = true;
		SetSpeed(-GetMaxSpeedWalk(),GetSpeedY());
	}
	m_oDirectionalCounter.nLeft = 0;
}
void RPGCharacter::GoRight()
{
	Character::GoRight();
	if(!m_oDirectionalFlags.bRight)
	{
		//animation
		if( !m_oDirectionalFlags.OrDirectionOpened())
		{
			SetCharacterState(knWalk);
//			Play("right");
		}
		m_oDirectionalFlags.bRight = true;
		SetSpeed(GetMaxSpeedWalk(),GetSpeedY());
	}
	m_oDirectionalCounter.nRight = 0;
}
void RPGCharacter::Jump()
{
	Character::Jump();
}

}//Game
}//DX