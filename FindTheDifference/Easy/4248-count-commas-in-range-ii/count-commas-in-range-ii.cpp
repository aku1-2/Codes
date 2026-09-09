class Solution { 
    public: long long countCommas(long long n) { 
        long long ans=0; 
        long long num=n, digits=0;
         while(num!=0){ 
            num/=10;
             digits++; 
            } 
            num=n;
            if(n<=999)
             return 0; 
            int comma=0; 
            if(digits%3==0) 
            comma=digits/3-1; 
            else 
            comma=digits/3; 
            while(num>999){ 
                long long c=1;
                for(int i=1;i<digits;i++)
                    c*=10;
                ans += (num - c+1)*comma; 
                num= c-1;
                 digits--; 
                 if(digits%3==0)
                   comma--; 
        } 
        return ans; 
        }
    };