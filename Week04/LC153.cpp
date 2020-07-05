class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int low = 0; 
        int high = n - 1;
        if (nums[low] < nums[high]) return nums[low];
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid+1]) {
                return nums[mid+1];
            }
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            else {
                low = mid + 1; 
            }
        }
        return 0;
    }
};
