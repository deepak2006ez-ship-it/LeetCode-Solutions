class Solution {
public:
//humlog wahi element stack mai keep jiska next greater lemenet not found else we pop thaT ELEMENT
    vector<int> nextGreaterElements(vector<int>& nums) {
       stack<int>s;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<2*nums.size();i++){
           
            while(!s.empty() && nums[i%n]>nums[s.top()]){
                ans[s.top()]=nums[i%n];
                s.pop();
            }
            s.push(i%n);

        }
        
        return ans;
    }
};