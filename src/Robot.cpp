#include "Robot.h"

Robot::Robot()
	:m_symbol('/')
{
	LaodTexture::LoadTexture a;
	
	 m_robot.setTexture(a.getTexture(m_symbol));
}