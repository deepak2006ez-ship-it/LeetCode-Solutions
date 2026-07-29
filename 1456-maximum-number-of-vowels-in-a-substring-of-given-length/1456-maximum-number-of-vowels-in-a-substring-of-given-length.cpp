class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int windowSum=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'||s[i]=='o'|| s[i]=='u'){
                windowSum++;
            }
        }
        ans=max(ans,windowSum);
        int left=0;
        int right=k-1;
        int n=s.size();
        int isLeftVowel=0;
        int isRightVowel=0;
        while(right<n-1){
            if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'){
                isLeftVowel=1;
            }
            if(s[right+1]=='a'||s[right+1]=='e'||s[right+1]=='i'||s[right+1]=='o'||s[right+1]=='u'){
                isRightVowel=1;
            }

            windowSum=windowSum-(isLeftVowel)+isRightVowel;
            ans=max(ans,windowSum);

            isLeftVowel=0;
            isRightVowel=0;
            left++;
            right++;

        }
        return ans;
        
    }
};