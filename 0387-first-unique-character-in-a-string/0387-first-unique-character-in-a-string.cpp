class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        queue<char>q;
        for(int i=0;i<s.size();i++){
            q.push(s[i]);
            mp[s[i]]++;
        }
        int pos=0;
        while(!q.empty()){
            char ch=q.front();
            
            q.pop();
            if(mp[ch]==1){
                return pos;
            }
            pos++;
        }
        return -1;
        
        
    }
};