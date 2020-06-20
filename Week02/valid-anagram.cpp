class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> ms, mt;
        if (s.size() != t.size()) return false;
        for (int i = 0; i< s.size(); ++i) {
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for (auto p : ms) {
            if (mt.count(p.first) == 0 || mt[p.first] != p.second) 
                return false;
        }
        return true;
    }
};
