class Solution {
public:
    void dfs(int curr, int n, vector<int> &arr){
       
        if(curr>n)return;
        arr.push_back(curr);
        for(int i=0;i<=9;i++){
         int next= curr*10+i;
        if(next>n)return;
        dfs(next, n , arr);}
    }
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        for(int i=1;i<=9;i++){
            dfs(i,n,arr);
        }
        return arr;
    }
};