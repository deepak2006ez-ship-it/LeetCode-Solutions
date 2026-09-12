class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        
        int n=heights.size();
        vector<int>leftMin(n,-1);
        vector<int>rightMin(n,-1);
        stack<int>leftStackMin;
        stack<int>rightStackMin;
        for(int i=0;i<heights.size();i++){
            while(!rightStackMin.empty() && heights[i]<heights[rightStackMin.top()]){
                rightMin[rightStackMin.top()]=i;
                rightStackMin.pop();
            }
            rightStackMin.push(i);
        }
       for(int i=0;i<heights.size();i++){
            while(!leftStackMin.empty() && heights[leftStackMin.top()]>=heights[i]){
                leftStackMin.pop();
            }
            if(leftStackMin.empty()){
                leftMin[i]=-1;

            }else{
                leftMin[i]=leftStackMin.top();
            
            }
            leftStackMin.push(i);
        }

        for(int i=0;i<heights.size();i++){
            int currArea=1;
            int length=heights[i];
            int leftIdx,rightIdx=0;
            if(leftMin[i]==-1){
                leftIdx=i+1;
            }else{
                leftIdx=i-leftMin[i];
            }
            if(rightMin[i]==-1){
                rightIdx=heights.size()-(i+1);

            }else{
                rightIdx=rightMin[i]-(i+1);
            }
            int breadth=leftIdx+rightIdx;
            maxArea=max(maxArea,length*breadth);
        }
        return maxArea;
        
        
    }
};