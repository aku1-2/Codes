class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int left=0 , right=height.size()-1;
        int maxarea=0;
        while(left<right){
            area = (right-left) * min(height[left],height[right]);
            maxarea = max(maxarea,area);
            if(height[left]<height[right])
                left++;
                else
                right--;
        }
        return maxarea;
    }
};