class MyStack {
public:
    list<int>l1;
    list<int>l2;
    MyStack() {
        
    }
    
    void push(int x) {
        l1.push_back(x);
    }
    
    int pop() {
        while(l1.size()!=1){
            l2.push_back(l1.front());
            l1.pop_front();
        }
        int val=l1.front();
        l1.pop_front();
        while(!l2.empty()){
            l1.push_back(l2.front());
            l2.pop_front();

        }
        return val;

        
    }
    
    int top() {
        while(l1.size()!=1){
            l2.push_back(l1.front());
            l1.pop_front();
        }
        int val=l1.front();
        l2.push_back(l1.front());
        l1.pop_front();
        
        while(!l2.empty()){
            l1.push_back(l2.front());
            l2.pop_front();

        }
        return val;
        
    }
    
    bool empty() {
        return l1.size()==0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */