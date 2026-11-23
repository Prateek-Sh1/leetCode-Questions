class ProductOfNumbers {
public:
    vector<int>st;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
        int n=st.size();
        int p=1;
        int i=1;
        while(k>0){
            p*=st[n-i];
            i++;
            k--;
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */