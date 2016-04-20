#pragma once
#ifndef _DXDefine_h
#define _DXDefine_h

#define _DEBUG_ADN_CELL
#define _DEBUG_PIN_POINT_SET

namespace DX
{
#define _DX_PI 3.14159
#define _DX_2PI 2*_DX_PI

#define _DX_CONST_90 90
#define _DX_CONST_180 180
#define _DX_CONST_360 360

//adn define
#define _DX_ADN_CELL_SIDE 64
#define _DX_ADN_MOLE_CASE 4
#define _DX_ADN_MOLE_SIDE _DX_ADN_CELL_SIDE * _DX_ADN_MOLE_CASE


class Point;
class Circle;

namespace Game
{
	class GameMap;
	class RPGCharacter;
	class Character;
}
namespace Time
{
	class SceneManager;
	class Scene;
}//Time
namespace Renderer
{
	class RendererAdmin;
	class RenderingUnit;
}
namespace Physics
{
	class KineticParticule;
}
namespace Core
{
	template<typename T> class AdnStack;
	class PointStack;
	class PixelStack;

}//Core
namespace Data
{
	class DataTable;
}
namespace adn
{
	class Mole;
	class Cell;
	class Plane;
}
namespace Graphic
{
	class Vect2;
	class Quadrilatere;
	class Drawer;
	class Pixel;
	class Color;
	class Renderer;
	class Coin;
	class Text;
	class Sprite;
	class AnimatedSprite;


}//Graphic
namespace Canevas
{
	class PinPointSet;
	class RollerPin;
}
namespace Math
{
	class Dimension;
	class Angle;
	class GridOffset;
	class Proportion;

}//Math
namespace Toolbox
{
	class Convertion;
}//Toolbox
namespace Debug
{
	class MouseView;
}//Debug

namespace kDx //constante de DX
{
	const int _DX_SCREEN_WIDTH = 1024;
	const int _DX_SCREEN_HEIGHT = 768;

namespace Path
{
	const char c_Target_Directory[] = "targets/";
	const char c_Target_Item_Pixel[] = "targets/pixel.png";
}//Path
enum eGameState
{
	knGameState_Invalid = -1,
	knGameState_Play = 0,
	knGameState_Pause = 1,
	knGameState_Count
};
enum eCollisionContext
{
    knCollisionContextInvalid = -1,
    knCollisionContextStatic = 0,
    knCollisionContextDynamic,
    knCollisionContextChildren,
    knCollisionContextLayered,
	knCollisionContextCount
};
enum eMouseContextState
{
    kn_MouseContextState_Invalid = -1,
    kn_MouseContextState_Up = 0,
    kn_MouseContextState_Down
};
enum ePositionType
{
    POS_TOPLEFT = 0,
    POS_TOPCENTER,
    POS_TOPRIGHT,
    POS_CENTERLEFT,
    POS_CENTER,
    POS_CENTERRIGHT,    
	POS_BOTTOMLEFT,
    POS_BOTTOMCENTER,
    POS_BOTTOMRIGHT,
	POS_COUNT
};
enum eTriggerType
{
	knTriggerType_Invalid = -1,
	knTriggerType_Timer = 0,
	knTriggerType_InputValidation, //like press start
	knTriggerType_BinaryChoice,		// yes or no
	knTriggerType_Loop,
	knTriggerType_Other,
	knTriggerType_Count
};

enum eRotationType
{
	knRotationType_Invalid = -1,
	knRotationType_LapCounter = 0,
	knRotationType_RadAjustment,
	knRotationType_Other,
	knRotationType_Count
};
enum eParticuleType
{
	knParticuleType_Invalid = -1,
	knParticuleType_Static = 0,
	knParticuleType_Dynamic,
	knParticuleType_Count
};
enum eInputKey
{
	knInputKey_UP = -128,
	knInputKey_DOWN = -127,
	knInputKey_LEFT = -126,
	knInputKey_RIGHT = -125
};
}//Constante

//#include <vector>
//type
#define CellsList std::vector< adn::Cell >
#define CellsMap std::vector< CellsList >
typedef Math::Proportion Prop;
#define dxString str


}//DX

//lite class
#include "Proportion.h"
#endif