class Solution {
public:
    int subtractProductAndSum(int n) {
        int x = n;  // 234
        int d = 0;  // 0
        while(x>0){    // t t t f
            x /= 10;   // 23 2 0
            d++;       // 1+1+1 = 3
        }
        int sum = 0;
        int product = 1;
        int y = n;     // 234
        for(int i = 0; i<d; i++){  // 0,1,2
        sum += y%10;        // 0+4+3+2 = 9
        product *= y%10;    // 1*4*3*2 = 24
        y /= 10;            // 23 2 0
        }
        return product - sum;  // 24 - 9 = 15
    }
};