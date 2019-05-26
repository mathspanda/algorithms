class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            _id.push_back(i);
            _size.push_back(i);
        }
        count = n;
    }
    
    int Find(int p) {
        while (p != _id[p]) {
            _id[p] = _id[_id[p]];
            p = _id[p];
        }
        return _id[p];
    }
    
    void Union(int p, int q) {
        int i = Find(p);
        int j = Find(q);
        if (i == j) {
            return;
        }
        if (_size[i] < _size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        count--;
    }
    
    int Count() {
        return count;
    }
private:
    vector<int> _id;
    vector<int> _size;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet _set(M.size());
        for (int i = 0; i < M.size(); i++) {
            for (int j = i + 1; j < M.size(); j++) {
                if (M[i][j]) {
                    _set.Union(i, j);
                }
            }
        }
        return _set.Count();
    }
private:
};
