class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int arrPoint1 = 0;
        int arrPoint2 = 0;
        while (arrPoint1 < nums1.size() && arrPoint2 < nums2.size()){
            if (nums1[arrPoint1] < nums2[arrPoint2]){
                arrPoint1++;
            } else if (nums1[arrPoint1] > nums2[arrPoint2]){
                arrPoint2++;
            } else {
                return nums1[arrPoint1];
            }
        }
        return -1;
    }
};