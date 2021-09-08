
#include"LinkedList.h"

using std::cout;
using std::cin;
using std::endl;


template<typename T>
LinkedList<T>::LinkedList()
	:m_pHead(nullptr)
	,m_pTail(nullptr)
	,m_iCount(0)
{
}
template<typename T>
LinkedList<T>::~LinkedList()
{
	delete m_pHead;
	delete m_pTail;
	cout << "객체 해제" << endl;
}
template<typename T>
void LinkedList<T>::AddCount()
{
	this->m_iCount++;
}

template<typename T>
void LinkedList<T>::SubCount()
{
	this->m_iCount++;
}


template<typename T>
int LinkedList<T>::Size()
{
	return this->m_iCount;


}

template<typename T>
void LinkedList<T>::Create(T data)
{
	if (this->IsEmpty() == true) 
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;
		this->m_pHead = newNode;
		this->m_pTail = newNode;
		this->AddCount();
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;

		this->m_pTail->next = newNode;
		this->m_pTail = newNode;
		this->AddCount();
	}
}

template<typename T>
void LinkedList<T>::Push(T data)
{

}

template<typename T>
void LinkedList<T>::Delete(T data)
{
	// 타겟을 가리키는 노드 // nullptr 일 경우  찾지 못함을 의미
	if (this->IsEmpty() == true)
	{
		cout << "is Empty !!!" << endl;
		return;
	}
	else
	{
		Node<T>* prevNode = this->Search(data);

		if (prevNode == nullptr)
			return;
		else
		{
			Node<T>* delNode = prevNode->next;
			if (prevNode->next->next == nullptr)
			{
				prevNode->next = nullptr;
			}
			else//nullptr이 아닐경우
			{
				prevNode->next = delNode->next;
			}
			free(delNode);
		}
	}
}

// 반환값은 검출된 주소를 가리키는 노드의 주소를 반환
template<typename T>
Node<T>* LinkedList<T>::Search(T data)
{
	int i = 0;
	Node<T>* temp = nullptr;
	while (1)
	{
		if (this->IsEmpty() == true)
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
		if (temp == nullptr)
			break;
	}
}

template<typename T>
void LinkedList<T>::Print()
{
	int i = 0;
	Node<T>* temp = nullptr;
	while (1)
	{
		if (this->IsEmpty() == true)
		{
			cout << "is Empty !!!" << endl;
			break;
		}
		else
		{
			if (temp == nullptr)
			{
				cout << i << "번째 노드 데이터 : " << this->m_pHead->data;
				temp = this->m_pHead->next;
			}
			else
			{
				cout << i << "번째 노드 데이터 : " << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
		i++;
		if (temp == nullptr)
			break;
	}
	cout << "------------------------------" << endl;
}

template<typename T>
void LinkedList<T>::Show()
{
	int i = 0;
	for (Node<T>* temp = this->m_pHead; 
		temp != nullptr; 
		temp = temp->next)
	{
		cout << i << "번째 노드 데이터 : " << temp->data;
		i++;
	}
}


template<typename T>
bool LinkedList<T>::IsEmpty()
{
	if (this->m_pHead == nullptr && this->m_pTail == nullptr)
		return true;
	return false;
}