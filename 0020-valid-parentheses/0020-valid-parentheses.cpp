class Solution {
public:
    bool isValid(string s) {
        stack<char>str;
        for(auto &val:s){
            if(val==']' ||val==')'||val=='}'){
                if(str.empty()){
                    return false;
                }else{
                    if(val==']' && str.top()=='['||
                    val=='}' && str.top()=='{'||
                    val==')' && str.top()=='('){
                        str.pop();
                    }else{
                        return false;
                    }
                }

            }else{
                str.push(val);
            }

        }
        return str.size()==0;
        
    }
};