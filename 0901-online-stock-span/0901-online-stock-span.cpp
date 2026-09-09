class StockSpanner {
public:
    stack<pair<int,int>>s;
    int day=0;
    StockSpanner() {   
    }
    int next(int price) {
        while(s.size()>0 && s.top().first<=price){
            s.pop();
        }
        int ans;
        if(s.size()==0){
            ans=day+1;
        }else{
            ans=day-s.top().second;
        }
        s.push({price,day});
        day++;
        return ans;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */