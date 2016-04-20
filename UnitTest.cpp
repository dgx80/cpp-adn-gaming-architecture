#include "UnitTest.h"
#include "DXLib.h"

#include "Data.h"

using namespace DX::Math;
using namespace DX::Graphic;
using namespace DX::adn;

namespace
{
	DX::Data::DataTable oTable(1,1);
}

// namespace
namespace DX
{
namespace Debug
{

UnitTest::UnitTest()
: m_n(0)
#if _UnitTest_Pixel
	, m_oPixel(Point(100,300),1.0f,1.0f,10)
#endif
	//, m_oPinPtSet(Point(20,40),Prop(64,64))
#if _UnitTest_Vect
	, m_oVect(Point(40,40),100.0f,30)
#endif
#if _UnitTest_Cell
	, m_oCell(Point(10,10),Prop(256,256))
#endif
#if  _UnitTest_Mole	
	, m_oMole(Point(100,100), Prop(256,256))
#endif
#if _UnitTest_Quad
	, m_oQuad(Point(100,100),Prop(100,100))
#endif
#if _UnitTest_GameMap
	, m_oGameMap(Point(),Prop(1024,1024))
#endif
#if _UnitTest_Sprite
	, m_oSprite(DX::Point(400,400),"dx/toto.png")
#endif
#if _UnitTest_AnimatedSprite
	, m_oAnim(DX::Point(400,400),"anim/cardinal.xml")
#endif
#if _UnitTest_RPGCharacter
	, m_oCharacter(DX::Point(400,400),"anim/cardinal.xml")
#endif
{
	oTable.SetLineName(0,"Cells");
}
void UnitTest::PixelTest()
{
#if _UnitTest_Pixel
	m_oPixel.SetVisible(true);
	m_oPixel.SetColor(Color::PalWhite());
#endif
}
void UnitTest::VectorTest()
{
#if _UnitTest_Vect
	m_oVect.SetVisible(true);
	m_oVect.SetSpeed(1.5f,1.5f);
	m_oVect.SetRadian(1.0f);
	m_oVect.SetAngularFreq(0.1416f);
	
#endif
}

void UnitTest::PinPointTest()
{
//	m_oPinPtSet = Point(400,200);
//	m_oPinPtSet.SetVisible(true, m_poRenderer);
}
void UnitTest::PlaneTest()
{
}
void UnitTest::CellTest()
{
#if _UnitTest_Cell
	m_oCell.SetVisible(true);
//	m_oCell =	 Point(200,400);
//	m_oCell.SetDimension(Prop(100,100));
#endif
}

void UnitTest::QuadrilatereTest()
{
#if _UnitTest_Quad
	m_oQuad.SetVisible(true);
//	m_oQuad.SetDimension(Prop(25,25));

#endif
}
void UnitTest::MoleTest()
{
#if  _UnitTest_Mole
	m_oMole.SetVisible(true);
	m_oMole.SetSpeed(50,40);
	m_oMole.SetColor(Color(0,0,255,255));
#endif
}
void UnitTest::GameMapTest()
{
#if _UnitTest_GameMap
	
	m_oGameMap.SetVisible(true);

#endif
}
void UnitTest::SpriteTest()
{
#if _UnitTest_Sprite

	m_oSprite.SetVisible(true);
//	m_oSprite.SetSpeed(10,10);
#endif
}
void UnitTest::AnimatedSpriteTest()
{
#if _UnitTest_AnimatedSprite

	m_oAnim.SetVisible(true);


#endif
}
void UnitTest::RPGCharacterTest()
{
#if _UnitTest_RPGCharacter

	m_oCharacter.SetVisible(true);
	m_oCharacter.Play("DoAnim");

#endif
}

void UnitTest::DrawADNConsole()
{

}

// close
}// Debug namespace end
}// DX namespace end
