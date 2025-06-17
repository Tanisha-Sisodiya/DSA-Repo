class Solution {
public:
    int countDigits(int num) {
    int x = num;
    int d = 0;
    while(x>0){
        d++;
        x /= 10;
    } 
    int y = num;
    int count = 0;
    for(int i = 0; i<d; i++){
        int digit = y%10;

        if(num % digit == 0){
          count++;
        }
                y /= 10;
    }
    return count;
    }
};