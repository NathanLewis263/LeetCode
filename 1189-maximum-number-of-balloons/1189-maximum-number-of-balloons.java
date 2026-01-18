class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] counts = new int[5];
        for (char letter : text.toCharArray()){
            if (letter == 'b'){
                counts[0]++;
            } else if (letter == 'a') {
                counts[1]++;
            } else if (letter == 'l') {
                counts[2]++;
            } else if (letter == 'o') {
                counts[3]++; 
            } else if (letter == 'n') {
                counts[4]++;
            }
        }
        int ans = counts[0];
        ans = Math.min(ans, counts[1]);
        ans = Math.min(ans, counts[2]/2);
        ans = Math.min(ans, counts[3]/2);
        ans = Math.min(ans, counts[4]);
        return ans;

    }
}