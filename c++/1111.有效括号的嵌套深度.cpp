/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105327028
 */

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(const string& seq) {
        int len = seq.length();
        vector<int> ans;
        ans.resize(len);

        int depth(0);
        for (int i = 0; i < len; ++i) {
            if ('(' == seq[i]) {
                ans[i] = depth & 1;
                ++depth;
            } else {
                --depth;
                ans[i] = depth & 1;
            }
        }

        return ans;
    }
};
// @lc code=end
