class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int ans=0;
       vector<int> diff(n);
       for(int i=0;i<n;i++){
        diff[i]=capacity[i]-rocks[i];
       } 
       sort(diff.begin(),diff.end());
       for(int i=0;i<n;i++){
        if(diff[i]==0){
            ans++;
        }
        else{
            if(additionalRocks>=diff[i]){
                additionalRocks-=diff[i];
                ans++;
            }
            else{
                break;
            }
        }
       }
       return ans;
    }
};