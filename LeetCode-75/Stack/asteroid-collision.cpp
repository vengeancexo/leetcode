class Solution {
public:
    bool diffdirection(int i, int j){
        return (i>0 && j<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> stk;
        for(int i=0;i<asteroids.size();i++){
            bool died = false;
            while(!stk.empty() && diffdirection(stk.top(), asteroids[i])){
                if(abs(asteroids[i]) > abs(stk.top())){
                    stk.pop();
                }
                else if(abs(stk.top()) == abs(asteroids[i])){
                    stk.pop();
                    died = true;
                    break;
                }
                else{
                    died = true;
                    break;
                }
            }
            if(!died){
                stk.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
