#pragma once
#include"JObject.h"

class JNode{
public:
	JRact m_Rect;
	JNode* m_pParent;
	int m_iDepth;
	JNode* m_Child[MAXSIZE];
	int m_iIndex;
	std::vector<JVector3> m_ObjectList;
	std::map<std::string,JObject*> m_Dynamic_ObjectList;

public:
	JNode() {};
	JNode(JNode* p_Parent, float fX, float fY, float fZ, float fWidth, float fHeight, float fLength, int iDepth, int iIndex);
};

