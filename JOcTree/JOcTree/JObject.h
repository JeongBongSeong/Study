#pragma once
#include"JVector.h"

class JObject{
public:
	std::string m_sName;
	JVector3 m_Pos;
	JVector3 m_Force;
	JVector3 m_Velocity;
	float m_fMass;
	JVector3 m_fAcceleration;
	int iIndexNode;

public:
	JObject();
	void Init(std::string sName,float fX, float fY, float fZ, float fForceX, float fForceY, float fForceZ, float fMass);
};

