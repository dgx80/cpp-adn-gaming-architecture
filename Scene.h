#ifndef _DX_Scene_h
#define _DX_Scene_h

#include "DXDefine.h"
#include "GameMap.h"

#include "RendererAdmin.h"
#include "MouseView.h"

#define _SCENE_STARTED 0

// namespace
namespace DX
{
namespace Time
{
class Scene
{
public:
	friend class SceneManager;

	Renderer::RendererAdmin &GetRenderer()
	{
		return m_oRenderer;
	}

	void AddToInputControlled(DX::adn::Cell& cell);
	void RemoveToUpdate(const Point* pt);
	void RemoveToInputControlled(const DX::adn::Cell* cell);

private:

	Scene();
	virtual ~Scene(){}
	
	void Init();

	void Draw();
	void Update(const int &a_nElapsedTime);
	void OnMouseMove(const Point& pt);
	void OnMouseDown(const Point& pt);
	void OnMouseUp(const Point& pt);
	void OnKeyDown(char key, uint32_t flags);

	void AddToUpdate(Point& pt);

	Renderer::RendererAdmin m_oRenderer;
	DX::Debug::MouseView m_oMouse;

	std::list<Point*> m_lpUpdatingPoint;
	std::list<DX::adn::Cell*> m_lpInputControlled;

#if _SCENE_STARTED
	DX::Game::GameMap m_oGameMap;
#endif
};
}//end Time
}// end namespace DX
#endif
