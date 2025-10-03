class Solution {
public:
    // priority list () > ^ > / & * > + & -
    int calculate(string s) {
        stack<int> st;
    int num = 0;
    char op = '+';  // operator before current number

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // build multi-digit numbers
        }

        // if operator or last character, process the previous number
        if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {
            if (op == '+') {
                st.push(num);
            } else if (op == '-') {
                st.push(-num);
            } else if (op == '*') {
                int top = st.top(); st.pop();
                st.push(top * num);
            } else if (op == '/') {
                int top = st.top(); st.pop();
                st.push(top / num); // integer division truncates toward 0
            }
            op = ch;  // update operator
            num = 0;  // reset current number
        }
    }

    int result = 0;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}
};