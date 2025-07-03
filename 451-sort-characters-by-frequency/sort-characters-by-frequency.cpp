class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<pair<char, int>> mp2(mp.begin(), mp.end());
        sort(mp2.begin(), mp2.end(), [](pair<char, int>& a, pair<char, int>& b) {
                 return a.second > b.second;
             });

        string result;
        for (auto& entry : mp2) {
        result.append(entry.second, entry.first);  // append char 'freq' times
    }

    return result;
}

};