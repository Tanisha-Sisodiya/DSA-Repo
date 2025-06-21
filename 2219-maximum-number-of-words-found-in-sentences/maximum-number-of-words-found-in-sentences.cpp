class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int Maxwords = 0;
        for (int i = 0; i < sentences.size(); i++) {
                int noWords = 1;
                for(int j = 0; j < sentences[i].size(); j++){
                if(sentences[i][j] == ' ') {
                    noWords++;
                }
                }

                if (Maxwords < noWords) {
                    Maxwords = noWords;
                }
        }
                
        return Maxwords;
            
    }
};