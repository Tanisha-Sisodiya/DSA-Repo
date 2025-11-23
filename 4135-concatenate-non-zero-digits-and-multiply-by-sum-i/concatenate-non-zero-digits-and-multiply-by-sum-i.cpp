class Solution {
public:
    // string str = to_string(num);
        // int num = stoi(str);
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        string str2 = "";
        for(int i = 0; i< str.length(); i++){
            if(str[i] != '0'){
                str2 += str[i];
            }
        }
        if (str2 == "") str2 = "0";

        long long x = stoll(str2);
        long long z = x;
        int sum = 0;
        while(z>0){
            sum += z%10;
            z /= 10;
        } 
        return x*sum;   
    }
};