/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 * 题解代码：https://blog.csdn.net/feng964497595/article/details/105331747
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.empty())
            return s;

        // 初始化
        bool dp[1005][1005];
        memset(dp, 0, sizeof(dp));
        int len = s.length();
        for (int i = 0; i < len; ++i)
            dp[i][i] = true;

        int start = 0, end = 0;
        for (int step = 1; step < len; ++step) {
            for (int i = 0; i < len; ++i) {
                int j = i + step;
                if (j >= len) break;

                if (s[i] == s[j] && (i+1 >= j-1 || dp[i+1][j-1])) {
                    // [i+1, j-1]就是一个回文串，且s[i]==s[j]，则[i, j]本身就是一个回文串
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};
// @lc code=end
