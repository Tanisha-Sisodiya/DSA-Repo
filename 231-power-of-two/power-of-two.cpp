class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2 != 0) return false;
        while(n>=1){
            if(n%2 != 0) return false;
            if(n==2 || n==1) return true;
            n/=2;
        }
        return false;
    }
};