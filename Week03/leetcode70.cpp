class Solution {
public:
    void dfs(int c, int n, int k, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if (c > n) return;
        dfs(c+1, n, k, cur, res);
        cur.push_back(c);
        dfs(c+1, n, k, cur, res);
        cur.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(1, n, k, cur, res);
        return res;
    }
};
