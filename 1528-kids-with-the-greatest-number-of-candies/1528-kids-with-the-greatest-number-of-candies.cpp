class Solution {
public:
    int maxOfArray(vector<int>& candies){
        int maxi=candies[0];
        for(int i=1;i<candies.size();i++){
            maxi = max(maxi,candies[i]);
        }
        return maxi;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = maxOfArray(candies);
        vector<bool> kidsWithCandies(candies.size(),false);
        for (int i = 0;i<candies.size();i++){
            if (candies.at(i)>=(maxCandy-extraCandies)){
                kidsWithCandies.at(i) = true;
            }
        }
        return kidsWithCandies;
    }
};