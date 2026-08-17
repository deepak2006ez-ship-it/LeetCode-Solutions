class Solution {
public:
    void getPermute(vector<int>& nums,int idx,vector<vector<int>>ans){
        if(idx==nums.size()){
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            getPermute(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;

        
    }
};