class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost=0;
        int totalGas=0;
        int start=-1;

        for(int i=0;i<gas.size();i++){
            totalCost+=cost[i];
            totalGas+=gas[i];
        }
        if(totalCost>totalGas){
            return start;
        }
        start=0;
        int currGas=0;
        for(int i=0;i<gas.size();i++){
            currGas+=gas[i]-cost[i];
            if(currGas<0){
                start=i+1;
                currGas=0;
            }
        }
        return start;
    }
};