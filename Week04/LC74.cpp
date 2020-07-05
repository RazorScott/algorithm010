class Solution {
public:
    bool binarySearch(vector<int>& v, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == target) return true;
            else if (v[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] < target) {
                low = mid + 1;
                if (low >= m || (low < m && matrix[low][0] > target)) {
                    low--;
                    break;
                }
            }
            else {
                high = mid;
            }
        }
        return binarySearch(matrix[low], 0, n-1, target);
    }
};
