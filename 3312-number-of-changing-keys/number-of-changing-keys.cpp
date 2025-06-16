class Solution {
public:
    int countKeyChanges(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
        }
        int ans = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] != s[i+1]){
                ans++;
            }
        }
        return ans;
    }
};