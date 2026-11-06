class Solution {
public:
// O(q+2m)- O(q+m)
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int size= logs.size();
        sort(logs.begin(),logs.end(), [](vector<int> &a, vector<int>& b){
            return a[1]<b[1];
        });
        int q= queries.size();
        vector<int>result(q);
        vector<pair<int,int>>timeIndex(q);
        for(int i=0;i<q;i++){
            timeIndex[i]={queries[i],i};
        }
        sort(timeIndex.begin(),timeIndex.end());
        unordered_map<int,int>mp;
        int i=0,j=0;
        for(auto [time,idx]: timeIndex){
            int start=time-x;
            int end=time;

            while(j<size && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<size && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            result[idx]= n-mp.size();
        }
        return result;
    }
};