/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [面试题62] 圆圈中最后剩下的数字
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105212527
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n, int m) {
        // func(n, m) = (m + func(n-1, m)) % n
        // func(1, m) = 0;
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (m + res) % i;
        }

        return res;
    }
};
// @lc code=end