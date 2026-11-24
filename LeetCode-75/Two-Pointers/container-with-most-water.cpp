class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = 0, maxarea = 0;
        while(left <= right){
            area = min(height[left], height[right]) * (right - left);
            maxarea = max(maxarea, area);
            if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxarea;
    }
};
