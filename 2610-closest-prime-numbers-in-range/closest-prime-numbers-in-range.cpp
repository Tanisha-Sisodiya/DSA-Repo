class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<int> prime;

        for (int i = max(2, left); i <= right; i++) {
            bool isPrime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                prime.push_back(i);
        }

        vector<int>ans(2, -1);
        int min = INT_MAX;
        if (prime.size() < 2)
        return {-1, -1};
        
        for(int i = 0; i<prime.size()-1; i++){
            if(prime[i+1]-prime[i] < min){
                int x = prime[i];
                int y = prime[i+1];
                min = prime[i+1]-prime[i];
                ans[0]= x;
                ans[1] =y;
            }
            
        }
        return ans;

    }
};