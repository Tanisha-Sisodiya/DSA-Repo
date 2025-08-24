class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int ans = 0;
        int i = 1;
        while(n>=i){
            n = n-i;
            i++;
            ans++;
        }
        return ans;
        }

        
};