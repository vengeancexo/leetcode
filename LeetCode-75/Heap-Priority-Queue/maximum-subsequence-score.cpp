class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums1.size();i++){
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> minheap;
        long long ans = 0;
        long long currsum = 0;
        for(int i=0;i<nums1.size();i++){
            minheap.push(pairs[i].second);
            currsum += pairs[i].second;
            if(minheap.size() > k){
                int temp = minheap.top();
                minheap.pop();
                currsum -= temp;
            }
            if(minheap.size() == k){
                ans = max(ans, currsum*pairs[i].first);
            }
        }
        return ans;
    }
};
