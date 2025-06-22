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
        // int start = i;
        // int length = 1;
        // string sub = num.substr(start, length); 
        // int num = stoi(sub);
        // if(num%2 == 1){
        // Max = max(Max, num);
        // }
        // }
        // string ans = to_string(Max);
        return "";
    }
};