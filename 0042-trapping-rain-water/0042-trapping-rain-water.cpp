class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()){
            return 0;
        }
        int trapped = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        while (left <= right){
            if (leftMax < rightMax){
                leftMax = max(leftMax,height[left]);
                trapped += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax,height[right]);
                trapped += rightMax - height[right];
                right--;
            }
        }
        return trapped;
    
    }
};