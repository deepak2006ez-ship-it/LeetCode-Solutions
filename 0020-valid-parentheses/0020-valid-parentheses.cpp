class Solution {
public:
    bool isValid(string s) {
        stack<char>str;
        int i=0;
        while(i<s.size()){
            if(s[i]=='(' ||s[i]=='[' || s[i]=='{'){
                str.push(s[i]);
            }else{
                if(str.empty()){
                    return false;
                }
                if(str.top()=='('&& s[i]==')'||
                str.top()=='[' && s[i]==']'||
                str.top()=='{' && s[i]=='}'){
                    str.pop();
                }else{
                    return false;
                }

            }
            i++;
        }
        if(str.size()>0){
            return false;
        }
        return true;
        
    }
};