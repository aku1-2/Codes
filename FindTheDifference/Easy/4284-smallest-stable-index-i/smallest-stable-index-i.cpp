class Solution {
public:
   
    int firstStableIndex(vector<int>& nums, int k) {
         
      if(k==0 && nums.size()==1){
        return 0;
      }
      
      for(int i=0;i<nums.size();i++){
         int minE= INT_MAX, maxE=INT_MIN; 
        for(int j=0;j<=i;j++){
            maxE=max(maxE,nums[j]);
            }
            for(int l=i;l<nums.size();l++){
                minE = min(minE, nums[l]);
            }
            if((maxE - minE) <=k){ 
                      return i;
                     
            }
        
      }
      return -1;

    }
};