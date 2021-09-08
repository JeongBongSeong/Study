#include <iostream>

#define TYPE int
#define SIZE 10

using std::cout;
using std::cin;
using std::endl;

struct CNode
{
	TYPE m_Depth;
	TYPE m_Value;
	CNode* m_pChildNode[2] = { nullptr,nullptr };
	CNode();
	~CNode();
};
CNode::CNode() : m_Depth(-1), m_Value(-1), m_pChildNode{ nullptr,nullptr }{}
CNode::~CNode()
{
	int delValue = this->m_Value;
	if (m_pChildNode[0] != nullptr)
	{		
		delete m_pChildNode[0];
	}
	
	if (m_pChildNode[1] != nullptr)
	{
		delete m_pChildNode[1];
	}
	cout << "delValue : " << delValue << endl;
}

TYPE g_iData[SIZE] = { 5,0,4,7,8,3,9,2,6,1 };

CNode* g_pRoot = nullptr;



// 함수 선언부
void AddBinaryNode(CNode*, TYPE);
void Inorder(CNode*);
CNode* Find(CNode*, int);
void Delete(CNode*, int);

int main()
{
	CNode* findNode = nullptr;
	int iSize = SIZE;
	g_pRoot = new CNode();
	g_pRoot->m_Value = g_iData[0];


	for (int i = 1; i < iSize; i++)
	{
		AddBinaryNode(g_pRoot, g_iData[i]);
	}
	Inorder(g_pRoot);
	findNode = Find(g_pRoot, 6);
	cout << endl << "Value : " << findNode->m_Value << endl;
	cout << "Depth : " << findNode->m_Depth << endl;


	delete g_pRoot;

}

void Inorder(CNode* pNode)
{
	if (pNode == nullptr)
		return;
	cout << pNode->m_Value << " ";
	Inorder(pNode->m_pChildNode[0]);
	Inorder(pNode->m_pChildNode[1]);

}



CNode* Find(CNode* pNode, int data)
{
	if (pNode->m_Value == data)
	{
		return pNode;
	}
	else if (pNode->m_Value != data)
	{
		if (pNode->m_Value > data)
		{
			return Find(pNode->m_pChildNode[0], data);
		}
		else if ((pNode == nullptr))
			return nullptr;
		else
		{
			return Find(pNode->m_pChildNode[1], data);
		}
	}
	else if (pNode == nullptr)
	{
		return nullptr;
	}
}

void AddBinaryNode(CNode* pNode, TYPE data)
{
	if(pNode->m_Value > data)
		//오른쪽추가[1]
	{ 
		if (pNode->m_pChildNode[0] != nullptr)
		{
			AddBinaryNode(pNode->m_pChildNode[0], data);
		}
		else if (pNode->m_pChildNode[0] == nullptr)
		{
			pNode->m_pChildNode[0] = new CNode();
			pNode->m_pChildNode[0]->m_Value = data;
			pNode->m_pChildNode[0]->m_Depth = (pNode->m_Depth)+1;
		}
		else
		{
			cout << "잘못된 값" << endl;
		}
		
	}
	else
	{
		if (pNode->m_pChildNode[1] != nullptr)
		{
			AddBinaryNode(pNode->m_pChildNode[1], data);
		}
		else if (pNode->m_pChildNode[1] == nullptr)
		{
			pNode->m_pChildNode[1] = new CNode();
			pNode->m_pChildNode[1]->m_Value = data;
			pNode->m_pChildNode[1]->m_Depth = (pNode->m_Depth) + 1;
		}
		else
		{
			cout << "잘못된 값" << endl;
		}
	}
}
