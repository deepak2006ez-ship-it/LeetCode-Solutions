class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }
        vector<int>ans;
        //for traversing nums1 array
        for(auto val:nums1){
            bool run=false;
            for(int j=mp[val]+1;j<nums2.size();j++){
                if(nums2[j]>val){
                    ans.push_back(nums2[j]);
                    run =true;
                    break;
                }
            }
            if(!run){
                ans.push_back(-1);
            }
            
        }
        return ans;
        

    }
};