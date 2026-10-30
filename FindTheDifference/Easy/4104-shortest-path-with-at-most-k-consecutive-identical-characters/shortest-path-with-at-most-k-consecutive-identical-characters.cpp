class Solution {
public:
typedef tuple<int,int,int>T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<vector<int>>>adj;
        for(auto e: edges){
            int u= e[0];
            int v=e[1];
            int cost=e[2];
            adj[u].push_back({v,cost});
        }
        vector<vector<int>> result(n,vector<int>(k+1,INT_MAX));
        priority_queue<T,vector<T>,greater<T>>q;
        result[0][1]=0;
        q.push({0,0,1});
        while(!q.empty()){
            auto[d,node,count]=q.top();
            q.pop();
            if(d>result[node][count])
            continue;
            if(node==n-1)
            return d;
            for(auto e:adj[node]){
                int adjnode=e[0];
                int wt= e[1];
                int newC= (labels[adjnode]==labels[node])? count+1:1;
                if(newC>k)
                continue;
                int newD= d+wt;
                if(newD < result[adjnode][newC]){
                    result[adjnode][newC]=newD;
                    q.push({newD,adjnode,newC});
                }
            }
        }
        return -1;
    }
};