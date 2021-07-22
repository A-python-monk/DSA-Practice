#include<iostream>
using namespace std;

template <typename T>
class binaryTreeNode
{   
    public:
    T data;
    binaryTreeNode<T>* right;
    binaryTreeNode<T>* left;

    binaryTreeNode(T data)
    {
        this->data=data;
    }

};