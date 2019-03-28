class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
        	vector<vector<int>> threeRes = threeSum(nums, target - nums[i], i + 1);
        	for (int j = 0; j < threeRes.size(); j++) {
        		threeRes[j].insert(threeRes[j].begin(), nums[i]);
        		res.push_back(threeRes[j]);
        	}
        	while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
private:
	vector<vector<int>> threeSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> res;
        for (int i = start; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            int remain = target - nums[i];
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
                    while (k > start && nums[k] == nums[k + 1]) k--;
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
