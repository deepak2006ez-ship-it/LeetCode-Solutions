class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        queue<pair<char,int>>q;
        for(int i=0;i<s.size();i++){
            q.push({s[i],i});
            mp[s[i]]++;
        }
       
        while(!q.empty()){
            char ch=q.front().first;
            int pos=q.front().second;
            q.pop();
            if(mp[ch]==1){
                return pos;
            }
        }
        return -1;
        
    }
};