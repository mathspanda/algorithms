class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> res_set;
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, item, res, res_set, 0, target);
        return res;
    }
    
    void generate(int i, vector<int>& nums, 
                  vector<int>& item, 
                  vector<vector<int>>& res, 
                  set<vector<int>>& res_set, 
                  int sum, int target) {
        if (sum > target) {
            return;
        }
        if (sum == target && res_set.find(item) == res_set.end()) {
            res_set.insert(item);
            res.push_back(item);
            return;
        }
        if (i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        generate(i + 1, nums, item, res, res_set, sum + nums[i], target);
        item.pop_back();
        generate(i + 1, nums, item, res, res_set, sum, target);
    }
};
