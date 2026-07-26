//refer notes 
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int,vector<long long>>mp;
        int n=arr.size();
        vector<long long>ans(n);
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        for(auto &it:mp){
            vector<long long>&idx=it.second;
            long long totalIndexSum=0;
            for(auto &val:idx){
                totalIndexSum+=val;
            }
            int leftCount=0;
            long long leftSumIndices=0;
            long long leftContri=0;
            int idxSize=idx.size();
            long long prefixSum=0;
            for(int i=0;i<idxSize;i++){
                prefixSum+=idx[i];
                long  long rightContri=(totalIndexSum-prefixSum)-idx[i]*(idxSize-1-i);
                leftContri=idx[i]*(leftCount)-leftSumIndices;
                long long totalContri=leftContri+rightContri;
                ans[idx[i]]=totalContri;
                leftSumIndices+=idx[i];
                leftCount++;
            }
                
            
           
        }
        return ans;
    }
};