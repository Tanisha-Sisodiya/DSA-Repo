class Solution {
public:
    bool BinarySearch(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int high = arr.back() + k; 

        for (int i = 1; i <= high; i++) {
            if (!BinarySearch(arr, i)) {
                missing.push_back(i);
            }
        }

        return missing[k - 1];
    }
};
