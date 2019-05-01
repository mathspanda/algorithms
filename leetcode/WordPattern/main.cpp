class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;
        char used[128] = {0};
        string temp_word;
        int pattern_index = 0;
        
        str += ' ';
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (pattern_index == pattern.length()) {
                    return false;
                }
                if (word_map.find(temp_word) == word_map.end()) {
                    if (used[pattern[pattern_index]]) {
                        return false;
                    }
                    word_map[temp_word] = pattern[pattern_index];
                    used[pattern[pattern_index]] = 1;
                } else {
                    if (word_map[temp_word] != pattern[pattern_index]) {
                        return false;
                    }
                }
                temp_word = "";
                pattern_index++;
            } else {
                temp_word += str[i];
            }
        }
        
        if (pattern_index == pattern.length()) {
            return true;
        }
        return false;
    }
};
