class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> visited;
        set<string> words;
        for (int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }
        q.push(make_pair(beginWord, 1));
        visited.insert(beginWord);
        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord) {
                return step;
            }
            for (int i = 0; i < word.length(); i++) {
                for (int j = 0; j < 26; j++) {
                    string temp = word;
                    temp[i] = 'a' + j;
                    if (words.find(temp) != words.end() && 
                        visited.find(temp) == visited.end()) {
                        q.push(make_pair(temp, step + 1));
                        visited.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};
