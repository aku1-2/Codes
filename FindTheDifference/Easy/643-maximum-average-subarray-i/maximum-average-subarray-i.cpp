class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double avg=0.0;
        double sum=0.0;
    
       for(int i=0;i<k;i++){
           sum+= nums[i];
       }
       double maxavg=sum/k;
       for(int i=k;i<nums.size();i++){
        sum+= nums[i] - nums[i-k];
        avg = sum/k;
        maxavg=max(maxavg,avg);
       }
       return maxavg;
    }
};