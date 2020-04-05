/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105332386
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int val = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && val > 7))
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && val < -8))
                return 0;
            ans = ans * 10 + val;
        }

        return ans;
    }
};
// @lc code=end
