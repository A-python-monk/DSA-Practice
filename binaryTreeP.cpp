#include "./binaryTree.h"
#include<queue>

binaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter the Data : ";
    cin>>rootData;
    if (rootData == -1)
    {
        return NULL;
    }  
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>* leftchild = takeInput();
    binaryTreeNode<int>* rightchild = takeInput();
    root->left=leftchild;
    root->right=rightchild;
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

binaryTreeNode<int>* takingInputLevelWise()
{
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftdata,rightdata;
        cout<<"Enter Left child of "<<front->data<<": ";
        cin>>leftdata;

        if (leftdata != -1)
        {
            binaryTreeNode<int>* leftChild= new binaryTreeNode<int>(leftdata);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }

        cout<<"Enter Right child of "<<front->data<<": ";
        cin>>rightdata;

        if (rightdata != -1)
        {
            binaryTreeNode<int>* rightChild = new binaryTreeNode<int>(rightdata);
            front->right=rightChild;
            pendingNodes.push(rightChild);
        }    
    }
return root;

}

int main()
{
    binaryTreeNode<int>* root = takingInputLevelWise();
    printTree(root);
}










