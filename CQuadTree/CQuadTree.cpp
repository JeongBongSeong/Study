#include"CQuadTree.h"


void CQuadTree::Init(float fWidth, float fHeight)
{
	this->m_rootNode = CreateNode(nullptr,0,0,fWidth,fHeight,0);
	CQuadTree::g_iCounter++;
	
	this->BuildTree(this->m_rootNode);
	
}

CNode* CQuadTree::CreateNode(CNode* pParent, float x, float y, float fWidth, float fHeight,int iDepth)
{
	CNode* newNode = new CNode(pParent, x, y, fWidth, fHeight,iDepth);
	return newNode;
}

void CQuadTree::BuildTree(CNode* pParentNode)
{
	//3 깊이 까지 생성 완료된 것을 확인 
	if (pParentNode->iDepth == 3) {
		return;
	}
	pParentNode->pChild[0] = CreateNode(pParentNode,
										pParentNode->pRact.p0.x,
										pParentNode->pRact.p0.y,
										pParentNode->pRact.p1.x / 2.0f,
										pParentNode->pRact.p1.y / 2.0f,
										pParentNode->iDepth+1);
	this->BuildTree(pParentNode->pChild[0]);
	g_iCounter++;

	pParentNode->pChild[1] = CreateNode(pParentNode->pChild[0],
										pParentNode->pChild[0]->pRact.p1.x,
										pParentNode->pChild[0]->pRact.p0.y,
										pParentNode->pChild[0]->pRact.wh.x,
										pParentNode->pChild[0]->pRact.wh.y,
										pParentNode->iDepth+1);
	this->BuildTree(pParentNode->pChild[1]);
	g_iCounter++;

	pParentNode->pChild[2] = CreateNode(pParentNode->pChild[0],
										pParentNode->pChild[0]->pRact.p0.x,
										pParentNode->pChild[0]->pRact.p1.y,
										pParentNode->pChild[0]->pRact.wh.x,
										pParentNode->pChild[0]->pRact.wh.y,
										pParentNode->iDepth+1);
	this->BuildTree(pParentNode->pChild[2]);
	g_iCounter++;

	pParentNode->pChild[3] = CreateNode(pParentNode->pChild[0],
										pParentNode->pChild[0]->pRact.p1.x,
										pParentNode->pChild[0]->pRact.p1.y,
										pParentNode->pChild[0]->pRact.wh.x,
										pParentNode->pChild[0]->pRact.wh.y,
										pParentNode->iDepth+1);
	this->BuildTree(pParentNode->pChild[3]);
	g_iCounter++;
}

bool CQuadTree::isRact(CVector2 pos)
{
	if (m_rootNode->pRact.p0.x <= pos.x &&
		m_rootNode->pRact.p0.y <= pos.y &&
		m_rootNode->pRact.p1.x >= pos.x &&
		m_rootNode->pRact.p1.y >= pos.y
		)
	{
		return true;
	}
	return false;
}

bool CQuadTree::isRact(CNode* CurrentNode, CVector2 pos)
{
	if (CurrentNode->pRact.p0.x <= pos.x &&
		CurrentNode->pRact.p0.y <= pos.y &&
		CurrentNode->pRact.p1.x >= pos.x &&
		CurrentNode->pRact.p1.y >= pos.y
		)
	{
		return true;
	}
	return false;
}

void CQuadTree::AddObject(CVector2 pos)
{
	CNode* retNode = FindNode(this->m_rootNode, pos);	
	retNode->ObjectList.push_back(pos);
	retNode->ObjectSize++;
	//Find(m_rootNode,pos)
}
CNode* CQuadTree::FindNode(CNode* CurrentNode,CVector2 pos)
{
	CNode* retQNode = nullptr;
	CNode* retNode = nullptr;
	
	if (isRact(CurrentNode, pos))
	{
		for (int i = 0; i < 4; i++)
		{
			if (CurrentNode->pChild[i] == nullptr)
				return CurrentNode;
			if (isRact(CurrentNode->pChild[i],pos))
			{
				
				this->m_Queue.push(CurrentNode->pChild[i]);
				break;
			}
		}
		
		retQNode = this->m_Queue.front();
		this->m_Queue.pop();
		retNode = FindNode(retQNode,pos);
		if (retNode == nullptr)
		{
			return retQNode;
		}
		//retNode = FindNode(CurrentNode->pChild[0],pos);
		//if (retNode != nullptr)
		//{
		//	return retNode;
		//}
		//retNode = FindNode(CurrentNode->pChild[1], pos);
		//if (retNode != nullptr)
		//{
		//	return retNode;
		//}
		//retNode = FindNode(CurrentNode->pChild[2], pos);
		//if (retNode != nullptr)
		//{
		//	return retNode;
		//}
		//retNode = FindNode(CurrentNode->pChild[3], pos);
		//if (retNode != nullptr)
		//{
		//	return retNode;
		//}
	}
	else
		return nullptr;


	return retNode;
}

CQuadTree::~CQuadTree()
{
	if (m_rootNode != nullptr)
	{
		delete(m_rootNode);
		CNode::g_iDelNodeCounter++;
	}
}
