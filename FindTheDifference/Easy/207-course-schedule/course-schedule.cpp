class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
         vector<int> inorder(numCourses,0);
         for(auto &a : prerequisites){
            adj[a[1]].push_back(a[0]);
            inorder[a[0]]++;
         }
         int count=0;
         queue<int> q;
         for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
            q.push(i);
         }
         while(!q.empty()){
            int node =q.front();
            count++;
            q.pop();
            for(auto &a: adj[node]){
                inorder[a]--;
                if(inorder[a]==0){
                    q.push(a);
                }
            }
         }
         return count==numCourses ;//no cycle
    }
};