#pragma once

#include<iostream>

template<typename T>
struct Node {
	T data;
	Node* next;
};

template<typename T>
class LinkedList
{
private:
	Node<T>* pHead;
	Node<T>* pTail;

public:
	LinkedList();
	void Create(T data);
	void Push(T data);
	void Delete(T data);
	Node<T>* Search(T data);
	bool IsEmpty();
	void Print();
};
