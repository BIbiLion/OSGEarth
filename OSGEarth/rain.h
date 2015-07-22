/* --------------------------------------------
** ��Ȩ: 
** ����: rain
** ����: louyk 
** ����: 2015/07/22 
** ����: 
** ------------------------------------------*/
#ifndef RAIN_H
#define RAIN_H

#include "graphicsview.h"

class Rain
{
public:
	Rain(GraphicsView* view);
	~Rain();

	// ��Ч����iLevel����1-10��x:��Ļ���� y:��Ļ����
	void run(int iLevel, double x, double y);

	// ֹͣ��Ч��
	void stop();

private:
	// ������Ļ������������
	osg::Vec3d getPostion(double x, double y);

private:
	GraphicsView* m_pMap3D;
	osg::ref_ptr<osg::Group> m_pRainGroup;
};

#endif // RAIN_H
