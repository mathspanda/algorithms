class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::map<int, int> num_map;
    	std::vector<int> res;
    	for (int i = 0; i < nums.size(); i++) {
    		if (num_map.find(target - nums[i]) != num_map.end()) {
    			res.push_back(num_map[target - nums[i]]);
    			res.push_back(i);
    			break;
    		}
    		num_map[nums[i]] = i;
    	}
    	return res;
    }
};
