class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (const string& op : operations) {
            int size = record.size();
            if (op == "C") {
                record.pop_back();
            } else if (op == "D") {
                record.push_back(record[size-1] * 2);
            } else if (op == "+") {
                record.push_back(record[size-1] + record[size-2]);
            } else {
                int num = stoi(op);
                record.push_back(num);
            }
        }
        int sum = 0;
        for (int i = 0; i < record.size(); i++) {
            sum += record[i];
        }
        return sum;
    }
};