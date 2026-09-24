class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq;
        queue<int> rq;
        int n = senate.size();
        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }
        while(!dq.empty() && !rq.empty()){
            if(dq.front() < rq.front()){
                rq.pop();
                int i = dq.front();
                dq.pop();
                dq.push(i+n);
            }
            else{
                dq.pop();
                int i = rq.front();
                rq.pop();
                rq.push(i+n);
            }
        }
        if(dq.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};
