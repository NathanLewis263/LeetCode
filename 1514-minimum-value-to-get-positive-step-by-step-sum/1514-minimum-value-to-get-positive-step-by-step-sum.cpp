class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix.at(0) = nums.at(0);
        for (int i = 1;i<n;i++){
            prefix.at(i) = prefix.at(i-1) + nums.at(i);
            cout << prefix.at(i) << " ";
        }
        int minVal = *min_element(prefix.begin(),prefix.end());
        return minVal < 0 ? abs(minVal)+1 : 1;
    }
};