class Solution {
public:
    string minWindow(string s, string t) {
        int map_s[128] = {0};
        int map_t[128] = {0};
        for (int i = 0; i < t.length(); i++) {
            map_t[t[i]]++;
        }
        bool ok = false;
        int begin = 0;
        string res;
        for (int i = 0; i < s.length(); i++) {
            map_s[s[i]]++;
            while (begin < i) {
                if (map_t[s[begin]] == 0) {
                    begin++;
                } else if (map_s[s[begin]] > map_t[s[begin]]) {
                    map_s[s[begin]]--;
                    begin++;
                } else {
                    break;
                }
            }
            // Flag for ok is important!
            if (ok || is_ok(map_s, map_t, t)) {
                ok = true;
                int new_len = i - begin + 1;
                if (res == "" || new_len < res.length()) {
                    res = s.substr(begin, new_len);
                }
            }
        }
        return res;
    }

private:
    bool is_ok(int map_s[], int map_t[], string t) {
        for (int i = 0; i < t.length(); i++) {
            if (map_s[t[i]] < map_t[t[i]]) {
                return false;
            }
        }
        return true;
    }
};
