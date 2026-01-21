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
            int remove = pile/2;
            total -= remove;
            maxHeap.add(pile-remove);
        }

        return total;
    }
}