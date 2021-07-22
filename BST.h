#include "binaryTree.h"
#include<queue>

binaryTreeNode<int>* buildBST()
{
    int rootdata=0;
    cout<<"Enter root data : ";
    cin>>rootdata;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootdata);
    queue<binaryTreeNode<int>*> pendindNodes;
    pendindNodes.push(root);
    while (pendindNodes.size() != 0)
    {   
        binaryTreeNode<int>* front = pendindNodes.front();
        pendindNodes.pop();
        int childData;
        cout<<"Enter child data : ";
        cin>>childData;
        if (childData>root->data)
        {
            binaryTreeNode<int>* root = new binaryTreeNode<int>(rootdata);
        }
        

    }
    




}




int main()
{

}