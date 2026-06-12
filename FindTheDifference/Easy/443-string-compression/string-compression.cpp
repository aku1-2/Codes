class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int t=0;
        while(i<chars.size()){
            char current = chars[i];
            int count=0;
            while(i<chars.size() && current== chars[i]){
                count++;
                i++;
            }
            chars[t++]= current;
            if(count > 1 ){
                string news = to_string(count);
                for(char c: news){
                    chars[t++]= c;
                }
            }
        }
        return t;
    }
};