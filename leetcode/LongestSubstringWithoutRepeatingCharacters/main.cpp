class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> char_map;
        string result;
        int begin = 0, max = 0;
        for (int i = 0; i < s.length() && begin < s.length(); i++) {
            if (char_map.find(s[i]) == char_map.end() || char_map[s[i]] < begin) {
                result += s[i];
            } else {
                if (result.length() > max) {
                    max = result.length();
                }
                begin = char_map[s[i]] + 1;
                result = s.substr(begin, i - begin + 1);
            }
            char_map[s[i]] = i;
        }
        if (result.length() > max) {
            max = result.length();
        }
        return max;
    }
};
