#include "SceneManager.h"
#include <stdlib.h>

#include "Scene.h"
// namespace
namespace DX
{
namespace Time
{
Scene * SceneManager::s_pFocusScene = NULL;
std::vector<Scene*> SceneManager::s_vScene;
int SceneManager::s_nLastTime = 0;
TAssetMap SceneManager::s_AssetMap;
bool SceneManager::s_bFirstExecution = true;

Scene& SceneManager::CreateScene()
{
	if(s_bFirstExecution)
	{
		s_AssetMap.SetAutoLoad(true);
		s_bFirstExecution = false;
	}

	Scene* s = new Scene();
	s->Init();
	s_nLastTime = TPlatform::GetInstance()->Timer();

	if( s_pFocusScene == NULL)
	{
		s_pFocusScene = s;
	}
	s_vScene.push_back(s);

	return *s;
}
void SceneManager::DestroyScene(Scene* scene)
{
	static std::vector<Scene*>::iterator iter;

	for(iter = s_vScene.begin();iter != s_vScene.end(); iter++)
	{
		if( (*iter) == scene)
		{
			s_vScene.erase(iter);
			break;
		}
	}

	if( s_vScene.empty())
	{
		s_pFocusScene = NULL;
	}
	else
	{
		//s_pFocusScene = *s_vScene.begin();
	}
}
Scene& SceneManager::GetFocusScene()
{
	return *s_pFocusScene;
}

void SceneManager::SetFocusScene(Scene &scene)
{
	s_pFocusScene = &scene;
}
void SceneManager::Draw()
{
	if(s_pFocusScene != NULL)
		s_pFocusScene->Draw();
}
void SceneManager::Update()
{
	int newtime = TPlatform::GetInstance()->Timer();
	int elapsedTime =  newtime - s_nLastTime;
	s_nLastTime = newtime;

	if(elapsedTime > 200)
		elapsedTime = 20;

	if(s_pFocusScene != NULL)
		s_pFocusScene->Update(elapsedTime);
}
void SceneManager::OnMouseMove(const Point &pt)
{
	if(s_pFocusScene != NULL)
		s_pFocusScene->OnMouseMove(pt);
}
void SceneManager::OnMouseDown(const Point &pt)
{
	if(s_pFocusScene != NULL)
		s_pFocusScene->OnMouseDown(pt);
}
void SceneManager::OnMouseUp(const Point &pt)
{
	if(s_pFocusScene != NULL)
		s_pFocusScene->OnMouseUp(pt);
}
void SceneManager::OnKeyDown(char key, uint32_t flags)
{
	if(s_pFocusScene != NULL)
	{
		s_pFocusScene->OnKeyDown(key,flags);
	}
}

Scene *SceneManager::AddToUpdate(Point &pt)
{
	if(s_pFocusScene != NULL)
		s_pFocusScene->AddToUpdate(pt);
	return s_pFocusScene;
}

}//end Time
}// end namespace DX