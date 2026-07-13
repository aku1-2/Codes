class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    string s= "123456789";
    for(int i= to_string(low).size();i<=(int)to_string(high).size();i++){
        for(int j=0;j+i<=9;j++){
            int num= stoi(s.substr(j,i));
            if(num>=low && num<=high)
               ans.push_back(num);
        }
        }
        return ans;
    
    }
};