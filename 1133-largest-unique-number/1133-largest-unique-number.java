class Solution {
    public int largestUniqueNumber(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int ans = -1;
        for (int i : nums){
            freq.put(i, freq.getOrDefault(i, 0)+1);
        }
       
        for (int i : freq.keySet()){
            if (freq.get(i) == 1){
                ans = Math.max(ans, i);
            } 
        }
        return ans;
    }
}