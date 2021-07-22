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
        if (childData>root->data && childData!=-1)
        {
            binaryTreeNode<int>* rightChild = new binaryTreeNode<int>(childData);
            root->right=rightChild;
            pendindNodes.push(rightChild);
        }
        else if(childData!=-1)
        {
            binaryTreeNode<int>* leftChild = new binaryTreeNode<int>(childData);
            root->left=leftChild;
            pendindNodes.push(leftChild);
        }
    }
    return root;
}
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

int searchinBST(binaryTreeNode<int>* root,int data)
{
    if(root->data==data)
    {
        cout<<"True : "<<root->data;
        return 0;
    }
    else if(data > root->data)
    {
        searchinBST(root->right,data);
    }
    else{
        searchinBST(root->right,data);
    }

}


int main()
{
    binaryTreeNode<int>* root = buildBST();
    printTree(root);
    return 0;
}