class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> pos(2,0);
        for(char c : moves){
            if(c == 'U'){
                pos[0] += 1;
            }
            if(c == 'D'){
                pos[0] += -1;
            }
            if(c == 'L'){
                pos[1] += -1;
            }
            if(c == 'R'){
                pos[1] += 1;
            }
        }
        if(pos[0] == 0 && pos[1] == 0){
            return true;
        }
        return false;
    }
};