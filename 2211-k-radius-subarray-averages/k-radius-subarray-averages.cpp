class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    int m = 2 * k + 1;
    vector<int> ans(n, -1);
    if (m > n) return ans;
    long long sum = 0;

    for (int i = 0; i < m; i++) {
        sum += nums[i];
    }
    ans[k] = sum / m;

    for (int i = m; i < n; i++) {
        sum += nums[i];         
        sum -= nums[i - m];     

        int center = i - k;
        ans[center] = sum / m;
    }

    return ans;
}
};