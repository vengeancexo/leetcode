class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0, high = k;
        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxi = sum / k;
        while(high < nums.size()) {
            sum -= nums[low];
            sum += nums[high];
            low++;
            high++;
            maxi = max(maxi, sum / k);
        }
        return maxi;
    }
};
