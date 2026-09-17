class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
        return true;
        vector<vector<int>> adj(n);
        for(auto x:edges){
            int u= x[0];
            int v= x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        queue<int> q;
        vector<int> vis(n,0);
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x==destination)
                   return true;
            for(int m: adj[x]){
                
                if(!vis[m]){
                    vis[m]=1;
                    q.push(m);
                }
            }
        }
        return false;
    }
};