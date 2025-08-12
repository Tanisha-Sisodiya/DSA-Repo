class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int pos = -1;  // position of nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    pos = j;
                    break;
                }
            }

            int nextGreater = -1;
            if (pos != -1) {
                for (int k = pos + 1; k < nums2.size(); k++) {
                    if (nums2[k] > nums2[pos]) {
                        nextGreater = nums2[k];
                        break;
                    }
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
