class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maxScore = 0;
        int n = tokens.size();
        int j = n - 1;
        int i = 0;
        while(i<=j){
            if(tokens[i] <= power){
                score++;
                power -= tokens[i];
                i++;
                maxScore = max(maxScore, score);
            } else if(score>= 1){
                    score--;
                    power +=tokens[j];
                    j--;
            } else {
                break;
            }
        }
        return maxScore;
    }
};