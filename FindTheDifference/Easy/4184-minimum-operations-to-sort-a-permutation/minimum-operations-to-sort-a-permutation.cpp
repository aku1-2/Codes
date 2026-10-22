class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int start= find(nums.begin(),nums.end(),0)-nums.begin();
        bool a=true;
        bool d=true;
        for(int i=1;i<n;i++){
            int value=nums[(start+i)%n];
            if(value!=i){
                a=false;
            }
            if(value!=n-i){
                d=false;
            }
            if(!a && !d){
                return -1;
            }}
            if(a){
                return min(start,n-start+2);
            }
            return min(n-start,start+2);
        
    }
};