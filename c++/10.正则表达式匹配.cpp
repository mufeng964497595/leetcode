/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105624569
 */

// @lc code=start
// 动态规划解法
class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        bool dp[1005][1005];    // dp[i][j]表示s[i:]与p[j:]的匹配结果
        memset(dp, 0, sizeof(dp));
        int len1 = s.length(), len2 = p.length();
        dp[len1][len2] = true;  // 两个串都为空

        for (int i = len1; i >= 0; --i) {
            // i从len1开始，是因为s是空串时也有可能匹配成功
            for (int j = len2 - 1; j >= 0; --j) {
                // j从len1开始，是因为p是空串时，除非s是空串，否则都匹配失败
                // 前面已设置dp[len1][len2]=true，已包含该逻辑，不需要再特殊处理
                if (s[i] == p[j] || p[j] == '.') {  // 当前字符匹配成功
                    if (j+1 >= len2 || p[j+1] != '*') {
                        // 下一个字符不是*，匹配结果取决于两个串的下一个字符
                        dp[i][j] = dp[i+1][j+1];
                    } else {
                        // 下一个字符是*，分0、多次这两个情况进行匹配
                        dp[i][j] = dp[i+1][j] || dp[i][j+2];
                    }
                } else if (j+1 < len2 && p[j+1] == '*') {
                    // 当前字符匹配失败，但下一个字符是*，则把*当作取0次进行匹配
                    dp[i][j] = dp[i][j+2];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
};

/*
//递归解法
class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        memset(ans, -1, sizeof(ans));
        return dp(0, 0, s.length(), p.length(), s, p);
    }

private:
    bool dp(int i, int j, int len1, int len2, const string& s, const string& p) {
        // 已计算过，不再重复计算，直接返回结果
        if (ans[i][j] != -1) return ans[i][j];

        // 正则串已结束，看匹配串空不空来确定匹配结果
        if (j >= len2) return ans[i][j] = i >= len1;

        if (i >= len1 && j < len2) {
            // 匹配串已结束，正则串还有，则把带有*的跳过看看是否能满足
            if (j+1 < len2 && p[j+1] == '*')
                return ans[i][j] = dp(i, j+2, len1, len2, s, p);
            return ans[i][j] = false;
        }

        bool res = false;
        if (s[i] == p[j] || p[j] == '.') {  // 当前字符匹配成功
            if (j+1 >= len2 || p[j+1] != '*') {
                // 下一个字符不是*，两个串都直接校验下一个字符
                res = dp(i+1, j+1, len1, len2, s, p);
            } else {
                // 下一个字符是*，分0、多这两种情况进行匹配
                res = dp(i+1, j, len1, len2, s, p) || dp(i, j+2, len1, len2, s, p);
            }
        } else if (j+1 < len2 && p[j+1] == '*'){
            // 当前字符匹配失败，但下一个字符是*，则把*当作取0次进行匹配
            res = dp(i, j+2, len1, len2, s, p);
        } else {
            res = false;
        }

        return ans[i][j] = res;
    }

private:
    int ans[1005][1005];    // 保存结果
};
*/
// @lc code=end
