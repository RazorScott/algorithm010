 class Solution {
public:
    bool cantransform(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            count += (s1[i] != s2[i]); 
        }
        return count == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> used(wordList.size(), false);
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            level++;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                string ts = q.front();
                q.pop();
                for (int j = 0; j < wordList.size(); j++) {
                    if (!used[j] && cantransform(wordList[j], ts)) {
                        if (wordList[j] == endWord) return level;
                        used[j] = true;
                        q.push(wordList[j]);
                    }
                }
            }
        }
        return false;
    }
};
