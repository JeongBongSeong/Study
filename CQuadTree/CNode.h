#pragma once
#include"TStd.h"
class CNode
{
public:
	static int	g_iDelNodeCounter;
	TRect pRact;
	int iDepth;
	CNode* pParent;
	CNode* pChild[4];
	vector<CVector2> ObjectList;
	int ObjectSize;

public:
	CNode() {};
	CNode(CNode* parent, float x, float y, float w, float h, int d);
	~CNode();
	//void AddObject(CVector2 pTarget);
	
};



	