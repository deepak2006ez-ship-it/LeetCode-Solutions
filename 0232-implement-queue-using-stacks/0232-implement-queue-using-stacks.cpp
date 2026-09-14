class MyQueue {
public:
    list<int>l1;//storing actual elemnt sequence
    list<int>l2;//storing reverse order so that deletion happen from start
    MyQueue() {
        
    }
    
    void push(int x) {
        l1.push_back(x); 
    }
    
    int pop() {
        while(l1.size()!=1){
            l2.push_back(l1.back());
            l1.pop_back();
        }
        int val=l1.back();
        l1.pop_back();
        while(!l2.empty()){
            l1.push_back(l2.back());
            l2.pop_back();
        }
        return val;
    }
    
    int peek() {
        while(l1.size()!=1){
            l2.push_back(l1.back());
            l1.pop_back();
        }
        int val=l1.back();
        
        while(!l2.empty()){
            l1.push_back(l2.back());
            l2.pop_back();
        }
        return val;

        
    }
    
    bool empty() {
        return l1.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */