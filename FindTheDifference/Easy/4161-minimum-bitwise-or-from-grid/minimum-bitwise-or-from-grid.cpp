class Solution {
public:
int ans=INT_MAX;
 unordered_map<int, unordered_set<int>> visited;
   void dfs(vector<vector<int>>&grid, int row, int current){
        if(row==grid.size()){
            ans=min(ans,current);
            return;
        }
        if (visited[row].count(current)) return;
        visited[row].insert(current);

        for(int val: grid[row]){
            int nextval= current|val;
            if(nextval>=ans) continue;
            dfs(grid,row+1,nextval);
        }
   }
    int minimumOR(vector<vector<int>>& grid) {
        dfs(grid,0,0);
        return ans;
    }
};