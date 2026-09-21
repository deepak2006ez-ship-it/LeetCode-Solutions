class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasInStation=0,totalGasRequired=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            totalGasInStation+=gas[i];
            totalGasRequired+=cost[i];
        }
        if(totalGasInStation<totalGasRequired){
            return -1;
        }
        int ans=0;
        int currGas=0;
        for(int i=0;i<n;i++){
            currGas+=gas[i]-cost[i];
            if(currGas<0){
                currGas=0;
                ans=i+1;
            }
        }
        return ans;
    }
};