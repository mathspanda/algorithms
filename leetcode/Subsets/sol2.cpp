class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int all = 1 << nums.size();
        for (int i = 0; i < all; i++) {
            vector<int> item;
            for (int j = 0; j < nums.size(); j++) {
                if ((1 << j) & i) {
                    item.push_back(nums[j]);
                }
            }
            res.push_back(item);
        }
        return res;
    }
};
