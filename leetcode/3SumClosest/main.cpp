class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
            	int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                   return target;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
                if (abs(sum - target) < abs(closest - target)) {
                	closest = sum;
                }
            }
        }
        return closest;
    }
};
