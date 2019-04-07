class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> res_set;
        vector<int> item;
        sort(nums.begin(), nums.end());
        generate(0, nums, item, res, res_set);
        return res;
    }
    
    void generate(int i, vector<int>& nums, 
                  vector<int>& item, 
                  vector<vector<int>>& res, 
                  set<vector<int>>& res_set) {
        if (i >= nums.size()) {
            if (res_set.find(item) == res_set.end()) {
               res.push_back(item);
                res_set.insert(item);
            }
            return;
        }
        item.push_back(nums[i]);
        generate(i + 1, nums, item, res, res_set);
        item.pop_back();
        generate(i + 1, nums, item, res, res_set);
    }
};
