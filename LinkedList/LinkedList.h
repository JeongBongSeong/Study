#pragma once

#include<iostream>

template<typename T>
class Node {
public:
	T data;
	Node* next;
};

template<typename T>
class LinkedList
{
private:
	int m_iCount;
	Node<T>* m_pHead;
	Node<T>* m_pTail;

public:
	LinkedList();
	~LinkedList();
	void Create(T data);
	void Push(T data);
	void Delete(T data);
	Node<T>* Search(T data);
	bool IsEmpty();
	void AddCount();
	void SubCount();
	int Size();
	void Print();
	void Show();
};
