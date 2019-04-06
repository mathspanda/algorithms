class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i + nums[i];
        }
        int max_index = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_index) {
                break;
            }
            if (nums[i] > max_index) {
                max_index = nums[i];
            }
        }
        if (max_index >= nums.size() - 1) {
            return true;
        }
        return false;
    }
};
