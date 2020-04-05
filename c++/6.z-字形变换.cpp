/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105333310
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (1 == numRows || len <= numRows) return s;

        std::vector<std::string> vec;
        vec.resize(numRows);
        int offset = -1;     // 偏移量，控制Z字走向
        for (int i = 0, idx = 0; i < len; ++i) {
            vec[idx] += s[i];
            if (idx == numRows - 1 || idx == 0) {
                offset = ~offset + 1;    // 到边缘了，调个头
            }
            idx += offset;
        }

        std::string ans;
        for (auto& str : vec) {
            ans.append(str);
        }
        return ans;
    }
};
// @lc code=end
