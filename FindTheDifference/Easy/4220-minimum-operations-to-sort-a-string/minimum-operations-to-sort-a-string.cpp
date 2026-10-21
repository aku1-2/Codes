class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string s1=s;
        bool sorted=true;
        sort(s.begin(),s.end());

        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                 sorted=false;
            }
        }
        if(sorted)
        return 0;
          if(n==2)
        return -1;
        if(s[0]==s1[0] || s[n-1]==s1[n-1]){
            return 1;
        }
        for(int i=1;i<n-1;i++){ 
        if(s1[i]==s[0] || s1[i]==s[n-1]){
            return 2;
          }
        }
          return 3;
        
    }
};