/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105670313
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = 0;
        int last_left = -1;
        bool first = true;
        int ans = 0;
        while (left <= right && right < size) {
            // 找下一个奇数
            while (left < size && 0 == (nums[left] & 1)) ++left;
            if (left >= size) break;    // 没有奇数了
            // 找以这个奇数为开头的第k个奇数
            if (first) {
                // 第一次需要找出k个奇数的区间
                first = false;
                int current = 1;    // 当前有1个奇数
                right = left;
                while (current < k) {
                    ++right;
                    if (right >= size) break;
                    if (nums[right] & 1) ++current;
                }
                if (right >= size) break;   // 不足k个
            }

            // 找到了k个奇数的区间，数一下左、右各有几个连续偶数
            int left_num = left - last_left - 1;
            int next_right = right + 1;
            while (next_right < size && 0 == (nums[next_right] & 1)) {
                ++next_right;
            }
            int right_num = next_right - right - 1;
            // 套公式计算
            ans += (left_num + 1) * (right_num + 1);

            // 更新下次要进行操作的左右区间
            // 右边下一个奇数的位置其实已经算出来了，直接更新right就好了，不用再算一次
            last_left = left;
            ++left;
            right = next_right;
        }

        return ans;
    }
};
// @lc code=end
