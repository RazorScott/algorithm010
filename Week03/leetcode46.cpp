class Solution {
public:
    void dfs(int c, int n, vector<int>& nums, vector<bool>& isput, vector<int>& cur, vector<vector<int>>& res) {
        if (c == n) res.push_back(cur); 
        for (int i = 0; i < n; ++i) {
            if (!isput[i]) {
                isput[i] = true;
                cur.push_back(nums[i]);
                dfs(c+1, n, nums, isput, cur, res);
                cur.pop_back();
                isput[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> isput(nums.size(), false);
        vector<int> cur;
        dfs(0, nums.size(), nums, isput, cur, res);
        return res;
    }
};
