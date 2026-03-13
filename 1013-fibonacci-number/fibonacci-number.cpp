class Solution {
public:
    int f(int n, vector<int> &dparr){
        if(n==0 || n==1){
            return n;
        } 
        if(dparr[n] != -1){
            return dparr[n];
        }
        dparr[n] = f(n-1, dparr) + f(n-2, dparr);
        return dparr[n];
    }

    int fib(int n) {
        vector<int> dparr(n+1, -1);
        return f(n, dparr);
        
    }
};