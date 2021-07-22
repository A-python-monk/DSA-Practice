#include "tree.h"
#include<queue>
#include<iostream>
using namespace std;

TreeNode<int>* takinginputlevelwise()
{
    int rootdata;
    cout<<"Enter Root Data : ";
    cin>>rootdata;
    queue<TreeNode<int>* > pendingNodes;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        int numberofchilds;
        TreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of child of "<<front->data<<" : ";
        cin>>numberofchilds;
        for(int i=0;i<numberofchilds;i++)
        {   int childData;
            cout<<"Enter the "<<i<<"th child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}
int count=0;
int countNumberOfLeaves(TreeNode<int>* root)
{ 
    if (root->children.size()==0)
    {
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        countNumberOfLeaves(root->children[i]);
        cout<<count;
    }
    
}
// 1 3 2 3 4 2 5 6 1 7 1 9 0 0 1 8 0 0

void printAtLevelK(TreeNode<int>* root,int k)
{
    if (k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
}
   
int height=0,temp=0;
int heightofTree(TreeNode<int> * root)
{
    if(root->children.size() !=0)
    {
        temp+=1;
        for(int i=0;i<root->children.size();i++)
       {
        heightofTree(root->children[i]);
          }
    }
    else{
        if(temp>=height){
        height=temp;
        temp=0;}
    }
 return height + 1;
}


int main()
{
    TreeNode<int>* root = takinginputlevelwise(); 
    printTree(root);
    cout<<heightofTree(root);

    return 0;

}