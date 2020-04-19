/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105619937
 */

// @lc code=start
class Solution {
public:
    int myAtoi(const string& str) {
        int len = str.length();
        int begin = 0;
        int flag(1);    // 标记正负数，小技巧
        for (begin = 0; begin < len; ++begin) {
            if (' ' == str[begin]) continue;
            if ('-' == str[begin]) {
                // 负数符号，打上标记
                ++begin;
                flag = -1;
                break;
            } else if ('+' == str[begin]) {
                // 正数符号，打上标记
                ++begin;
                flag = 1;
                break;
            } else if (str[begin] >= '0' && str[begin] <= '9') {
                break;
            } else {
                return 0;
            }
        }

        int ans = 0;
        for (int i = begin; i < len; ++i) {
            if (str[i] < '0' || str[i] > '9') break;

            // 小技巧，乘以flag区分正负数
            int tmp = flag * (str[i] - '0');
            // 防止正数溢出
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tmp > 7) ) {
                return INT_MAX;
            }
            // 防止负数溢出
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && tmp < -8)) {
                return INT_MIN;
            }

            ans = ans * 10 + tmp;
        }

        return ans;
    }
};
// @lc code=end
