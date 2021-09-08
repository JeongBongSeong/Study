#include "CLinkedList.h"



CLinkedList::CLinkedList()
	: m_iCount(0)
	, m_pHead(nullptr)
	, m_pTail(nullptr)
{
}

CLinkedList::~CLinkedList()
{
	cout << "exit" << endl;
}

void CLinkedList::Menu()
{
	cout << "------------------------------------------------" << endl;
	cout << "1.InsertFront" << endl;
	cout << "2.InsertBack" << endl;
	cout << "3.InsertCircle" << endl;
	cout << "4.CircleGame" << endl;
	cout << "(exit : -1)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Select Number : ";
}

void CLinkedList::Insert_Menu()
{
	cout << "------------------------------------------------" << endl;
	cout << "1. Add" << endl;
	cout << "2. Sub" << endl;
	cout << "3. Alt" << endl;
	cout << "4. Search" << endl;
	cout << "5. " << endl;
	cout << "(exit : -1 or prev stage : -2)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Select Number : ";
}


void CLinkedList::Circle_Menu()
{
	cout << "------------------------------------------------" << endl;
	cout << "1. Add" << endl;
	cout << "2. Sub" << endl;
	cout << "3. Alt" << endl;
	cout << "4. Search" << endl;
	cout << "5. " << endl;
	cout << "(exit : -1 or prev stage : -2)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Select Number : ";
}

void CLinkedList::Circle_Game_Menu()
{
	cout << "------------------------------------------------" << endl;
	cout << "1. Add Node" << endl;
	cout << "2. Game Start" << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
	cout << "5. " << endl;
	cout << "(exit : -1 or prev stage : -2)" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Select Number : ";
}

bool CLinkedList::Is_Empty()
{
	if(this->m_pHead == nullptr)
		return true;
	return false;
}

/*void CLinkedList::Create(int)
{
}*/

void CLinkedList::Create_Circle(int data)
{
	CNode* newNode = new CNode();
	newNode->data = data;
	m_pHead = m_pTail = newNode;
}

void CLinkedList::Insert_Circle(int data)
{
	//head와 tail이 최소 한 노드를 가르키고 있는 상태 (같은 노드)
	CNode* newNode = new CNode();
	newNode->data = data;

	// 현재 꼬리에 새로운 노드를 연결
	this->m_pTail->next = newNode;
	// 꼬리를 새로운 노르로 임명
	this->m_pTail = newNode;
	// 꼬리와 헤드를 연결
	this->m_pTail->next = this->m_pHead;
	this->m_iCount++;
}
//
//void CLinkedList::Insert_Front(int data)
//{
//}
//
//void CLinkedList::Insert_Back(int data)
//{
//}
//
CNode* CLinkedList::Search(int data)
{
	int i = 0;
	CNode* temp = nullptr;
	while (1)
	{
		if (this->Is_Empty() == true)
		{
			cout << "is Empty !!!" << endl;
			break;
		}
		else
		{
			if (temp == nullptr)
			{
				if (this->m_pHead->data == data)
					return this->m_pHead;
				else if (this->m_pHead->next->data == data)
					return this->m_pHead;
				else
				{
					temp = this->m_pHead->next;
				}
			}
			else
			{
				if (temp->next->data == data)
				{
					return temp;
				}
				temp = temp->next;
			}
		}
		i++;
		if (temp == m_pHead)
			break;
	}
}

CNode* CLinkedList::Pop(int data)
{
	if (this->Is_Empty() == true)
	{
		cout << "is Empty !!!" << endl;
		return nullptr;
	}
	else
	{
		CNode* prevNode = this->Search(data);
		this->Delete(prevNode);
		
	}

	return 0;
}

void CLinkedList::Delete(CNode* prevNode)
{
	if (prevNode == nullptr)
		return;
	else
	{
		CNode* delNode = prevNode->next;
		//if (prevNode->next->next == this->m_pHead)
		//{
		//	//prev가 헤드인경우 2개가 남을 경우에 하나를 지우기 때문에 nullptr로 변경
		//	prevNode->next = nullptr;
		//	m_pTail = prevNode;
		//}
		//else if (prevNode->next->next == this->m_pTail)
		//{
		//	prevNode->next = nullptr;
		//	m_pHead = prevNode;
		//}
		if (prevNode->next == nullptr)
		{
			delNode = prevNode;
			this->m_pHead = nullptr;
			this->m_pTail = nullptr;
		}
		else//nullptr이 아닐경우
		{
			if (this->m_pHead == delNode)
				this->m_pHead = delNode->next;
			else if (this->m_pTail == delNode)
				this->m_pTail = prevNode;
			
			if (this->m_pHead == this->m_pTail)
				this->m_pHead->next = nullptr;
			else
			{
				prevNode->next = delNode->next;
			}
		}
		delete(delNode);
	}
	
}

void CLinkedList::Size()
{
	cout << m_iCount << "개" << endl;
}

CNode* CLinkedList::ReturnHead()
{
	return this->m_pHead;
}

//void CLinkedList::Search(int data)
//{
//}
//
//void CLinkedList::Sort()
//{
//}
//
//void CLinkedList::Alter()
//{
//}
//
//void CLinkedList::Print()
//{
//}
