class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int> result(n);
        int i=0;
        int j=n-1;
        int pos=n-1;
        while(i<=j){
            int leftsq = nums[i]*nums[i];
            int rightsq = nums[j]*nums[j];
            if(leftsq > rightsq){
                result[pos--]=leftsq;
                i++;
            }else{
                result[pos--]=rightsq;
                j--;
            }
        }
        return result;
        /*vector<int> v;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        return v;*/
    }
};