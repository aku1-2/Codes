class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a, int b){
            int bits_a = count_bits(a);
            int bits_b = count_bits(b);
            if(bits_a == bits_b)
            return a<b;
            return bits_a < bits_b;
        });
        return arr;
    }

    int count_bits(int num){
        int count=0;
        while(num>0){
            if((num & 1) ==1)
            count++;
            num =num>>1;
        }
        return count;
    }
};