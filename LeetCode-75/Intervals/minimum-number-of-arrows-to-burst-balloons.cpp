class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int ans = 1;
        int currend = points[0][1];
        for(int i=1;i<points.size();i++){
            int nextstart = points[i][0];
            if(currend < nextstart){
                ans++;
                currend = points[i][1];
            }
        }
        return ans;
    }
};
