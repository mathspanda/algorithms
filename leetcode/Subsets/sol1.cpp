class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        generate(0, nums, item, res);
        return res;
    }
    
    void generate(int i, vector<int>& nums, 
                  vector<int>& item, 
                  vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(item);
            return;
        }
        item.push_back(nums[i]);
        generate(i + 1, nums, item, res);
        item.pop_back();
        generate(i + 1, nums, item, res);
    }
};
