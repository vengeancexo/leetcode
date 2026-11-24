class Solution {
public:
    long long converttobinary(long long i){
        long long ans = 0;
        while(i > 0){
            ans = (ans*10 + i%2);
            i /= 2;
        }
        return ans;
    }
    int summ(long long num){
        int ans = 0;
        while(num>0){
            if(num%10 == 1){
                ans+=1;
                num /=10;
            }
            else{
                num /= 10;
            }
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n;i++){
            ans.push_back(summ(converttobinary(i)));
        }
        return ans;
    }
};
