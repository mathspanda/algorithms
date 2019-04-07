class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> item;
        generate(0, candidates, item, res, 0, target);
        return res;
    }
    
    void generate(int i, vector<int>& nums, 
                  vector<int>& item, 
                  vector<vector<int>>& res, 
                  int sum, int target) {
        if (sum == target) {
            res.push_back(item);
            return;
        }
        if (sum > target || i >= nums.size()) {
            return;
        }
        item.push_back(nums[i]);
        generate(i, nums, item, res, sum + nums[i], target);
        item.pop_back();
        generate(i + 1, nums, item, res, sum, target);
    }
};
