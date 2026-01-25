class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = min(strs[0].size(), strs[1].size());
        string common = strs[0];
        string curr = "";
        for(int i = 1; i<strs.size(); i++){
            curr = "";
            for(int j = 0; j<strs[i].size(); j++){
                if(j<common.size() && common[j] == strs[i][j]){
                  curr += common[j];
              } else {
                break;
              }
            }
            common = curr;
        }
        return common;
    }
};