class Solution {
public:
    bool isPalindrome(string s) {
        string n="";
          for(int i=0;i<s.size();i++){
            //if the character is alphabet and numeric value then add it to string n ....dont add  spaces.
            if(isalnum(s[i]))
                n+=tolower(s[i]);
          }
          int i=0,j=n.size()-1;
          //checking for palindrome.
          while(i<j){
            if(n[i]!=n[j])
            return false;
            i++;
            j--;
          }
          return true;
    }
};