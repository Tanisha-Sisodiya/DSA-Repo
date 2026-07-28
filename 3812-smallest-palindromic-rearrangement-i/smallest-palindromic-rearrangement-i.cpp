class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string firstHalf = s.substr(0, n / 2);

        sort(firstHalf.begin(), firstHalf.end());

        // Put the sorted first half back.
        for (int i = 0; i < n / 2; i++) {
            s[i] = firstHalf[i];
        }

        // Mirror it.
        for (int i = 0; i < n / 2; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};