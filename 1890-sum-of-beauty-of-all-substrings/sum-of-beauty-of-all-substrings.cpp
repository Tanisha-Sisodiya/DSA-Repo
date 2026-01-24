class Solution {
public:
    int beauty( vector<int>& alpha){
        int mf = -1;
        int lf = 1e9;
        for(int i = 0; i<alpha.size(); i++){
           mf = max(alpha[i], mf);
           if(alpha[i]>=1){
            lf = min(alpha[i], lf);
           }
        }
        return mf-lf;

    }
    int beautySum(string s) {
        int res = 0;

        for(int i = 0; i<s.size(); i++){
            vector<int>alpha(26,0);
            for(int j  = i; j<s.size(); j++){
            alpha[s[j]-'a']++;
            res = res + beauty(alpha);
            }

        }
        return res;

    }
};