/* --------------------------------------------
** ��Ȩ: 
** ����: fountain
** ����: louyk 
** ����: 2015/07/24 
** ����: 
** ------------------------------------------*/
#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "MyOSG.h"

class Fountain
{
public:
	Fountain();
	~Fountain();

	// ����Ҫ������Ȫ�ľ������
	void setFountainParas(double num = 1000, double size = 0.2, double speed = 100);

	// ������Ȫ������Ϊ��Ȫ��λ����Ϣ�����ڵ�
	osg::ref_ptr<osg::Node> createFountain(osg::Vec3d postion, osg::Group* parent);

private:
	osg::Vec3d m_vecPos;             // λ��
	double m_dParticlesNum;          // ������Ŀ
	double m_dParticlesSize;         // ���Ӵ�С
	double m_dParticlesSpeed;        // �����ٶ�
};

#endif // FOUNTAIN_H
