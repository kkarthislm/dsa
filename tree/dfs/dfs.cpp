/*
dfs -> depth first search
three types are : inorder, preorder and postorder
inorder -> left, root, right
pre-order -> root, left, right
post-order -> left, right, root

there are multiple ways to solve dfs
1. recursive
2. iterative with extra memory (stack)
3. morris traversal
4. with two stacks (one to maintain the path/other one is to construct dfs)

in-order
1. recursive: O(n) time O(n) space
    -> call the helper recursively with TreeNode and result referrence
    -> return result if root == nullptr
    -> add val to the result if root.left recursion is completed
2. iterative: O(n) time O(n) space
    -> init a stack to retain TreeNode
    -> check TreeNode or stack not empty
    -> add all the root->left in stack
    -> peek/pop from stack and add to result
    -> move to root.right
3. morris: O(n) time O(1) space
    ->

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class DFS
{

private:
    // result is a ref var because call by value creates new memory
    vector<int> in_order_helper(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return result;
        in_order_helper(root->left, result);
        result.push_back(root->val);
        in_order_helper(root->left, result);
        return result;
    }

    vector<int> in_order_recursive(TreeNode *root)
    {
        vector<int> result;
        return in_order_helper(root, result);
    }

    vector<int> in_order_iterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stk;

        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root->left);
                root = root->left;
            }
            root = stk.top();
            result.push_back(root->val);
            stk.pop();
            root = root->right;
        }
        return result;
    }

    vector<int> in_order_morris(TreeNode *tree)
    {
        vector<int> result;
        return result;
    }

    // result is a ref var because call by value creates new memory
    vector<int> pre_order_helper(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return result;
        result.push_back(root->val);
        pre_order_helper(root->left, result);
        pre_order_helper(root->left, result);
        return result;
    }

    vector<int> pre_order_recursive(TreeNode *root)
    {
        vector<int> result;
        return pre_order_helper(root, result);
    }

    vector<int> pre_order_iterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stk;

        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                result.push_back(root->val);
                stk.push(root->left);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return result;
    }

    vector<int> pre_order_morris(TreeNode *tree)
    {
        vector<int> result;
        return result;
    }

    // result is a ref var because call by value creates new memory
    vector<int> post_order_helper(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return result;
        result.push_back(root->val);
        post_order_helper(root->left, result);
        post_order_helper(root->left, result);
        return result;
    }

    vector<int> post_order_recursive(TreeNode *root)
    {
        vector<int> result;
        return post_order_helper(root, result);
    }

    // need one more var to hold the previously visited node
    vector<int> post_order_iterative(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *pre = nullptr;

        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.push(root->left);
                root = root->left;
            }
            root = stk.top();
            if (root->right == nullptr || pre == root->right)
            {
                result.push_back(root->val);
                pre = root;
                stk.pop();
                root == nullptr;
            }
            else
            {
                root = root->right;
            }
        }
        return result;
    }

    vector<int> post_order_morris(TreeNode *tree)
    {
        vector<int> result;
        return result;
    }
};

int main()
{

    return 0;
}