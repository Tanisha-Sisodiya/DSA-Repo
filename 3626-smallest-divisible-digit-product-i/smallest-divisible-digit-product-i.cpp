class Solution {
public:
    int product(int x, int prod){
        while(x){
            prod = prod*(x%10);
            x /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int x = n;
        int prod = 1;
        while(product(x, prod)%t != 0){
            x++;
        }
        return x;
    }
};