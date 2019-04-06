class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int step = 1;
        int prev_max = nums[0], cur_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > cur_max) {
                cur_max = prev_max;
                step++;
            }
            if (prev_max < nums[i] + i) {
                prev_max = nums[i] + i;
            }
        }
        return step;
    }
};
