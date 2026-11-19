class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector <int> days(n, 0);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[i] >= arr[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                days[i] = 0;
            }
            else{
                days[i] = stk.top()-i;
            }
            stk.push(i);
        }
        return days;
    }
};
