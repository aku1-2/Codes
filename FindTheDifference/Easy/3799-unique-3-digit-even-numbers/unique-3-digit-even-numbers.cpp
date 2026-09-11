class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       set<int>st;
        int count=0;
        for(int i=0;i<digits.size();i++){
           for(int j=0;j<digits.size();j++){
               for(int k=0;k<digits.size();k++){
                if(i!=j && j!=k && i!=k){
                       int num =digits[i]*100+digits[j]*10+digits[k]; 
                       if(num%2==0 && num/100!=0 )
                          st.insert(num);  
                  }
               }
           }
        }
        return st.size();
    }
};