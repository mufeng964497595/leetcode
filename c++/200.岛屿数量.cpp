/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105647901
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int width = grid.size();
        int height = grid[0].size();
        vector<vector<bool>> visit(width, vector<bool>(height, false));

        // bfs
        int ans = 0;
        int dirx[] = {0, 1, 0, -1}, diry[] = {1, 0, -1, 0};
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (visit[i][j] || '0' == grid[i][j]) continue;

                queue<Node> qu;
                qu.push(Node(i, j));
                while (!qu.empty()) {
                    Node node = qu.front();
                    qu.pop();
                    if (visit[node.x][node.y]) continue;
                    visit[node.x][node.y] = true;
                    for (int k = 0; k < 4; ++k) {
                        int x = node.x + dirx[k];
                        int y = node.y + diry[k];
                        if (x < 0 || x >= width || y < 0 || y >= height
                                || visit[x][y] || '0' == grid[x][y])
                            continue;
                        qu.push(Node(x, y));
                    }
                }
                ++ans;
            }
        }

        return ans;
    }

private:
    struct Node {
        int x, y;

        Node(int xx = 0, int yy = 0) : x(xx), y(yy) {
        }
    };
};
// @lc code=end
