class Solution {
    public int minStoneSum(int[] piles, int k) {
        int total = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int pile : piles){
            total += pile;
            maxHeap.add(pile);
        }

        while (k>0){
            int pile = maxHeap.remove();
            int remove = pile/2;
            total -= remove;
            maxHeap.add(pile-remove);
            k--;
        }

        return total;
    }
}