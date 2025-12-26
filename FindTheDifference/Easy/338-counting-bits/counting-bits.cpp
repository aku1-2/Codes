class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        
        for(int i=0;i<=n;i++){
            result.push_back(CountSet(i));
        }
        return result;
    }

    int CountSet(int num){
       
        int count=0;
        while(num>0){
            count+= num&1;
            num=num>>1;
        }
        return count;
    }

};