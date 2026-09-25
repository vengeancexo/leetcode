class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());

        int ans = 0;

        for (int i : arr) {
            if (arr.count(i - 1) == 0) {
                int curr = i;
                int length = 1;

                while (arr.count(curr + 1)) {
                    curr++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
