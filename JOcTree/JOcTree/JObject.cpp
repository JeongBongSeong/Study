#include "JObject.h"

JObject::JObject(){
	m_Pos = JVector3(0.0f, 0.0f, 0.0f);
	this->m_fAcceleration.x = 1.0f;
	this->m_fMass = 1;
}

void JObject::Init(std::string sName, float fX,float fY, float fZ, float fForceX, float fForceY, float fForceZ,float fMass)
{
	this->m_sName = sName;
	this->m_Pos = JVector3(fX, fY, fZ);
	this->m_Force = JVector3(fForceX, fForceY, fForceZ);
	this->m_fMass = fMass;
	this->m_fAcceleration.x = fForceX / fMass;
	this->m_fAcceleration.y = fForceY / fMass;
	this->m_fAcceleration.y = fForceZ / fMass;

	
	this->m_Velocity = JVector3(0.0f, 0.0f, 0.0f);
	this->iIndexNode = NULL;
}
