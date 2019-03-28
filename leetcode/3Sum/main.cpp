class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            int remain = 0 - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == remain) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    j++;
                    k--;
                    while (j < nums.size() && nums[j] == nums[j - 1]) j++;
                    while (k > 0 && nums[k] == nums[k + 1]) k--;
                } else if (nums[j] + nums[k] < remain) {
                    j++;
                } else {
                    k--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};
