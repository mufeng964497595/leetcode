/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105333882
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数 或 末位为0的非0整数不是回文数
        if (x < 0 || (0 == (x % 10) && x != 0)) return false;

        int res = 0;
        while (x > 0) {
            int val = x % 10;
            res = res * 10 + val;
            if (res >= x) break;    // 为了让121之类的奇数位能通过
            x /= 10;
            if (res >= x) break;    // 为了让1221之类的偶数位能通过
        }

        return res == x;
    }
};
// @lc code=end
