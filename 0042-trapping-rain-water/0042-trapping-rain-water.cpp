class Solution {
public:
//tc:0(n)
//sc:0(n)
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0;
        int rightMax=0;
        int left=0;
        int right=n-1;
        int area=0;
        while(left<right){
            leftMax=max(height[left],leftMax);
            rightMax=max(height[right],rightMax);
            if(leftMax<rightMax){
                area+=leftMax-height[left];
                left++;
            }else{
                area+=rightMax-height[right];
                right--;
            }

        }
        return area;
        
    }
};