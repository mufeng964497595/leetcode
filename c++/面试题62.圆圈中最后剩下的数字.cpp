/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [面试题62] 圆圈中最后剩下的数字
 * 题解博客：待周末补充
 */

/*
题目地址：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
设func(n, m)表示入参n、m移除的最后一个数是第几位（从1开始数），注意是**第几位**，而不是**是多少**
很显然，我们可以直接得到(n, m)移除的第一个数的下标是m%n，由于数字是排成一个圆圈，那么移除掉m%n后，我们把剩下的数看成是以(m%n+1)%n为头，长度为n-1的数组。这个数组的答案不就正好可以套进func(n-1, m)了么？
设func(n-1, m) = x，也就是说，(n, m)的结果是以(m%n+1)%n为开头的第x个数，也就是func(n, m) = (m%n+1+x-1)%n=(m%n+x)%n = (m+x)%n
由于func(1, m) = 0，故func(2, m) = (m + func(1, m))%2 = (m + 0) % 2，递推下去直到func(n, m)就可以得到答案
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