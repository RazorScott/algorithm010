class Solution {
public:
    int binarySearch(vector<int>& v, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == target) return mid;
            else if (v[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return target == nums[0] ? 0 : -1;
        if (nums[0] <= nums[n-1]) {
            return binarySearch(nums, 0, n-1, target);
        }
        else {
            int low = 0;
            int high = n-1;
            while (low <= high) {
                int mid = low + (high - low)/2;
                if (nums[mid+1] < nums[mid]) {
                    if (target >= nums[0]) {
                        return binarySearch(nums, 0, mid, target);
                    }
                    else {
                        return binarySearch(nums, mid+1, n-1, target);
                    }
                }
                else if (nums[mid] >= nums[low]) {
                    low = mid + 1; 
                }
                else {
                    high = mid - 1;
                }
            } 
        }
        return -1;
    }
};
