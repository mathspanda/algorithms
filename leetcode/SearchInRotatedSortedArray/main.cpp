class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[begin] == nums[mid]) {
                begin = mid + 1;
            } else if (nums[mid] < target) {
                if (nums[begin] < nums[mid]) {
                    begin = mid + 1;
                } else if (nums[begin] > nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                }
            } else if (nums[mid] > target) {
                if (nums[begin] < nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else if (nums[begin] > nums[mid]) {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
