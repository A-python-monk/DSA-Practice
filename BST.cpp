#include "binaryTree.h"
#include<algorithm>
#include<queue>

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

/* 
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

int heightofBST(binaryTreeNode<int>* root)
{
    if (root==NULL)
    {
        return 0;
    }
    return 1 + max(heightofBST(root->left),heightofBST(root->right));
}

 int diameterofBST(binaryTreeNode<int>* root)
{
    if(root==NULL)
    return 0;

    int option1=heightofBST(root->left)+heightofBST(root->right);
    int option2=diameterofBST(root->left);
    int option3=diameterofBST(root->right);

    return max(option1,option2,option3);

} 


bool isBST(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return true;
    }

    return (root->data > root->left->data)&&(root->data < root->left->data)&&isBST(root->left)&& isBST(root->right);
}  
*/

binaryTreeNode<int>* buildTree(int *arr ,int si,int ei)
{      
    if (si>=ei)
    {
        return NULL;
    }
    int rootData=arr[(ei)/2];
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root->left = buildTree(arr,si,(ei/2)-1);
    root->right = buildTree(arr,(ei/2)-1,ei);
    return root;
}
 
int main()
{   
    int arr[] = {1,2,3,4,5,6,7};
    binaryTreeNode<int>* root = buildTree(arr,0,6);
    printTree(root);
    return 0;
}