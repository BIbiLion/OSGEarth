/* --------------------------------------------
** ��Ȩ: 
** ����: fog
** ����: louyk 
** ����: 2015/07/22 
** ����: 
** ------------------------------------------*/
#ifndef FOG_H
#define FOG_H

#include "graphicsview.h"

class Fog
{
public:
	Fog(GraphicsView* view);
	~Fog();

	// ��Ч����iLevel����1-10
	void run(int iLevel);

	// ������Ч��
	void stop();

private:
	GraphicsView* m_pMap3D;
	osg::ref_ptr<osg::Fog> m_pFog;
	osg::ref_ptr<osgEarth::Util::FogEffect> m_pFogEffect;
};

#endif // FOG_H
