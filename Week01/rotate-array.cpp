class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0) return;
        k = k % nums.size();
        vector<int> v(k);
        copy(nums.begin()+nums.size()-k, nums.end(), v.begin());
        for (int i = nums.size()-k-1; i >= 0; --i) {
            nums[i+k] = nums[i]; 
        }
        for (int i = 0; i< v.size(); ++i) {
            nums[i] = v[i];
        }
    }
};

//https://leetcode.com/problems/rotate-array/
