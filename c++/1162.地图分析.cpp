/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // 找出所有陆地的坐标，压入队列
        int dwLandNum(0);
        std::queue<Point> q;
        // bfs visit标记，其实也可以用grid来打标就行了，但是破坏原始数据的这个习惯不太好
        bool visit[105][105];
        memset(visit, 0, sizeof(visit));
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (1 == grid[i][j]) {
                    ++dwLandNum;
                    q.push(Point(i, j, 0));
                    visit[i][j] = true;
                }
            }
        }

        // bfs搜索就行了，最后一个找到的海洋就是目标
        int dirx[] = {0, 1, 0, -1}, diry[] = {1, 0, -1, 0};
        int ans = -1;
        while (!q.empty()) {
            Point p = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int x = p.x + dirx[i];
                int y = p.y + diry[i];
                if (x >= 0 && x < n && y >= 0 && y < n && !visit[x][y] && 0 == grid[x][y]) {
                    visit[x][y] = true;
                    ans = p.step + 1;
                    q.push(Point(x, y, ans));    // 压入队列
                }
            }
        }

        return ans;
    }

private:
    struct Point {
        int x, y;   // 坐标
        int step;   // 搜索到当前坐标所花费的步数
        Point(int xx = 0, int yy = 0, int s = 0)
            : x(xx), y(yy), step(s) {
        }
    };
};
// @lc code=end
