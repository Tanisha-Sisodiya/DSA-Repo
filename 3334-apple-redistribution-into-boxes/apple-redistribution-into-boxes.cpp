class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int i = 0; i< apple.size(); i++){
            sum += apple[i];
        }
        sort(capacity.begin(), capacity.end());
        int j = capacity.size()-1;
        while(sum > 0 && j>=0){
            sum -= capacity[j];
            j--;
        }
        return capacity.size()-j-1;
        }
};