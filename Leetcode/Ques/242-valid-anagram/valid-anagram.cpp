class Solution {
public:
    bool isAnagram(string s, string t) {
       /*vector<char> c1(s.begin(),s.end());
       vector<char> c2(t.begin(),t.end());
       if(s.length()!=t.length())
       return false;
       
       sort(c1.begin(),c1.end());
       sort(c2.begin(),c2.end());
       if(c1==c2)
       return true;
       return false;*/
       //without using vector 
       if(s.size()!=t.size())
       return false;
       sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       if(s==t)
       return true;
       return false;
    }
};