class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
       
        int n = board[0].size();

        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                q.push({i,0});
            if(board[i][n-1]=='O')
            q.push({i,n-1});
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
                q.push({0,i});
            if(board[m-1][i]=='O')
            q.push({m-1,i});
        }
      vector<vector<int>> dirs={{1,0},{-1,0} ,{0,1}, {0,-1}};
      while(!q.empty()){
        auto [x,y]= q.front();
        q.pop();

        if(x<0 || y<0 || x>=m || y>=n || board[x][y]!='O') continue;

         board[x][y]='T';
        
        for(auto &a : dirs){
            q.push({x+a[0], y+a[1]});
        }
      }
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]=='O') board[i][j]='X';
            if(board[i][j]=='T') board[i][j]='O';

        }
      }
    }
};
