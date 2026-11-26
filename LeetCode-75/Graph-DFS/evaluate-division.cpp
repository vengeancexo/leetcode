class Solution {
public:
    double dfs(string start, string end, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string> &vis, double prod){
        if(start == end)
            return prod;
        vis.insert(start);
        for(auto& [adj, wt] : graph[start]){
            if(vis.find(adj) == vis.end()){
                double ans = dfs(adj, end, graph, vis, prod*wt);
            if(ans != -1.0)
                return ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> graph;
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }
        vector<double> ans;
        for(auto& q : queries){
            string start = q[0];
            string end = q[1];
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> vis;

            double divi = dfs(start, end, graph, vis, 1.0);

            ans.push_back(divi);
        }
        return ans;
    }
};
