#ifndef _DX_SceneManager_h
#define _DX_SceneManager_h

#include "DXDefine.h"
#include <vector>
#include <pf/pflib.h>

// namespace
namespace DX
{
namespace Time
{
class SceneManager
{
public:

	static Scene& CreateScene();
	static void DestroyScene(Scene* scene);
	static Scene& GetFocusScene();


	static void SetFocusScene(Scene& scene);

	static void Draw();
	static void Update();
	static void OnMouseMove(const Point& pt);
	static void OnMouseDown(const Point& pt);
	static void OnMouseUp(const Point& pt);
	static void OnKeyDown(char key, uint32_t flags);

	static Scene* AddToUpdate(Point& pt);
	
	static TAssetMap & GetAssetMap() {return s_AssetMap;}

private:

	static bool s_bFirstExecution;

	static Scene *s_pFocusScene;

	static std::vector<Scene*> s_vScene;

	static int s_nLastTime;
	static TAssetMap s_AssetMap;

};
}//end Time
}// end namespace DX
#endif
