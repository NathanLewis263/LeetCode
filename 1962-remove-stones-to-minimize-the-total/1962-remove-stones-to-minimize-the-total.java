class Solution {
    public int minStoneSum(int[] piles, int k) {
        int total = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int pile : piles){
            total += pile;
            maxHeap.add(pile);
        }

        for (int i = 0;i<k;i++){
            int pile = maxHeap.remove();
            double remove = Math.floor((pile*1.0)/2);
            total -= remove;
            maxHeap.add((int)(pile-remove));
        }

        return total;
    }
}