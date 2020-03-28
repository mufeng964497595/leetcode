/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // 用map统计每个数字有几张牌
        std::map<int, int> mCard2Num;
        for (auto val : deck) {
            ++mCard2Num[val];
        }

        // 计算各个数的最大公约数，大于1就表示有超过一种分配方法
        int gcd = 1;
        bool first = true;
        for (auto item : mCard2Num) {
            if (first) {
                // 第一个数是自己的最大公约数
                gcd = item.second;
                first = false;
            } else {
                // 计算最大公约数
                gcd = CalcGCD(gcd, item.second);
            }

            if (1 == gcd) break;
        }

        return gcd > 1;
    }

private:
    int CalcGCD(int a, int b) {
        return b == 0 ? a : CalcGCD(b, a % b);
    }
};
// @lc code=end
