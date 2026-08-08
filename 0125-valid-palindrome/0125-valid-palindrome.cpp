class Solution {
public:
    bool isValid(char ch){
        if(ch>='0' && ch<='9'){
            return true;
        }else if(tolower(ch)>='a' && tolower(ch)<='z'){
            return true;
        }
        
        
        return false;
        


    }
    bool helper(string &s,int left,int right){
        int n=s.size();
        if(left>=right){
            return true;
        }

      
        while(left<n && !isValid(s[left])){
            left++;
        }
        while(right>=0 && !isValid(s[right])){
            right--;
        }
        if(left>=right){
            return true;
        }

        
        if(tolower(s[left])!=tolower(s[right])){
            return false;
        }
        return helper(s,left+1,right-1);

        
    }
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        return helper(s,left,right);
        
    }
};