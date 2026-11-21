class Solution {
public:
unordered_map<int,vector<int>>adj;
vector<int>ans;
vector<int> last;

void dfs(int curr, string& s, vector<int>& parent){
   char currNode= s[curr]-'a';
   int nearest= last[currNode];
   last[currNode]=curr;
   for(int c: adj[curr]){
    dfs(c,s,parent);
   }
   last[currNode]= nearest;
   
   if(curr !=0){ 
    int newParent= parent[curr];
       if(nearest!=-1){
          newParent= nearest;
        }
      parent[curr]= newParent;
       ans[newParent]+= ans[curr];
      }
   }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n= parent.size();
         ans.assign(n,1);
         last.assign(26,-1);
        for(int i=1;i<n;i++){
            int u= parent[i];
            int v=i;
            adj[u].push_back(v);
        }
       dfs(0,s,parent);
        return ans;
    }
};