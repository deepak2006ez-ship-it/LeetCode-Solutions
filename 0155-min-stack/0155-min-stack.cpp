class MinStack {
public:
    stack<long long>s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minVal=value;
        }
        else if(value>=minVal){
            s.push(value);
        }else{
            long long val=2LL*value-minVal;//these we are doing so that when popping val from stack we can keep track of prev min value (minVal=2*value-val) val here while popping value will be curr min minVa
            s.push(val);
            minVal=value;
            //val`=2(value)-minVal(these help to store both curr value and prev min,val` will be stored in stack(here val`==val))
        }
        
    }
    
    void pop() {
        if(s.top()>=minVal){
            s.pop();
        }else{
            minVal=2*minVal-s.top();
            s.pop();
            
        }
        
    }
    
    int top() {
        if(s.top()>=minVal){
            return s.top();
        }else{
            return minVal;
            
        }

        
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */