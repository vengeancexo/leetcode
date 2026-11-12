class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        for(int i=1;i<=searchWord.size();i++){
            string prefix = searchWord.substr(0,i);
            int low = 0, high = products.size();
            int mid = low + (high-low)/2;
            while(low < high){
                mid = low + (high-low)/2;
                if(products[mid] < prefix){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            vector<string> temp;
            for(int j=low; j<products.size() && temp.size()<3;j++){
                if(products[j].find(prefix) == 0){
                    temp.push_back(products[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
