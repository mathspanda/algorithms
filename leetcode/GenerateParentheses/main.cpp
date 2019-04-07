class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", n, n, res);
        return res;
    }
    
    void generate(string item, int left, int right, 
                  vector<string>& res) {
        if (!left && !right) {
            res.push_back(item);
            return;
        }
        if (left > 0) {
            generate(item + '(', left - 1, right, res);
        }
        if (left < right) {
            generate(item + ')', left, right - 1, res);
        }
    }
};
