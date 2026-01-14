class Solution {
public:
    long long mod = 1000000007;

    long long power(long long a, long long b) {
        if (b == 0) return 1;

        long long half = power(a, b / 2);
        half = (half * half) % mod;

        if (b % 2 == 0)
            return half;
        else
            return (half * a) % mod;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;  
        long long oddPos  = n / 2;       

        long long ans = (power(5, evenPos) * power(4, oddPos)) % mod;
        return ans;
    }
};
