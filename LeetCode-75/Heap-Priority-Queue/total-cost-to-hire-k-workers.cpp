class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> leftheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rightheap;
        int n = costs.size();
        int left = 0, right = n-1;
        for(int i = 0; i < candidates && left <= right; i++) {
            leftheap.push({costs[left], left});
            left++;
        }
        for(int i = 0; i < candidates && left <= right; i++) {
            rightheap.push({costs[right], right});
            right--;
        }
        long long ans = 0;
        for(int i=0; i<k; i++){

            if(rightheap.empty() ||
               (!leftheap.empty() && leftheap.top() <= rightheap.top())) {
                auto worker = leftheap.top();
                leftheap.pop();

                ans += worker.first;

                if(left <= right) {
                    leftheap.push({costs[left], left});
                    left++;
                }
            }
            else {
                auto worker = rightheap.top();
                rightheap.pop();
                ans += worker.first;
                if(left <= right) {
                    rightheap.push({costs[right], right});
                    right--;
                }
            }
        }
        return ans;
    }
};
