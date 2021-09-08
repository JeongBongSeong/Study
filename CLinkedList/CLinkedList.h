
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct CNode
{
	int data;
	CNode* next;
};

class CLinkedList
{
private:
	int m_iCount;
	CNode* m_pHead;
	CNode* m_pTail;


public:
	CLinkedList();
	~CLinkedList();

	void Menu();
	void Insert_Menu();
	void Circle_Menu();
	void Circle_Game_Menu();
// 
	bool Is_Empty();
	//void Create(int);
	void Create_Circle(int);
	
	void Insert_Circle(int);
	
	//void Insert_Front(int);
	//void Insert_Back(int);
	CNode* Search(int data);
	CNode* Pop(int);
	void Delete(CNode*);
	//void Search(int);
	//void Sort();
	//void Alter();
	//void Print();
	void Size();
	CNode* ReturnHead();
};


