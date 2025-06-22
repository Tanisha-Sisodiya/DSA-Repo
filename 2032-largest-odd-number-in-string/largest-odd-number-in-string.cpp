class Solution {
public:
    string largestOddNumber(string num) {
        int Max = 0;
        for(int i = num.size()-1; i>=0; i--){
            if(num[i]%2==1){
                string sub = num.substr(0, i+1);
                return sub;
            }
        }
        return "";
    }
};