int searchInsert(int* nums, int numsSize, int target) {
    int n = numsSize;
    int high=n-1;
    int low=0;
    int i=0,index,flag=0;
    int mid = (high+low)/2;
    while(low <= high){
        if(nums[mid] > target){
            high = mid-1;
        }
        if(nums[mid] < target){
            low = mid+1;
        }
        if(nums[mid] == target){
            index = mid;
            flag = 1;
            break;
        }
        mid = (high+low)/2;
    }
    if(flag == 1){
        return mid;
    }
    else{
        return low;
    }
        
}
