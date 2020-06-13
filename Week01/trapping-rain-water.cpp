class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int sum = 0;
        while (i < height.size()) {
            int cap = 0;
            bool found = false;
            int h = -1;
            int p = i+1;
            for (int j = i + 1; j< height.size(); ++j) {
                if (height[j] >= height[i]) {
                    sum += cap;
                    i = j;
                    found = true;
                    break;
                }
                else {
                    cap += height[i] - height[j];
                    if (h <= height[j]) {
                        h = height[j];
                        p = j;
                    }
                }
            }
            if (!found) {
                cap = 0;
                for (int j = i+1; j< p; ++j) {
                    cap += h - height[j];     
                } 
                i = p;
                sum += cap; 
            }
        }
        return sum;
    }
};
