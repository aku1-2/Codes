class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    bool added=false;
                    for(int k=0;k<result.size();k++){
                        if(result[k]==nums1[i]) added=true;
                    }
                    if(!added)
                    result.push_back(nums1[i]);
                }
            }
        }
        return result;
    }
};