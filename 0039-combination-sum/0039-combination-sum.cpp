class Solution {
public:
    void help(vector<int>& candidates, int target,int idx,int sum,vector<int>&curr,vector<vector<int>>&ans){
        int n=candidates.size();
        if(sum==target){
            ans.push_back(curr);
            return;
        }  
        if(idx==n||  sum>target ){
            return;
        }
        sum+=candidates[idx];
        curr.push_back(candidates[idx]);
        help(candidates,target,idx,sum,curr,ans);
        curr.pop_back();
        sum-=candidates[idx];
        help(candidates,target,idx+1,sum,curr,ans);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        help(candidates,target,0,0,curr,ans);
        return ans;

        
    }
};