class Solution {
public:
    long long ans(int n){
        if(n==0){
            return 0;
        }
        if(n==1 ){
            return 1;
        }
        return n + ans(n-1);

    }

    long long countSubstrings(string s, char c) {
        int count = 0;
        for(char t : s){
            if(t == c){
                count++;
            }
        }
        return ans(count);
    }
};