class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                char_stack.push(s[i]);
                continue;
            }
            if (char_stack.empty()) {
                return false;
            }
            if (s[i] == ')' && char_stack.top() == '(') {
                char_stack.pop();
            } else if (s[i] == ']' && char_stack.top() == '[') {
                char_stack.pop();
            } else if (s[i] == '}' && char_stack.top() == '{') {
                char_stack.pop();
            } else {
                return false;
            }
        }
        if (char_stack.empty()) {
            return true;
        }
        return false;
    }
};
