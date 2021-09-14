#pragma once
#include"CNode.h"

class CQuadTree
{
public:
	static int	g_iCounter;
	CNode*		m_rootNode;
	std::queue<CNode*> m_Queue;

public:
	void Init(float fWidth, float fHeight);
	void BuildTree(CNode* ParentNode);
	CNode* CreateNode(CNode* TargetNode, float x, float y, float fWidth, float fHeight,int iDepth);
	void AddObject(CVector2 pos);
	CNode* FindNode(CNode* CurrentNode, CVector2 pos);
	bool isRact(CVector2 pos);
	bool isRact(CNode* CurrentNode, CVector2 pos);

public:
	~CQuadTree();

}; 

