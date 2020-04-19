/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105625784
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            ans = std::max(ans, std::min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return ans;
    }
};
// @lc code=end
