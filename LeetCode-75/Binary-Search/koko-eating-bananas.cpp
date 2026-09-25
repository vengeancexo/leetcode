class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesmax = INT_MIN;
        for(int pile : piles){
            if(pile > pilesmax){
                pilesmax = pile;
            }
        }
        int low = 1, high = pilesmax;
        while(low < high){
            int mid = low + (high-low)/2;
            long long totaltime = 0;
            for (int pile : piles) {
                totaltime += (pile + mid - 1) / mid;
            }
            if(totaltime > h){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
