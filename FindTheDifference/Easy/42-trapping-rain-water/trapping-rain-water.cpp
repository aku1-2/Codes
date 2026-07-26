class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[i]>height[st.top()]){
                int middle= st.top();
                st.pop();
                if(st.empty())
                break;
                int left= st.top();
                int width = i-left-1;
                int h = min(height[i],height[left])- height[middle];
                ans += width * h;
            }
            st.push(i);
        }
        return ans;
    }
};