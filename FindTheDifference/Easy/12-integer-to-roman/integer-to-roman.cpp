class Solution {
public:
    string intToRoman(int num) {
        string sum="";
        vector<pair<int, string>> roman={ 
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        for( auto &a: roman){
            while(num>= a.first){ 
            sum += a.second;
            num -= a.first;
        }
       }
        return sum;
    }
};