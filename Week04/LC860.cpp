class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c10 = 0;
        int c5 = 0;
        for (auto c: bills) {
            if (c == 20) {
                if (c10 > 0) {
                    c10--;
                    c5--;
                }
                else {
                    c5 -=3;
                }
                if (c5 < 0) return false;
            }
            else if (c == 10) {
                c10++;
                c5--;
                if (c5 < 0) return false;
            }
            else {
                c5++;
            }
        }
        return true;
    }
};
