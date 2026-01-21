class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        for(char ch: s){
            if(isalpha(ch)){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ){
                    v++; 
                } else {
                    c++;
                }
            }
        }
        if (c == 0) return 0;
        return floor(v/c);
    }
};