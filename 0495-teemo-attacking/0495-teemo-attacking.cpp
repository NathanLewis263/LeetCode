class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (int i = 0;i<timeSeries.size();i++){
            if (i == 0){
                total+=duration;
            } else {
                if (timeSeries[i-1]+duration>timeSeries[i]){
                    total+=timeSeries[i]-timeSeries[i-1];
                } else {
                    total += duration;
                }   
            }
        }
            return total;
    }
};