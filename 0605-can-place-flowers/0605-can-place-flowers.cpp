class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if (n<1){
            return true;
        }
        for (int i = 0; i<flowerbed.size();i++){
            if (flowerbed[i]==0){
                if((i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1] == 0)){
                    flowerbed[i] = 1;
                    count++;
                    i++;
                    if (count==n){
                        return true;
                    }
                }
            }     
        }
        return false;
    }
};