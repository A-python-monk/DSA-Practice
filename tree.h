#include<vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    int data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data=data;
    }
};