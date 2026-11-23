class ProductOfNumbers {
public:
    vector<int>st;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0) st.clear();
        else{
            st.push_back(num*((st.size()>0)?(st[st.size()-1]):1));
        }
    }
    
    int getProduct(int k) {
        int n=st.size();
        if(n-k<0)return 0;
        return st[n-1]/((n-k-1>=0)?st[n-k-1]:1);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */