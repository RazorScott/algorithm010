class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i< prices.size(); ++i) {
            int val = v[i-1];
            int t = prices[i] - prices[i-1];
            if (t > 0) val += t;
            v.push_back(val);
        }
        return v[v.size()-1];
    }
};
