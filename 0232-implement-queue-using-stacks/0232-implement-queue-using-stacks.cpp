class MyQueue {
public:
    list<int>l1;
    list<int>l2;
    MyQueue() {
        
    }
    
    void push(int x) {
        l1.push_back(x);
    }
    
    int pop() {
        int val;
        if(l2.empty()){

            while(!l1.empty() ){
                l2.push_back(l1.back());
                l1.pop_back();
            }
        }

        val=l2.back();
        l2.pop_back();
        
        return val;
        

        
    }
    
    int peek() {
        if(l2.empty()){
        while(!l1.empty()){
            l2.push_back(l1.back());
            l1.pop_back();
        }

        }
       
        
        return l2.back();
        
    }
    
    bool empty() {
        return l1.size()==0 && l2.size()==0;
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