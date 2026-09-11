class MinStack {
public:
    vector<int>stack1;
    vector<int>stack2ForMin;
    MinStack() {
        
    }
    
    void push(int value) {
        stack1.push_back(value);
        if(stack2ForMin.size()==0){
            stack2ForMin.push_back(value);
        }else{
            int val=min(stack2ForMin[stack2ForMin.size()-1],value);
            stack2ForMin.push_back(val);
        }

        
    }
    
    void pop() {
        stack1.pop_back();
        stack2ForMin.pop_back();
    }
    
    int top() {
        return stack1[stack1.size()-1]; 
    }
    
    int getMin() {
        return stack2ForMin[stack2ForMin.size()-1];
        
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