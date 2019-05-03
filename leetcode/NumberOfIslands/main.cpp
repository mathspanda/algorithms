class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandNum = 0;
        vector<vector<int>> mark;
        for (int i = 0; i < grid.size(); i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++) {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && mark[i][j] == 0) {
                    bfs(mark, grid, i, j);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
private:
    void bfs(vector<vector<int>> &mark, 
            vector<vector<char>> &grid,
            int x, int y) {
        queue<pair<int, int>> q;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        q.push(make_pair(x, y));
        mark[x][y] = 1;
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= grid.size() || 
                    newy < 0 || newy >= grid[newx].size()) {
                    continue;
                }
                if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
                    q.push(make_pair(newx, newy));
                    mark[newx][newy] = 1;
                }
            }
        }
    }
};
