#ifndef _DX_KineticParticule_h
#define _DX_KineticParticule_h

#include "Point.h"

// namespace
namespace DX
{
namespace Physics
{
class KineticParticule: public Point
{
public:

	KineticParticule(const Point &oPosition = Point(), const float &fXSpeed=0.0f,const float &fYSpeed=0.0f,
		const int &a_nPixPerMeter = 100);
	virtual ~KineticParticule();

	void SetSpeed(const float &fX,const float &fY);
	float GetSpeedX(){return m_fXSpeed;}
	float GetSpeedY(){return m_fYSpeed;}

	void SetPixPerMeter(const int &a_nPixPerMeter);
	void SetParticuleType(kDx::eParticuleType a_eParticuleType);

	virtual void Update(const int &a_nElapsedTime);

protected:
	void			SetScene(Time::Scene *pScene){m_poScene = pScene;}
	Time::Scene *	GetScene(){return m_poScene;}

	virtual bool IsSceneDependency();
private:

	void RefreshSpeedPerMiliSec();


	int m_nPixPerMeter;
	float m_fXSpeed;//meter/second
	float m_fYSpeed;//meter/second
	
	Point m_oPixSpeedPerSecond;
	bool m_bXMove;
	bool m_bYMove;
	Point m_oElapsedSinceLastMove;
	Time::Scene *m_poScene;
	kDx::eParticuleType m_eParticuleType;

};
}// end namespace Physics
}// end namespace DX
#endif
