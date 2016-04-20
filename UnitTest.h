#ifndef _DX_UnitTest_h
#define _DX_UnitTest_h

#define _UnitTest_Pixel		0
#define _UnitTest_Vect		0
#define _UnitTest_Quad		0
#define _UnitTest_Cell		0
#define _UnitTest_Mole		0
#define _UnitTest_GameMap	0
#define _UnitTest_Sprite	0
#define _UnitTest_AnimatedSprite	0
#define _UnitTest_RPGCharacter		1

#include "DXDefine.h"
#include "DXLib.h"
// namespace
namespace DX
{
namespace Debug
{

class UnitTest
{
public:
	// Constructors
	UnitTest();
	// Destructor
	virtual ~UnitTest(){}

	void VectorTest();
	void CellTest();
	void MoleTest();
	void PlaneTest();
	void QuadrilatereTest();
	void PixelTest();
	void PinPointTest();
	void GameMapTest();
	void SpriteTest();
	void AnimatedSpriteTest();
	void RPGCharacterTest();
	void DrawADNConsole();


private:

	struct xDataLine
	{
		dxString sName;
	};
	int m_n;
//	DX::Graphic::Text m_oTx;

#if _UnitTest_Pixel
	DX::Graphic::Pixel m_oPixel;
#endif
#if _UnitTest_Vect
	DX::Graphic::Vect2 m_oVect;
#endif
//	DX::Canevas::PinPointSet m_oPinPtSet;

#if _UnitTest_Quad
	DX::Graphic::Quadrilatere m_oQuad;
#endif

#if _UnitTest_Cell
	DX::adn::Cell m_oCell;
#endif

#if  _UnitTest_Mole
	DX::adn::Mole m_oMole;
#endif

#if _UnitTest_GameMap
	DX::Game::GameMap m_oGameMap;
#endif

#if _UnitTest_Sprite
	DX::Graphic::Sprite m_oSprite;
#endif

#if _UnitTest_AnimatedSprite

	DX::Graphic::AnimatedSprite m_oAnim;

#endif

#if _UnitTest_RPGCharacter

	DX::Game::RPGCharacter m_oCharacter;

#endif
};
}// Debug namespace end
}// DX namespace end
#endif
