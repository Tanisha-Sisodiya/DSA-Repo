class Solution {
public:
    int getSingledigit(int num) {
        if (num < 10) return num;

        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return getSingledigit(sum);
    }

    int addDigits(int num) {
        return getSingledigit(num);
    }
};
