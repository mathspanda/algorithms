class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 4 != 0) {
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        int bucket[4] = {0};
        return generate(nums, 0, bucket, sum / 4);
    }
    
    bool generate(vector<int>& nums, int index, int bucket[], int target) {
        if (index >= nums.size()) {
            return bucket[0] == target && bucket[1] == target && 
                bucket[2] == target && bucket[3] == target;
        }
        for (int i = 0; i < 4; i++) {
            if (nums[index] + bucket[i] > target) {
                continue;
            }
            bucket[i] += nums[index];
            if (generate(nums, index + 1, bucket, target)) {
                return true;
            }
            bucket[i] -= nums[index];
        }
        return false;
    }
};
