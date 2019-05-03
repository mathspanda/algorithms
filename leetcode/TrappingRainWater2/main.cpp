struct Item {
    int x;
    int y;
    int h;
    Item(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
};

struct cmp {
    bool operator() (const Item &a, const Item &b) {
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }
        int row = heightMap.size();
        int col = heightMap[0].size();
        priority_queue<Item, vector<Item>, cmp> q;
        vector<vector<int>> mark;
        for (int i = 0; i < row; i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < col; j++) {
                mark[i].push_back(0);
            }
        }
        for (int i = 0; i < row; i++) {
            mark[i][0] = 1;
            mark[i][col - 1] = 1;
            q.push(Item(i, 0, heightMap[i][0]));
            q.push(Item(i, col - 1, heightMap[i][col - 1]));
        }
        for (int i = 1; i < col - 1; i++) {
            mark[0][i] = 1;
            mark[row - 1][i] = 1;
            q.push(Item(0, i, heightMap[0][i]));
            q.push(Item(row - 1, i, heightMap[row - 1][i]));
        }
        
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        int sum = 0;
        while (!q.empty()) {
            int x = q.top().x;
            int y = q.top().y;
            int h = q.top().h;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= row || newy < 0 || newy >= col || 
                   mark[newx][newy]) {
                    continue;
                }
                if (h > heightMap[newx][newy]) {
                    sum += (h - heightMap[newx][newy]);
                    heightMap[newx][newy] = h;
                }
                q.push(Item(newx, newy, heightMap[newx][newy]));
                mark[newx][newy] = 1;
            }
        }
        return sum;
    }
};
