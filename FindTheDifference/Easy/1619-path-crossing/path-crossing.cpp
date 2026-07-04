class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> p;
        int x=0,y=0;
        p.insert({0,0});
        for(char c: path){
           if(c=='N') y++;
           else if(c=='S') y--;
           else if(c== 'E')x++;
           else x--;
           if(p.count({x,y}))
           return true;
           p.insert({x,y});

        }
        return false;
    }
};