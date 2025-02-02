class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAr = 0;
        int left = 0;
        int right = height.size()-1;

        while (left < right){
            int width = right - left;
            maxAr = max(maxAr, min(height[left], height[right]) * width);

            if (height[left]<=height[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxAr;
    }
};