/* --------------------------------------------
** ��Ȩ: (C) 2015
** ����: custommanipulator
** ����: louyk
** ����: 2015/07/31 
** ����: �Զ���osg��������ʵ��һ������CS��ʽ�Ĳ�����
** ------------------------------------------*/
#ifndef CUSTOMMANIPULATOR_H
#define CUSTOMMANIPULATOR_H

#include "MyOSG.h"

class CustomManipulator : public osgGA::CameraManipulator
{
public:
	CustomManipulator();
	~CustomManipulator();

	// ���ó�ʼ�ƶ��ٶ�
	void setSpeed(double speed);

	// ������ײ��⿪��
	void setCollision(bool b);

	void setCollisionNode(osg::Node* node){ m_pCollisionNode = node; }

protected:
	// ʵ�ֹ���matrix�����㣬�����������
	virtual void setByMatrix(const osg::Matrixd& mat);
	virtual osg::Matrixd getMatrix() const;

	// ʵ�ֹ���inverse matrix�����㣬�����������
	virtual void setByInverseMatrix(const osg::Matrixd& mat);
	virtual osg::Matrixd getInverseMatrix() const;

	// handle, �¼�����
	virtual bool handle(const osgGA::GUIEventAdapter& ea,
		osgGA::GUIActionAdapter& aa);

private:
	// �ı�λ�ã�deltaΪ�������Ǿ�����
	void changePosition(osg::Vec3d& delta);

private:
	double m_dSpeed;                           // �ƶ��ٶ�
	double m_dSpeedDelta;                      // �ٶ�������
	float m_fAngle;                            // ��ת����
	osg::Vec3d m_vecPosition;                  // λ��
	osg::Vec3d m_vecRotation;                  // ��ת

	bool m_bIsCollision;                       // ��ײ��⿪��
	osg::ref_ptr<osg::Node> m_pCollisionNode;  // ��ײ���ڵ�

	bool m_bIsLeftPressed;                     // ��¼����Ƿ���
	int m_iPressedX;                           // �������ʱXλ��
	int m_iPressedY;                           // �������ʱYλ��
};

#endif	// CUSTOMMANIPULATOR_H
