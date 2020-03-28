/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 用map来记录已搜索过的值&对应的下标
        std::map<int, int> mVal2Idx;
        vector<int> vRes;
        // 提前分配空间，避免push_back触发空间重新分配，影响性能
        vRes.reserve(2);
        int size = nums.size();
        for (int i= 0; i < size; ++i) {
            int val = target - nums[i];
            auto mit = mVal2Idx.find(val);
            if (mVal2Idx.end() == mit) {
                // 没找到，将数组当前值送入map
                mVal2Idx.insert(std::make_pair(nums[i], i));
            } else {
                // 从map中找到另一个值，那就得到结果了。
                // 对于数组中有两个值相同的情况也兼容了，
                // 因为题目说只有一个答案，那么如果出现两个值相同且其中一个是答案的情况，
                // 就只能是这两个值都是答案这一种可能。
                // 而此时map里只有一个值，所以不存在下标被覆盖的情况
                // mit->second比较小，放前面
                vRes.push_back(mit->second);
                vRes.push_back(i);
                break;
            }
        }

        return vRes;
    }
};
// @lc code=end
