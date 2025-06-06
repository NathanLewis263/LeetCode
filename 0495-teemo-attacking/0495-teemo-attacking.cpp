class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration;
        for (int i = 1;i<timeSeries.size();i++){
            if (timeSeries[i-1]+duration>timeSeries[i]){
                total+=timeSeries[i]-timeSeries[i-1];
            } else {
                total += duration;
            }   
        }
            return total;
    }
};