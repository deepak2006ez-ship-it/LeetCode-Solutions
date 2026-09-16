class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        vector<int>ans;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        ans.push_back(pq.top());
        int st=0;
        int end=k-1;
        for(int i=end+1;i<nums.size();i++){
            mp[nums[st]]--;
            st++;
            end++;
            mp[nums[end]]++;
            pq.push(nums[end]);
            while(mp[pq.top()]==0){
                pq.pop();
            }
            
            ans.push_back(pq.top());
            
        }
        return ans;

    }
};