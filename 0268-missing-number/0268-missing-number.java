class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int i : nums){
            numberSet.add(i);
        }
        for (int i = 0; i<=nums.length;i++){
            if (!numberSet.contains(i)){
                return i;
            }
        }
        return -1;
        
    }
}