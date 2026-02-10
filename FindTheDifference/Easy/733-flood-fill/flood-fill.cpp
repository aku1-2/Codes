class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n= image[0].size();
        
         int oldcolor= image[sr][sc];
         if(oldcolor==color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        
            image[sr][sc]=color;
            

        int dx[4]= {-1,1,0,0};
        int dy[4]= {0,0,-1,1};

        while(!q.empty()){
                auto [x,y] =q.front();
                q.pop();

                for(int j=0;j<4;j++){
                    int nx= x+ dx[j];
                    int ny = y+dy[j];
                    if( nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny] == oldcolor ){
                        image[nx][ny] =color;
                        q.push({nx,ny});
                    }
                }
            
           
        }
        return image;
    }
};