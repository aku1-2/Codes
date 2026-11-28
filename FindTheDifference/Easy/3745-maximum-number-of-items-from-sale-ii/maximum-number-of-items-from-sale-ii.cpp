class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items,int budget) {
        int n=items.size();
        vector<int>freq(n+1,0);

        for(auto &item:items){
            freq[item[0]]++;
        }

        vector<int>cnt(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                cnt[i]+=freq[j];
            }
        }

        sort(items.begin(),items.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });

        int minPrice=items[0][1];
        long long ans=0;
        long long rem=budget;

        for(auto &item:items){
            int factor=item[0];
            int price=item[1];

            if(price>2LL*minPrice){
                break;
            }

            int bonus=cnt[factor]-1;

            if(bonus==0)continue;

            long long take=min((long long)bonus,rem/price);

            ans+=2*take;
            rem-=take*price;
        }

        ans+=rem/minPrice;

        return (int)ans;
    }
};