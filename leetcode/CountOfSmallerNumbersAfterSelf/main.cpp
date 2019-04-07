class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> pairs;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back(make_pair(nums[i], i));
            res.push_back(0);
        }
        merge_sort(pairs, res);
        return res;
    }
private:
    void merge_sort(vector<pair<int, int>> &nums, vector<int> &count) {
        if (nums.size() <= 1) {
            return;
        }
        vector<pair<int, int>> sub1;
        vector<pair<int, int>> sub2;
        int mid = nums.size() / 2;
        for (int i = 0; i < mid; i++) {
            sub1.push_back(nums[i]);
        }
        for (int i = mid; i < nums.size(); i++) {
            sub2.push_back(nums[i]);
        }
        merge_sort(sub1, count);
        merge_sort(sub2, count);
        nums.clear();
        merge_two_sorted_vec(sub1, sub2, nums, count);
    }
    
    void merge_two_sorted_vec(vector<pair<int, int>> &sub1, 
                              vector<pair<int, int>> &sub2, 
                              vector<pair<int, int>> &nums, 
                              vector<int> &count) {
        int i = 0;
        int j = 0;
        while (i < sub1.size() && j < sub2.size()) {
            if (sub1[i].first <= sub2[j].first) {
                nums.push_back(sub1[i]);
                count[sub1[i].second] += j;
                i++;
            } else {
                nums.push_back(sub2[j]);
                j++;
            }
        }
        while (i < sub1.size()) {
            nums.push_back(sub1[i]);
            count[sub1[i].second] += j;
            i++;
        }
        while (j < sub2.size()) {
            nums.push_back(sub2[j]);
            j++;
        }
    }
};
