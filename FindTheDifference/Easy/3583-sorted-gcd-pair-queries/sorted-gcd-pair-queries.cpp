class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n= nums.size();
        int maxel = *max_element(begin(nums),end(nums));
        vector<int> freq(maxel+1,0);
        vector<int> ans;
       for(int i=0;i<n;i++){
        int num= nums[i];
        for(int j=1;j*j <= num;j++){
            if(num%j==0){
                freq[j]++;
                if(num/j!=j){
                    freq[num/j]++;
                }
            }
        }
       }
       vector<long long> pairswithGcd(maxel+1,0);
       for(int g = maxel; g>=1;g--){
        long long count = freq[g];
        //nC2
        pairswithGcd[g] = count*(count-1)/2;

        //correction time
        for(int mult = 2*g; mult <= maxel;mult+=g){
            pairswithGcd[g] -= pairswithGcd[mult];
        }
       }
       vector<long long> prefixCountGcd(maxel+1,0);
       for(int g=1;g<=maxel;g++){
        prefixCountGcd[g]= prefixCountGcd[g-1]+ pairswithGcd[g];
       }
       for(long long idx: queries){
        int l=1;
        int r= maxel;
        int temp = 1; 
        while(l<=r){
            int mid_gcd = l+ (r-l)/2;

            if(prefixCountGcd[mid_gcd]> idx){
                temp = mid_gcd;
                r=mid_gcd-1;

            }
            else{
                l = mid_gcd+1;
            }
        }
        ans.push_back(temp);
       }
        return ans;
    }
};