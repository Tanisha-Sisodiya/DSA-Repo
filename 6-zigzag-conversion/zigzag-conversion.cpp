class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows){
            return s;
        }
        vector<string> Rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for(char c: s){
            Rows[currentRow] += c;

            if(currentRow == 0 || currentRow == numRows - 1)
            goingDown =! goingDown;

            currentRow += goingDown? 1: -1;
        }
        string result;
        for(const string& row : Rows){
            result += row;
        }
        return result;
    }
};