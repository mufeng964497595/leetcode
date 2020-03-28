/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirx[] = {0, 1}, diry[] = {1, 0};

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 当前格子没有正方体，不用处理
                if (0 == grid[i][j]) continue;
                ans += grid[i][j] * 4 + 2;  // 四个面+上下底面

                // 查找当前格子右边和上面相邻的两个格子，减去重复的区域。
                for (int k = 0; k < 2; ++k) {
                    int x = i + dirx[k], y = j + diry[k];
                    if (x >= n || y >= n) continue;
                    // 两列都被挡住，所以减去的表面积要*2
                    ans -= std::min(grid[i][j], grid[x][y]) * 2;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
