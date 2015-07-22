/* --------------------------------------------
** ��Ȩ: 
** ����: snow
** ����: louyk 
** ����: 2015/07/22 
** ����: 
** ------------------------------------------*/
#ifndef SNOW_H
#define SNOW_H

#include "graphicsview.h"

class Snow
{
public:
	Snow(GraphicsView* view);
	~Snow();

	// ѩЧ����iLevel����1-10��x:��Ļ���� y:��Ļ����
	void run(int iLevel, double x, double y);

	// ֹͣѩЧ��
	void stop();

private:
	// ������Ļ������������
	osg::Vec3d getPostion(double x, double y);

private:
	GraphicsView* m_pMap3D;
	osg::ref_ptr<osg::Group> m_pSnowGroup;
};

#endif // SNOW_H
