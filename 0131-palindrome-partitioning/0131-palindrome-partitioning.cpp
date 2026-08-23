class Solution {
public:
    bool isPalindrome(string &str){
        int st=0,end=str.size()-1;
        while(st<end){
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void help(string &s,vector<vector<string>>&ans,vector<string>&currVec,int start){
        int n=s.size();
        if(start==s.size()){
            ans.push_back(currVec);
            return;
        }
        string curr="";
        
        for(int i=start;i<s.size();i++){
            curr+=s[i];
            if(isPalindrome(curr)){
                currVec.push_back(curr);
                help(s,ans,currVec,i+1);
                currVec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>currVec;
        help(s,ans,currVec,0);
        return ans;

    }
};