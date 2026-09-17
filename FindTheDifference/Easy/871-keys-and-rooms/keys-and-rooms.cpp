class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int> vis(n,0);
        queue<int> q;
        int count=1;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            auto x= q.front();
            q.pop();
            for(auto w: rooms[x]){
                if(!vis[w]){
                    vis[w]=1;
                    count++;
                    q.push(w);
                }
            }
        }
        return count==n;
    }
};