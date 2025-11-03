class Solution {
public:
    void reverseString(vector<char>& s) {
        //method 1
       // vector<char> k;
        int i=0;
        /*for(int j=0;j<s.size();j++){
            k.push_back(s[j]);
        }
        for(int j=s.size()-1;j>=0;j--){
          s[i]=k[j];
          i++;
        }*/

        //method 2
          char k;
          int middle=(s.size())/2;
        for(int j=s.size()-1;j>=middle;j--){
             k=s[j];
             s[j]=s[i];
             s[i]=k;
             i++;
        }
        
    }
};