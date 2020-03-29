/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256+5];   // 保存字符与下标的映射，字符ASCII码就那几百个
        memset(pos, -1, sizeof(pos));

        int len = s.length();
        int left = 0, right = 0;
        int ans = 0;
        while (right < len) {
            if (left == right) {
                // 指向同一个字符，记录下标，右指针右移
                pos[s[left]] = left;
                ++right;
                ans = std::max(ans, 1);
            } else {
                if (pos[s[right]] != -1 && pos[s[right]] >= left) {
                    // 发现left~right中间的重复字符，right - left就是不重复字符串的长度
                    ans = std::max(ans, right - left);
                    // 左指针移动到重复字符的右边一位，避开这个重复字符
                    left = pos[s[right]] + 1;
                } else {
                    // 未发现重复字符，更新当前长度
                    ans = std::max(ans, right - left + 1);
                }

                // 更新下标，右指针右移
                pos[s[right]] = right;
                ++right;
            }
        }

        return ans;
    }
};
// @lc code=end
