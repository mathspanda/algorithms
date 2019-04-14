class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 0) {
            res.push_back(vector<int>());
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            vector<vector<int>> temp_res = this->permute(temp);
            for (int j = 0; j < temp_res.size(); j++) {
                temp_res[j].push_back(nums[i]);
                res.push_back(temp_res[j]);
            }
        }
        return res;
    }
};
