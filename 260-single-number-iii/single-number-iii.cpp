class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorAll = 0;

        for (int num : nums)
            xorAll ^= num;

        unsigned int mask = xorAll & (~xorAll + 1); // safe replacement for -xorAll

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & mask)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
