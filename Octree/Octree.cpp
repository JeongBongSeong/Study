#include"Octree.h"
#include<vector>
template<typename T>
Node<T>::Node() : mData(NULL), mChild(nullptr){}


template<typename T>
Node<T>::Node(int n) : mData(NULL), mChild(new Node<T>[n]()) {}



template<typename T>
OcTree<T>::OcTree(int n)
	: m_node(new Node<T>(n)){}

template<typename T>
void OcTree<T>::AddOcTreeNode(Node<T>* a) 
{
	std::vector<Node<T>> q;
	q.push_back(a);
	a->mChild

	
	
	
	
	


}