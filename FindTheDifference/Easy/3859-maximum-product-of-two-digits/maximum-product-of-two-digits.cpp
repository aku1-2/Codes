class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n>0){
            int d=n%10;
            arr.push_back(d);
            n /=10;
        }
        int prod=1;
        int maxprod=0;
        int left=0,right=arr.size()-1;
        while(left<right){
            prod = arr[left]*arr[right];
            if(arr[left]<arr[right])
               left++;
            else
                right--;
            maxprod = max(maxprod,prod);
        }
        return maxprod;
    }
};