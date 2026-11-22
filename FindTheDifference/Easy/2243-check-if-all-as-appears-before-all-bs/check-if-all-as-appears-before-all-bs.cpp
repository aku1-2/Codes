class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        if(n==1){
            return true;
        }
        int index=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                index=i;
                continue;
            }
            else{
                index=i;
                break;
            }
        }
        if(index<n-1){ 
        for(int i=index;i<n;i++){
            if(s[i]=='a')
              return false;
         }
        }
        return true;
    }
};