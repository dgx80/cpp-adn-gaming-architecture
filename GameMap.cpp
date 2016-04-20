#include "GameMap.h"
// namespace
namespace DX
{
namespace Game
{
GameMap::GameMap(const DX::Point &pos, const DX::Prop &dim)
: adn::Mole(pos,dim)
{
}
void GameMap::InitMap()
{
	FractionateMole();
}
void GameMap::Draw() const
{
	adn::Mole::Draw();
}
bool GameMap::OnMouseMove(const Point& oPoint)
{
	return adn::Mole::OnMouseMove(oPoint);
}
bool GameMap::OnMouseDown(const Point& oPoint)
{
	return adn::Mole::OnMouseDown(oPoint);
}
bool GameMap::OnMouseUp(const Point& oPoint)
{
	return adn::Mole::OnMouseUp(oPoint);
}
}//Game
}//DX