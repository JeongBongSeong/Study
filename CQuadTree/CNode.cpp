#include "CNode.h"
int CNode::g_iDelNodeCounter = 0;
CNode::CNode(CNode* parent, float x, float y, float w, float h, int d)
	:ObjectSize(0)
{
	this->pRact.wh = CVector2(w, h);
	this->pRact.p0 = CVector2(x,y);
	this->pRact.p1 = this->pRact.p0 + this->pRact.wh;
	this->iDepth = d;
	this->pParent = parent;
	
}

//void CNode::AddObject(CVector2 pTarget) 
//{
////오브젝트를 노드안에 추가하는 메소드
//	this->ObjectList.push_back(pTarget);
//	this->ObjectSize++;
//}

CNode::~CNode()
{
	for (int delNum = 0; delNum < 4; delNum++)
	{
		if (this->pChild[delNum] != nullptr) 
		{
			delete this->pChild[delNum];
			CNode::g_iDelNodeCounter++;
		}

	}
}