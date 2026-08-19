class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mp;
        for(auto &m:reservedSeats){
            mp[m[0]].insert(m[1]);
        }
        int ans= (n-mp.size())*2;
        for(auto &[row,col]:mp){
         bool left =true;
         bool right=true;
         bool middle=true;
         for(int i=2;i<=5;i++){
            if(col.count(i))
            left =false;

         }
         for(int i=4;i<=7;i++){
            if(col.count(i))
            middle =false;

         }
         for(int i=6;i<=9;i++){
            if(col.count(i))
            right =false;

         }
        
        if(left && right){
            ans+=2;
        }
        else if(left || right || middle)
        ans++;
        }
        return ans;
    }
};