class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        for (int i = 0; i < 9; i++) {
            if (pow(2, i) <= k && k <= pow(2, i + 1)) {
                int opr = i;
                for (int j = 0; j <= opr; j++) {
                    string shifted = "";
                    for (char c : word) {
                        if (c >= 'a' && c <= 'z') {
                            shifted += (c == 'z') ? 'a' : c + 1;
                        }
                    }
                    word += shifted;
                }
                }
            }
            return word[k-1];
        }
    };