class MyStack {
public:
    list<int>l1;
    int currSize=0;
    MyStack() {
        
    }
    
    void push(int x) {
        l1.push_back(x);
        currSize++;
    }
    
    int pop() {
        while(currSize!=1){
            l1.push_back(l1.front());
            l1.pop_front();
            currSize--;

        }
        int val=l1.front();
        l1.pop_front();
        currSize=l1.size();
        return val;

        
    }
    
    int top() {
        while(currSize!=1){
            l1.push_back(l1.front());
            l1.pop_front();
            currSize--;

        }
        int val=l1.front();
        l1.push_back(val);
        l1.pop_front();
        currSize=l1.size();
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