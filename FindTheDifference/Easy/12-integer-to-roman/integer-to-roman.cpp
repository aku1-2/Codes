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

/*
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        while (num > 0) {
            if (num >= 1000) {
                roman += 'M';
                num -= 1000;
            } else if ((num / 100) % 5 == 4){
                roman += 'C';
                num += 100;
            } else if (num >= 500) {
                roman += 'D';
                num -= 500;
            } else if (num >= 100) {
                roman += 'C';
                num -= 100;
            } else if ((num / 10) % 5 == 4){
                roman += 'X';
                num += 10;
            } else if (num >= 50) {
                roman += 'L';
                num -= 50;
            } else if (num >= 10) {
                roman += 'X';
                num -= 10;
            } else if (num % 5 == 4){
                roman += 'I';
                num++;
            } else if (num >= 5) {
                roman += 'V';
                num -= 5;
            } else if (num >= 1) {
                roman += 'I';
                num--;
            }
        }
        
        return roman;
    }
};
*/