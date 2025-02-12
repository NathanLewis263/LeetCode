class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l = 1, r = piles[piles.size()-1];
        
        while (l < r) {
            int mid = (l + r) / 2;
            int hours = 0;
            
            for (int pile : piles) {
                hours += ceil((double)pile/mid);
            }
            
            if (hours <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};
