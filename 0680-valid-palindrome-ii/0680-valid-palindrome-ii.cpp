class Solution {
    bool check(string &s, int left, int right,bool deleted) {
        if(left>=right){
            return true;
        }
        if(s[left]!=s[right] && !deleted){
            deleted=true;
            return check(s,left+1,right,deleted)|| check(s,left,right-1,deleted);;
        }else if (s[left]!=s[right] && deleted){
            return false;
        }
        return check(s,left+1,right-1,deleted);
    
    }
    public:
    bool validPalindrome(string s) {
        bool deleted =false;
        int left=0;
        int right=s.size()-1;
        return check(s,left,right,deleted);
    }
};