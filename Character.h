#pragma once
#ifndef _DX_Character_h
#define _DX_Character_h


#include "DXDefine.h"
#include "AnimatedSprite.h"

namespace DX
{
namespace Game
{
class Character :	public DX::Graphic::AnimatedSprite
{
public:
	struct DirectionalCounter
	{
		DirectionalCounter()
		{
			SetAllCounter(0);
		}
		void SetAllCounter(int nTime)
		{
			nUp = nTime;
			nDown = nTime;
			nLeft = nTime;
			nRight = nTime;
		}
		void AddTimeToAllCounter(int nTime)
		{
			nUp += nTime;
			nDown += nTime;
			nLeft += nTime;
			nRight += nTime;
		}
		int GetShortestTimer()
		{
			int n = nUp;

			if(n > nDown)
			{
				n = nDown;
			}
			if(n > nLeft)
			{
				n = nLeft;
			}
			if(n > nRight)
			{
				n = nRight;
			}
			return n;
		}
		int nUp;
		int nDown;
		int nLeft;
		int nRight;
	};
	struct DirectionalFlags
	{
		DirectionalFlags()
			: bUp(false)
			, bDown(false)
			, bLeft(false)
			, bRight(false){}
		void SetAllDirectionalFlags(bool bState)
		{
			bUp = bState;
			bDown = bState;
			bLeft = bState;
			bRight = bState;
		}
		bool OrDirectionOpened()
		{
			return (bUp || bDown || bLeft || bRight);
		}
		bool bUp;
		bool bDown;
		bool bLeft;
		bool bRight;
	};
	struct InputControls : public DirectionalFlags
	{
		InputControls()
			: bActivated(false)
			, bJump(true)
		{
			SetAllDirectionalFlags(true);
		}
		
		bool bActivated;
		bool bJump;
	};
	enum eCharacterState
	{
		knWalk = 0,
		knRun,
		knJump,
		knTalk,
		knWait
	};
	Character(const DX::Point & oPosition = DX::Point(), const str & a_sFileName = "");
	virtual ~Character();

	virtual void Update(const int &a_nElapsedTime);

	void SetInputControlled(bool IsControlled);
	void SetCharacterState( eCharacterState a_eCharacterState){m_eCharacterState = a_eCharacterState;}

	eCharacterState GetCharacterState(){return m_eCharacterState;}



protected:

	virtual bool IsSceneDependency();
	InputControls m_oInputControlled;
	DirectionalFlags m_oDirectionalFlags; //to know flags direction thats moving now

	virtual void GoUp();
	virtual void GoDown();
	virtual void GoLeft();
	virtual void GoRight();
	virtual void Jump();
	virtual void StopCharacter();

	void ResetTimeWhitoutInput(){m_oDirectionalCounter.SetAllCounter(0);};
	void AddTimeWhitoutInput(int a_nElapsedTime){m_oDirectionalCounter.AddTimeToAllCounter(a_nElapsedTime);}

	float GetMaxSpeedWalk(){return m_fMaxSpeedWalk;}
	float GetMaxSpeedRun(){return m_fMaxSpeedRun;}

	DirectionalCounter m_oDirectionalCounter;

private:
	
	eCharacterState m_eCharacterState;

	float m_fMaxSpeedWalk;
	float m_fMaxSpeedRun;
	
};
}//Game
}//DX
#endif