class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int result;
        while (l <= r) {
            int mid = l + (r-l) / 2;
            long long hours = 0;
            
            for (int pile : piles) {
                hours += ceil(1.0*pile/mid);
            }
            
            if (hours <= h) {
                result = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
    }
};
