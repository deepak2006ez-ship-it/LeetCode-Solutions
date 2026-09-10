class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n=nums2.size();
        unordered_map<int,int>mp;
        vector<int>ans(n,-1);
        for(int i=0;i<nums2.size();i++){
            if(!s.empty() && nums2[i]>nums2[s.top()]){
                while(!s.empty() &&nums2[i]>nums2[s.top()]){

                ans[s.top()]=nums2[i];
                s.pop();
                
                }
                s.push(i);
            }else{
                s.push(i);
            }
            mp[nums2[i]]=i;

        }
        vector<int>aans;

        for(int i=0;i<nums1.size();i++){
            aans.push_back(ans[mp[nums1[i]]]);
        }
        return aans;
    }
};