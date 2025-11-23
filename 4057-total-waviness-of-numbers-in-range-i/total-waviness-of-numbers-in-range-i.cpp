class Solution {
public:
    int totalWaviness(int num1, int num2){
        int count = 0;   
        for(int i = num1; i<=num2; i++){
            string str = to_string(i);
            for(int j = 1; j< str.length()-1; j++){
                int x = str[j-1]-'0';
                int y = str[j] - '0';
                int z = str[j+1] - '0';
                if((x < y && y > z) ||(x > y && y < z) ) count++;
            }
        }
        return count;
    }
};