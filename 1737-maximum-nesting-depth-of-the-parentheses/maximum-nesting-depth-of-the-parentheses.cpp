class Solution {
public:
    int maxDepth(string s) {
        int maxCount = 0;
        int Count = 0;
        for(char ch: s){
            if(ch == '(') Count++;
            if(ch == ')') Count--;
            maxCount = max(Count, maxCount);
        }
        return maxCount;
    }
};