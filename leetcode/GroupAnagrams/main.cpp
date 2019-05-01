class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (anagrams.find(str) == anagrams.end()) {
                vector<string> items;
                anagrams[str] = items;
            }
            anagrams[str].push_back(strs[i]);
        }
        map<string, vector<string>>::iterator it;
        for (it = anagrams.begin(); it != anagrams.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
