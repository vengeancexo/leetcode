class Solution {
public:
    int minFlips(int a, int b, int c) {
        string A = bitset<32>(a).to_string();
        string B = bitset<32>(b).to_string();
        string C = bitset<32>(c).to_string();
        int flips = 0;
        for(int i=0;i<A.size();i++){
            if(C[i] == '0') {
                if(A[i] == '1' && B[i] == '1')
                    flips += 2;
                else if(A[i] == '1' || B[i] == '1')
                    flips += 1;
            }
            else {
                if(A[i] == '0' && B[i] == '0')
                    flips += 1;
            }
        }
        return flips;
    }
};
