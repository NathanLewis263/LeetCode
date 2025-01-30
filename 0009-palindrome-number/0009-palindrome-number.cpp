class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        } else if (x < 10){
            return true;
        }
        
        long z=x;
        long y=0;
        while (x>0){
            long lastDigit = x % 10;
            x /= 10;
            y = y * 10;
            y+=lastDigit;
        }
        return z == y;
    }
};