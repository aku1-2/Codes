class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
       /* deque<int> d;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            while(!d.empty() && d.front()<= i -k)
                d.pop_front();
            while(!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();

            d.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[d.front()]);
        }

        return ans;*/
     int n=nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i%k==0){
                left[i]=nums[i];
            }
            else
            left[i]=max(nums[i],left[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1||(i+1)%k==0)
            right[i]=nums[i];
            else
            right[i]=max(right[i+1],nums[i]);
        }

        for(int i=0;i<=n-k;i++){
            ans.push_back(max(right[i],left[i+k-1]));
        }
        return ans;


    }
};