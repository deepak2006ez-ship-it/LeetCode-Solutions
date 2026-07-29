class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int blackWindow=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B'){
                blackWindow++;
            }
        }
        ans=min(ans,k-blackWindow);
        int n=blocks.size();
        int left=0;
        int right=k-1;
        

        int plus,minus=0;
        while(right<n-1){
            if(blocks[left]=='B'){
                minus=1;
            }
            if(blocks[right+1]=='B'){
                plus=1;
            }

            blackWindow=blackWindow-(minus)+(plus);


            ans=min(ans,k-blackWindow);
            left++;
            right++;
            minus=0;
            plus=0;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
        
    }
};