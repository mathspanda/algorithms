class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        const int STATE_BEGIN = 0, STATE_UP = 1, STATE_DOWN = 2;
        int len = 1;
        int state = STATE_BEGIN;
        for (int i = 1; i < nums.size(); i++) {
            switch (state) {
            case STATE_BEGIN:
                if (nums[i] == nums[i - 1]) {
                    continue;
                } else if (nums[i] > nums[i - 1]) {
                    state = STATE_UP;
                    len++;
                } else {
                    state = STATE_DOWN;
                    len++;
                }
                break;
            case STATE_UP:
                if (nums[i] >= nums[i - 1]) {
                    continue;
                } else {
                    state = STATE_DOWN;
                    len++;
                }
                break;
            case STATE_DOWN:
                if (nums[i] <= nums[i - 1]) {
                    continue;
                } else {
                    state = STATE_UP;
                    len++;
                }
            }
        }
        return len;
    }
};
