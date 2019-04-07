class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> mark;
        vector<string> loc;
        for (int i = 0; i < n; i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                mark[i].push_back(0);
            }
            loc.push_back("");
            loc[i].append(n, '.');
        }
        generate(0, n, loc, mark, res);
        return res;
    }
private:
    void put_down_queen(int x, int y, vector<vector<int>>& mark) {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        for (int i = 1; i < mark.size(); i++) {
            for (int j = 0; j < 8; j++) {
                int nx = x + i * dx[j];
                int ny = y + i * dy[j];
                if (nx >= 0 && nx < mark.size() && 
                    ny >= 0 && ny < mark.size()) {
                    mark[nx][ny] = 1;
                }
            }
        }
    }

    void generate(int col, int n, 
                  vector<string>& loc, 
                  vector<vector<int>>& mark, 
                  vector<vector<string>>& res) {
        if (col >= n) {
            res.push_back(loc);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mark[col][i] == 1) {
                continue;
            }
            vector<vector<int>> temp = mark;
            loc[col][i] = 'Q';
            put_down_queen(col, i, mark);
            generate(col + 1, n, loc, mark, res);
            mark = temp;
            loc[col][i] = '.';
        }
    }
};
