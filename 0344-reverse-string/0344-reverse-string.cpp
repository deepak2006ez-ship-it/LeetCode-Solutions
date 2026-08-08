class Solution {
public:
    void reverseString(vector<char>& s,int left,int right){
        if(left>=right){
            return;
        }
        swap(s[left],s[right]);
        reverseString(s,left+1,right-1);
    }
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        reverseString(s,left,right);
    }
};