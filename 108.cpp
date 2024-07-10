/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<iostream>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);//数组，left，right
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;//此时数组为空
        }

        // 单数时选择中间位置的数字作为根节点，双数时选择中间2个节点中靠后的那一个
        int mid = (left + right + 1) / 2;

        TreeNode* root = new TreeNode(nums[mid]);//创建根节点
        //对半分，所以必为平衡二叉树
        root->left = helper(nums, left, mid - 1);//小的放在左子树
        root->right = helper(nums, mid + 1, right);//大的放在右子树
        return root;//递归中的每一次root都是新建的，这里的return为此次递归创建的，最终返回给sortarraytobst的为第一个根节点
    }
};
