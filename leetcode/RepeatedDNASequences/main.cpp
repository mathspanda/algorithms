int h_map[1048576] = {0};

string change_int_to_DNA(int aint) {
    char DNAs[] = {'A', 'C', 'G', 'T'};
    string str;
    for (int i = 0; i < 10; i++) {
        str += DNAs[aint & 3];
        aint = aint >> 2;
    }
    return str;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10) {
            return res;
        }
        for (int i = 0; i < 1048576; i++) {
            h_map[i] = 0;
        }
        int char_map[128];
        char_map['A'] = 0;
        char_map['C'] = 1;
        char_map['G'] = 2;
        char_map['T'] = 3;
        int key = 0;
        for (int i = 9; i >= 0; i--) {
            key = (key << 2) + char_map[s[i]];
        }
        h_map[key] = 1;
        
        for (int i = 10; i < s.length(); i++) {
            key = key >> 2;
            key = key | (char_map[s[i]] << 18);
            h_map[key]++;
        }
        for (int i = 0; i < 1048576; i++) {
            if (h_map[i] > 1) {
                res.push_back(change_int_to_DNA(i));
            }
        }
        return res;
    }
};
