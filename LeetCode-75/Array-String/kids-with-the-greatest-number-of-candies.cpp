class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> arr(candies.size());
        int max = 0;
        for(int i=0;i<candies.size();i++){
            if(candies[i] > max){
                max = candies[i];
            }
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i] + extraCandies >= max){
                arr[i] = true;
            }
            else{
                arr[i] = false;
            }
        }
        return arr;
    }
};
