class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        int left=0;
        int highestFreq=0;
        int n=s.size();
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            highestFreq=max(highestFreq,mp[s[right]]);
            int windowSize=right-left+1;
            while(windowSize-highestFreq>k){
                mp[s[left]]--;
                left++;
                windowSize=right-left+1;

            }
            ans=max(ans,right-left+1);
            
        }
        return ans;
    }
};