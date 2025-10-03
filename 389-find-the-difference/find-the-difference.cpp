class Solution {
public:
      // using XOR oppression 
    char findTheDifference(string s, string t) {
        string st = s+t;
        char ans = 0;
        for(char c: st){
            ans ^= c;   
        }
        return ans;
    }
};