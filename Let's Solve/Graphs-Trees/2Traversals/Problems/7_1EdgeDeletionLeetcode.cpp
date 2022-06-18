// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    int precompute(TreeNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int a = precompute(node->left) + precompute(node->right);

        node->val += a;
        return node->val;
    }
    int center = 0;

    void traversal(TreeNode *node, int mid)
    {
        if (node == NULL)
        {
            return;
        }
        // cout << node->val << " " << (node->val - mid) << "\n";
        if (abs(node->val - mid) < abs(center - mid))
        {
            // cout << "Hello";
            center = node->val;
        }
        traversal(node->left, mid);
        traversal(node->right, mid);

        return;
    }

    int maxProduct(TreeNode *root)
    {
        precompute(root);
        int mid = (root->val) / 2;
        traversal(root, mid);
        // cout << root->val << " " << mid;
        int m = 1e9 + 7;
        return (1LL * (center % m) * ((root->val - center) % m)) % m;
    }
};