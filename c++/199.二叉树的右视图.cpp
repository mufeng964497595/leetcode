/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105696337
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        // 层次遍历
        queue<TreeNode*> qu;
        qu.push(root);
        int last_num = 1, num = 0;
        int current = 0;
        while (!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left) {
                qu.push(node->left);
                ++num;  // 更新下一层的个数
            }
            if (node->right) {
                qu.push(node->right);
                ++num;  // 更新下一层的个数
            }

            ++current;
            if (current == last_num) {  // 访问到当前层的最后一个
                ans.push_back(node->val);
                last_num = num;
                num = 0;
                current = 0;
            }
        }

        return ans;
    }
};
// @lc code=end
