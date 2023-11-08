#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p != nullptr && q != nullptr){
            return p->val == q->val;
        }else if(p == nullptr && q == nullptr){
            return true;
        }else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main(){

    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2));

    Solution s;
    cout << s.isSameTree(p,q) << endl;

    return 0;
}