
#include"LinkedList.h"

using std::cout;
using std::cin;
using std::endl;


template<typename T>
LinkedList<T>::LinkedList()
	:pHead(nullptr)
	,pTail(nullptr)
{
}



template<typename T>
void LinkedList<T>::Create(T data)
{
	if (this->IsEmpty() == true) 
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;
		this->pHead = newNode;
		this->pTail = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = nullptr;

		this->pTail->next = newNode;
		this->pTail = newNode;
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
				if (this->pHead->data == data)
					return this->pHead;
				else if (this->pHead->next->data == data)
					return this->pHead;
				else
				{
					temp = this->pHead->next;
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
				cout << i << "번째 노드 데이터 : " << this->pHead->data;
				temp = this->pHead->next;
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
}

template<typename T>
bool LinkedList<T>::IsEmpty()
{
	if (this->pHead == nullptr && this->pTail == nullptr)
		return true;
	return false;
}