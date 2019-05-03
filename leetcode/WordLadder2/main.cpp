struct Item {
    string word;
    int prev;
    int step;
    Item(string word, int prev, int step) : word(word), prev(prev), step(step) {}
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> g;
        constructG(beginWord, wordList, g);
        
        vector<Item> q;
        map<string, int> visited;
        vector<int> ends;
        q.push_back(Item(beginWord, -1, 1));
        visited[beginWord] = 1;
        
        int cur = 0;
        int minStep = 0;
        while (cur < q.size()) {
            string word = q[cur].word;
            int step = q[cur].step;
            if (step > minStep && minStep != 0) {
                break;
            }
            if (word == endWord) {
                minStep = step + 1;
                ends.push_back(cur);
            }
            vector<string> neighbours = g[word];
            for (int i = 0; i < neighbours.size(); i++) {
                string temp = neighbours[i];
                if (visited.find(temp) == visited.end() || 
                    visited[temp] == step + 1) {
                    q.push_back(Item(temp, cur, step + 1));
                    visited[temp] = step + 1;
                }
            }
            cur++;
        }
        
        vector<vector<string>> res;
        for (int i = 0; i < ends.size(); i++) {
            int pos = ends[i];
            res.push_back(vector<string>());
            while (pos != -1) {
                res[i].insert(res[i].begin(), q[pos].word);
                pos = q[pos].prev;
            }
        }
        return res;
    }

private:
    bool connect(string &word1, string &word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                count++;
            }
        }
        return count == 1;
    }
    
    void constructG(string beginWord, vector<string> &wordList,
                   map<string, vector<string>> &g) {
        bool has_begin_word = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                has_begin_word = true;
            }
            g[wordList[i]] = vector<string>();
        }
        g[beginWord] = vector<string>();
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (connect(wordList[i], wordList[j])) {
                    g[wordList[i]].push_back(wordList[j]);
                    g[wordList[j]].push_back(wordList[i]);
                }
            }
            if (!has_begin_word && connect(beginWord, wordList[i])) {
                g[beginWord].push_back(wordList[i]);
            }
        }
    }
};
