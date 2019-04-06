class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1) {
            return points.size();
        }
        
        sort(points.begin(), points.end(), cmp);
        int num = 1;
        int begin = points[0].first;
        int end = points[0].second;
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i].first <= end) {
                begin = points[i].first;
                if (points[i].second < end) {
                    end = points[i].second;
                }
            } else {
                num++;
                begin = points[i].first;
                end = points[i].second;
            }
        }
        return num;
    }
    
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
};
