class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i< nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) != 0) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            } 
            else {
                m[nums[i]] = i;
            }
        }
        return res;
    }
};
