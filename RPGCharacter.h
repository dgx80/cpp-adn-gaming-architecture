#pragma once
#ifndef _DX_RPGCharacter_h
#define _DX_RPGCharacter_h


#include "DXDefine.h"
#include "Character.h"

namespace DX
{
namespace Game
{
class RPGCharacter :	public DX::Game::Character
{
public:

	RPGCharacter(const DX::Point & oPosition = DX::Point(), const str & a_sFileName = "");
	virtual ~RPGCharacter();

	virtual void Update(const int &a_nElapsedTime);

	virtual bool OnMouseMove(const Point& pt);
	virtual bool OnMouseDown(const Point& pt);
	virtual bool OnMouseUp(const Point& pt);
	virtual bool OnKeyDown(char key, uint32_t flags);

protected:
	virtual void StopCharacter();
	virtual void GoUp();
	virtual void GoDown();
	virtual void GoLeft();
	virtual void GoRight();
	virtual void Jump();
	
private:

	

};
}//Game
}//DX
#endif