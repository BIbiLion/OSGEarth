#include "custommanipulator.h"

CustomManipulator::CustomManipulator()
:m_fAngle(2.5),
m_bIsCollision(true),
m_dSpeedDelta(0.1),
m_dSpeed(0.3),
m_bIsLeftPressed(false)
{
	m_vecPosition = osg::Vec3d(0, 0, 5);
	m_vecRotation = osg::Vec3d(osg::PI_2, 0, 0);
}

CustomManipulator::~CustomManipulator()
{

}

void CustomManipulator::setSpeed(double speed)
{
	m_dSpeed = speed;
}

void CustomManipulator::setCollision(bool b)
{
	m_bIsCollision = b;
}

void CustomManipulator::setByMatrix(const osg::Matrixd& mat)
{

}

osg::Matrixd CustomManipulator::getMatrix() const
{
	// �����ӿڵľ���
	osg::Matrixd mat;
	mat.makeRotate(m_vecRotation._v[0], osg::Vec3d(1.0, 0.0, 0.0),
		m_vecRotation._v[1], osg::Vec3d(0.0, 1.0, 0.0),
		m_vecRotation._v[2], osg::Vec3d(0.0, 0.0, 1.0));

	return mat * osg::Matrixd::translate(m_vecPosition);
}

void CustomManipulator::setByInverseMatrix(const osg::Matrixd& mat)
{

}

osg::Matrixd CustomManipulator::getInverseMatrix() const
{
	osg::Matrixd mat;
	mat.makeRotate(m_vecRotation._v[0], osg::Vec3d(1.0, 0.0, 0.0),
		m_vecRotation._v[1], osg::Vec3d(0.0, 1.0, 0.0),
		m_vecRotation._v[2], osg::Vec3d(0.0, 0.0, 1.0));

	// �����ӿڵ������
	return osg::Matrixd::inverse(mat * osg::Matrixd::translate(m_vecPosition));
}

bool CustomManipulator::handle(const osgGA::GUIEventAdapter& ea,
	osgGA::GUIActionAdapter& aa)
{
	switch (ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
	{
		if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Space)
		{
			// �ո�
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Plus)
		{
			// +������
			m_dSpeed += m_dSpeedDelta;
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Minus)
		{
			// -,����
			m_dSpeed -= m_dSpeedDelta;
			m_dSpeed = m_dSpeed <= 0.1 ? 0.1 : m_dSpeed;
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_W
			|| ea.getKey() == osgGA::GUIEventAdapter::KEY_Up)
		{
			// ��ǰ
			changePosition(osg::Vec3d(m_dSpeed * cosf(osg::PI_2 + m_vecRotation._v[2]),
				m_dSpeed * sinf(osg::PI_2 + m_vecRotation._v[2]), 0));
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_S
			|| ea.getKey() == osgGA::GUIEventAdapter::KEY_Down)
		{
			// ���
			changePosition(osg::Vec3d(-m_dSpeed * cosf(osg::PI_2 + m_vecRotation._v[2]),
				-m_dSpeed * sinf(osg::PI_2 + m_vecRotation._v[2]), 0));
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_A
			|| ea.getKey() == osgGA::GUIEventAdapter::KEY_Left)
		{
			// ����
			changePosition(osg::Vec3d(-m_dSpeed * sinf(osg::PI_2 + m_vecRotation._v[2]),
				m_dSpeed * cosf(osg::PI_2 + m_vecRotation._v[2]), 0));
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_D
			|| ea.getKey() == osgGA::GUIEventAdapter::KEY_Right)
		{
			// ����
			changePosition(osg::Vec3d(m_dSpeed * sinf(osg::PI_2 + m_vecRotation._v[2]),
				-m_dSpeed * cosf(osg::PI_2 + m_vecRotation._v[2]), 0));
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_Q)
		{
			// ����ת
			m_vecRotation._v[2] += osg::DegreesToRadians(m_fAngle);
			return true;
		}
		else if (ea.getKey() == osgGA::GUIEventAdapter::KEY_E)
		{
			// ����ת
			m_vecRotation._v[2] -= osg::DegreesToRadians(m_fAngle);
			return true;
		}
		break;
	}
	case osgGA::GUIEventAdapter::PUSH:
	{
		m_iPressedX = ea.getX();
		m_iPressedY = ea.getY();
		// ��������¼�
		if (ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			m_bIsLeftPressed = true;
		}
		else if (ea.getButton() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
		{
			//m_vecRotation._v[0] += osg::DegreesToRadians(m_fAngle);
		}
		return false;
	}
	case osgGA::GUIEventAdapter::RELEASE:
	{
		// ����ͷ��¼�
		m_bIsLeftPressed = false;
		return false;
	}
	case osgGA::GUIEventAdapter::DRAG:
	{
		// �϶��¼�
		if (m_bIsLeftPressed)
		{
			m_vecRotation._v[0] += osg::DegreesToRadians(0.001 *  (ea.getY() - m_iPressedY));
			m_vecRotation._v[2] -= osg::DegreesToRadians(0.001 * (ea.getX() - m_iPressedX));
			m_vecRotation._v[0] = m_vecRotation._v[0] >= 3.14 ? 3.14 : m_vecRotation._v[0];
			m_vecRotation._v[0] = m_vecRotation._v[0] <= 0 ? 0 : m_vecRotation._v[0];
		}
		else
		{
			if (ea.getY() > m_iPressedY)
			{
				m_vecRotation._v[0] += osg::DegreesToRadians(0.1 * m_fAngle);
			}
			else
			{
				m_vecRotation._v[0] -= osg::DegreesToRadians(0.1 * m_fAngle);
			}
		}
		return false;
	}
	case osgGA::GUIEventAdapter::SCROLL:
	{
		if (ea.getScrollingMotion() == osgGA::GUIEventAdapter::SCROLL_UP)
		{
			changePosition(osg::Vec3d(0, 3, 0));
			return true;
		}
		else if (ea.getScrollingMotion() == osgGA::GUIEventAdapter::SCROLL_DOWN)
		{
			changePosition(osg::Vec3d(0, -3, 0));
			return true;
		}
		return false;
	}
	default:
		return false;
	}
	return false;
}

void CustomManipulator::changePosition(osg::Vec3d& delta)
{
	if (m_bIsCollision)
	{
		// ������ײ���,����λ�ú;�λ�����߶��Լ���λ�õ����£������߶���
		osg::Vec3d newPos = m_vecPosition + delta;
		osgUtil::IntersectVisitor iv;
		osg::ref_ptr<osg::LineSegment> lineWidth = new osg::LineSegment(newPos, m_vecPosition);
		osg::ref_ptr<osg::LineSegment> lineHeight = new osg::LineSegment(
			newPos + osg::Vec3d(0, 0, m_dSpeed), newPos - osg::Vec3d(0, 0, m_dSpeed));
		iv.addLineSegment(lineWidth);
		iv.addLineSegment(lineHeight);
		m_pCollisionNode->accept(iv);
		if (!iv.hits())
		{
			// ��ײ���ʧ�ܣ������ƶ�
			m_vecPosition += delta;
		}
	}
	else
	{
		// δ������ײ���
		m_vecPosition += delta;
	}
}
