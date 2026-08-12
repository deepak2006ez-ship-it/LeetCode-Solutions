class Solution {
public:
    void helper(vector<int>& nums,int idx,vector<int>&subset ,vector<vector<int>>&ans){
        if(idx==nums.size()){
            ans.push_back({subset});
            return;
        }
        subset.push_back(nums[idx]);
        helper(nums,idx+1,subset,ans);
        subset.pop_back();
        helper(nums,idx+1,subset,ans);



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        helper(nums,0,subset,ans);
        return ans;

    }
};