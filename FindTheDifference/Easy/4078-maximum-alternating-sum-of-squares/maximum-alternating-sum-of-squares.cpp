class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        //swap even lower value to odd upper value
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        /*for(int i=0;i<n;i++){ 
        for(int i=0;i<n-1;i++){
            if(i%2==0 &&  nums[i]<nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
            if(i%2==1 && nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
    }*/
    sort(nums.begin(),nums.end());
       int mid=n/2;
        long long score=0;
        for(int i=0;i<mid;i++){
           score-= nums[i];
            }
        for(int i=mid;i<n;i++){
           score+= nums[i];
            }

        
        return score;
    }
};