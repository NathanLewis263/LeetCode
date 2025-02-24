class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(nums.at(0));
        for (int i = 1;i<nums.size();i++){
            prefix.push_back(nums.at(i)+prefix[i-1]);
        }
    }
    
    int sumRange(int left, int right) {

        return left==0 ? prefix[right] : prefix[right]-prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */