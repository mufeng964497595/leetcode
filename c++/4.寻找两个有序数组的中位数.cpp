/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105327458
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        double res1 = FindKth(nums1, nums2, 0, size1 - 1, 0, size2 - 1, (size1 + size2 + 1) >> 1);
        double res2 = FindKth(nums1, nums2, 0, size1 - 1, 0, size2 - 1, (size1 + size2 + 2) >> 1);
        return (res1 + res2) / 2.0;
    }

private:
    double FindKth(const vector<int>& nums1, const vector<int>& nums2, int left1, int right1
            , int left2, int right2, int k) {
        if (left1 > right1){
            // 数组1是空的，直接可以从数组2得到结果
            return nums2[left2 + k - 1];
        } else if (left2 > right2) {
            // 数组2是空的，直接可以从数组1得到结果
            return nums1[left1 + k - 1];
        }

        if (1 == k) {
            // 找两个数组的第一个进行比较，取小的那个就行
            return std::min(nums1[left1], nums2[left2]);
        }

        int tmp = k >> 1;
        int idx1 = std::min(right1, left1 + tmp - 1);
        int idx2 = std::min(right2, left2 + tmp - 1);
        if (nums1[idx1] < nums2[idx2]) {
            // 舍弃数组1的前半部分
            return FindKth(nums1, nums2, idx1 + 1, right1, left2, right2, k - (idx1 - left1 + 1));
        } else {
            // 舍弃数组2的前半部分
            return FindKth(nums1, nums2, left1, right1, idx2 + 1, right2, k - (idx2 - left2 + 1));
        }
    }
};
// @lc code=end
