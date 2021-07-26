#include "binaryTree.h"
#include<iostream>
using namespace std;

class BST
{
    binaryTreeNode<int>* root;

    public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    private:
    binaryTreeNode<int>* insert(int data,binaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            binaryTreeNode<int>* newNode = new binaryTreeNode<int>(data);
            return newNode;
        }
        else if(node->data < data)
        {
           node->right= insert(data,node->right);
        }
        else
        {
            node->left=insert(data,node->left);
        }
        return node;
    }
    public:
    void insert(int data)
    {
       this->root = insert(data,this->root);
    }

    private:
    binaryTreeNode<int>* deleteData(int data,binaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return NULL;
        }
        else if(data>node->data)
        {
            node->right = deleteData(data,node->right);
        }
        else if(data<root->data)
        {
           node->left = deleteData(data,node->left);
        }
        else
        {
            
            if((node->left==NULL) && (node->right== NULL))
            {
                delete node;
                return NULL;
            }
            else if((node->left==NULL) && (node->right!= NULL))
            {   binaryTreeNode<int>* temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if((node->left!=NULL) && (node->right== NULL))
            {   binaryTreeNode<int>* temp = node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else
            {
                binaryTreeNode<int>* minNode = node->right; 
                while (minNode->left!=NULL)
                {
                    minNode=minNode->left;
                }
                int minData=minNode->data;
                node->data=minData;
                node->right = deleteData(minData,node->right);
                
            }
        }
    }
    public:
    void deleteData(int data)
    {
        this->root=deleteData(data,this->root);
    }

    private:

    void printTree(binaryTreeNode<int>* root)
    {
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL)
    {
        cout<<" L "<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
    }

    public:
    void printTree()
    {
        printTree(root);
    }
};