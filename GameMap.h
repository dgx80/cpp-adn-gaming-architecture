#ifndef _DX_GameMap_h
#define _DX_GameMap_h

#include "DXDefine.h"
#include "Mole.h"

// namespace
namespace DX
{
namespace Game
{
	class GameMap : public adn::Mole
{
public:
	// Constructors
	GameMap(const DX::Point &pos = DX::Point(), const Prop &dim = Prop( _DX_ADN_MOLE_SIDE,_DX_ADN_MOLE_SIDE));
	// Destructor
	virtual ~GameMap(){}

	void InitMap();

	virtual void Draw() const;

	virtual bool OnMouseMove(const Point& oPoint);
	virtual bool OnMouseDown(const Point& oPoint);
	virtual bool OnMouseUp(const Point& oPoint);

protected:


private:
	//cree une class diumage simple sans collision et rotation DX::Graph::Image

};
}// adn namespace end
}// DX namespace end
#endif
