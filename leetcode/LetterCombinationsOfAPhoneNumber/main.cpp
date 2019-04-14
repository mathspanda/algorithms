class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	if (digits.length() <= 0) {
    		return vector<string>();
    	}
    	string nums_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    	vector<string> res;
    	generate(0, digits, res, "", nums_map);
    	return res;    
    }
private:
	void generate(int index, string digits, 
		vector<string> &res, 
		string temp_res, 
		string nums_map[]) {
		if (index >= digits.length()) {
			res.push_back(temp_res);
			return;
		}
		int nums_index = digits[index] - '0' - 2;
		for (int i = 0; i < nums_map[nums_index].length(); i++) {
			string temp = temp_res + nums_map[nums_index][i];
			generate(index + 1, digits, res, temp, nums_map);
		}
	}
};
