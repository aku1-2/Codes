class Solution {
public:
vector<vector<int>>pt;
long long m=1e9+7;
   int solve(vector<int>& nums){ 
    
    int n=nums.size();
    if(n<3)
    return 1;
    vector<int>left;
    vector<int>right;
    long long x;
    int root=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]<root){
            left.push_back(nums[i]);
        }
        else{
            right.push_back(nums[i]);
        }
    }
    long long l=solve(left)%m;
    long long r=solve(right)%m;
    x= pt[n-1][left.size()];
   return (((l*r)%m)*x)%m;

   }

    int numOfWays(vector<int>& nums) {
        int n= nums.size();
        pt.resize(n+1);
      
        for(int i=0;i<=n;i++){
            pt[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%m;
            }

        }
        return (solve(nums)-1)%m;
    }
};