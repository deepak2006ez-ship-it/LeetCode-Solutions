class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int leftMax=0;
        int rightMax=0;
        int area=0;
        while(l<r){
            leftMax=max(leftMax,height[l]);
            rightMax=max(rightMax,height[r]);
            if(leftMax<=rightMax){
                area+=leftMax-height[l];
                l++;
            }else{
                area+=rightMax-height[r];
                r--;
            }
        }
        return area;
    }
};