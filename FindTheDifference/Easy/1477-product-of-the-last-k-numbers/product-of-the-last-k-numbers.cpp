class ProductOfNumbers {
public:
vector<int>v;
int n;
    ProductOfNumbers() {
        v.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            v={};
            n=0;
        }else{ 
        if(v.empty())
             v.push_back(num);
        else{
            v.push_back(v[n-1]*num);
        }
        n++;
        }
    }
    
    int getProduct(int k) {
        /*int prod=1;
        int n=v.size();
        for(int i=n-k;i<n;i++){
            prod *=v[i];
        }
        return prod;*/
        if(k>n) return 0;
        else if(k==n) return v[n-1];
        else{
            return v[n-1]/v[n-k-1];
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */