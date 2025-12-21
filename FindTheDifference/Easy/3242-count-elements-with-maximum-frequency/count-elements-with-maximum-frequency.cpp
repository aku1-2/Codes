class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
     unordered_map<int, int> freq;
     int result=0;
     int maxfreq=0;
     
     for(int i=0; i<nums.size();i++){
         int num=nums[i];
         freq[num]++;
         if (freq[num] > maxfreq)
             maxfreq = freq[num];
     }
     // Sum up all elements that have the maximum frequency
        for (auto i = freq.begin(); i!= freq.end(); i++) {
            if (i->second == maxfreq)
                result += i->second;
        }

        return result;
 }
};
