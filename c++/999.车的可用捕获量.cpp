/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 车的可用捕获量
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // 找车在哪
        int n = board.size();
        int x, y;
        bool bFind = false;
        for (int i = 0; !bFind && i < n; ++i) {
            for (int j = 0; !bFind && j < n; ++j) {
                if ('R' == board[i][j]) {
                    x = i; y = j;
                    bFind = true;
                }
            }
        }
        if (!bFind) return 0;

        // 四个方向都走一走，撞到边界、自家人、敌军就可以停了
        int ans = 0;
        int dirx[] = {0, 1, 0, -1}, diry[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; ++i) {
            int new_x = x + dirx[i];
            int new_y = y + diry[i];
            while (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                if ('B' == board[new_x][new_y]) break;
                if ('p' == board[new_x][new_y]) {
                    ++ans;
                    break;
                }

                new_x += dirx[i];
                new_y += diry[i];
            }
        }

        return ans;
    }
};
// @lc code=end
