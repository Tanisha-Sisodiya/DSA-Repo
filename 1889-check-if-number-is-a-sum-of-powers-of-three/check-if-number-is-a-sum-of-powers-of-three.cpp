class Solution {
public:
    bool checkPowersOfThree(int n) {
        int sum = 0;
        for (int i = 0; i <= 15; i++) {
            if (n < pow(3, i)) {
                for (int j = i - 1; j >= 0; j--) {
                    int y = pow(3, j);
                    if (sum + y <= n) {
                        sum = sum + y;
                        if (n == sum) {
                            return true;
                        }
                    }
                }
                            break;
            }

        }
        return false;
    }
};