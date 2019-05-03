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
        int target = sum / 4;
        
        vector<int> one_set;
        vector<int> half_set;
        int all = 1 << nums.size();
        for (int i = 0; i < all; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    sum += nums[j];
                }
            }
            if (sum == target) {
                one_set.push_back(i);
            }
        }
        for (int i = 0; i < one_set.size(); i++) {
            for (int j = i + 1; j < one_set.size(); j++) {
                if ((one_set[i] & one_set[j]) == 0) {
                    half_set.push_back(one_set[i] | one_set[j]);
                }
            }
        }
        for (int i = 0; i < half_set.size(); i++) {
            for (int j = i + 1; j < half_set.size(); j++) {
                if ((half_set[i] & half_set[j]) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
