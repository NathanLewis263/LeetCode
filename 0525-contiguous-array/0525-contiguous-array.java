class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer, Integer> prefixMap = new HashMap<>();
        int prefixSum = 0;
        int ans = 0;
        prefixMap.put(0,-1); // store index cuz we need max len 
        for (int i = 0; i < nums.length; i++){
            prefixSum += nums[i] == 0 ? -1 : 1;
            if (prefixMap.containsKey(prefixSum)){
                int prevIndex = prefixMap.get(prefixSum);
                ans = Math.max(ans, i-prevIndex); // max length
            } else {
                // only put if its not in the map since we need earliest index to get max len
                prefixMap.put(prefixSum, i);
            }
        }
        return ans;
    }
}