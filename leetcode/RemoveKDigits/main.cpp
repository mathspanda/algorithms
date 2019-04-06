class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        
        for (int i = 0; i < num.length(); i++) {
            int temp = num[i] - '0';
            while (k > 0 && !s.empty() && s.top() > temp) {
                s.pop();
                k--;
            }
            if (temp != 0 || !s.empty()) {
                s.push(temp);
            }
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        
        string res;
        while (!s.empty()) {
            res.insert(res.begin(), s.top() + '0');
            s.pop();
        }
        if (res == "") {
            res = "0";
        }
        return res;
    }
};
