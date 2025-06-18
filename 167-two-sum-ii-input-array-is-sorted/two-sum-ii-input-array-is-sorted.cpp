class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int , int> mp;
        for(int i = 0; i<numbers.size(); i++){
            int compliment = target - numbers[i];
            
           if(mp.find(compliment) != mp.end()){
            return {mp[compliment], i+1};
           }

           mp[numbers[i]] = i + 1;
        }
        return {};

        
    }
};