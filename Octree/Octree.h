#include <iostream>


#define Octa 8

template<typename T>
struct Node
{
public:
    T mData;
    Node<T>*mChild;
public:
    Node();
    Node(int);
};


template<typename T>
class OcTree
{
private:
    Node<T>* m_node;
public:
    OcTree(int);
    void AddOcTreeNode(Node*);
};







template<typename T>
class Tree
{
private:
    Node<T>* Node;
public:
    
};


