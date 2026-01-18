class Solution {
    public int maximumSum(int[] nums) {
        Map<Integer, List<Integer>> dic = new HashMap<>();
        for (int num: nums) {
            int digitSum = getDigitSum(num);
            if (!dic.containsKey(digitSum)) {
                dic.put(digitSum, new ArrayList<>());
            }
            
            dic.get(digitSum).add(num);
        }
        
        int ans = -1;
        for (int key: dic.keySet()) {
            List<Integer> curr = dic.get(key);
            if (curr.size() > 1) {
                Collections.sort(curr, (d1,d2)->{
                    return d1==d2 ? 0 : d1 > d2 ? -1 : 1;
                });
                ans = Math.max(ans, curr.get(0) + curr.get(1));
            }
        }
        
        return ans;
        
    }
    
    public int getDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        
        return digitSum;
    }
}