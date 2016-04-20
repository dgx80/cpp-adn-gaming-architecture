#include "Scene.h"

#include <list>
// namespace
namespace DX
{
namespace Time
{
Scene::Scene()
#if _SCENE_STARTED
	: m_oGameMap(Point(),Prop(1024,1024))
#endif
{
}
void Scene::Init()
{
#if _SCENE_STARTED
	m_oGameMap.InitMap();
#endif
}
void Scene::Draw()
{
	m_oRenderer.Draw();
	m_oMouse.Draw();
#if _SCENE_STARTED

//	m_oGameMap.Draw();
#endif
}
void Scene::Update(const int &a_nElapsedTime)
{
	std::list<Point*>::iterator iter = m_lpUpdatingPoint.begin();

	for( ; iter != m_lpUpdatingPoint.end(); iter++)
	{
		(*iter)->Update(a_nElapsedTime);
	}
}
void Scene::OnMouseMove(const Point& pt)
{
	m_oMouse.OnMouseMove(pt);

#if _SCENE_STARTED
	m_oGameMap.OnMouseMove(pt);
#endif
}
void Scene::OnMouseUp(const Point& pt)
{
	std::list<DX::adn::Cell*>::iterator iter = m_lpInputControlled.begin();

	for( ; iter != m_lpInputControlled.end(); iter++)
	{
		(*iter)->OnMouseUp(pt);
	}
#if _SCENE_STARTED
	m_oGameMap.OnMouseUp(pt);
#endif
}
void Scene::OnMouseDown(const Point& pt)
{
#if _SCENE_STARTED
	m_oGameMap.OnMouseDown(pt);
#endif
	std::list<DX::adn::Cell*>::iterator iter = m_lpInputControlled.begin();

	for( ; iter != m_lpInputControlled.end(); iter++)
	{
		(*iter)->OnMouseDown(pt);
	}
}
void Scene::OnKeyDown(char key, uint32_t flags)
{
	std::list<DX::adn::Cell*>::iterator iter = m_lpInputControlled.begin();

	for( ; iter != m_lpInputControlled.end(); iter++)
	{
		(*iter)->OnKeyDown(key,flags);
	}
}
void Scene::AddToUpdate(Point &pt)
{
	m_lpUpdatingPoint.push_back(&pt);
}
void Scene::AddToInputControlled(DX::adn::Cell &cell)
{
	m_lpInputControlled.push_back(&cell);
}
void Scene::RemoveToUpdate(const DX::Point *pt)
{
	std::list<Point*>::iterator iter;

	for(iter=m_lpUpdatingPoint.begin();iter!=m_lpUpdatingPoint.end();iter++)
	{
		if(pt == *iter)
		{
			m_lpUpdatingPoint.erase(iter);
			break;
		}
	}
}
void Scene::RemoveToInputControlled(const DX::adn::Cell *cell)
{
	std::list<DX::adn::Cell*>::iterator iter;

	for(iter=m_lpInputControlled.begin();iter!=m_lpInputControlled.end();iter++)
	{
		if(cell == *iter)
		{
			m_lpInputControlled.erase(iter);
			break;
		}
	}
}

}//end Time

}// end namespace DX