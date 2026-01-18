class Solution {
    public int maxNumberOfBalloons(String text) {
        HashMap<Character, Integer> count = new HashMap<>();
        for (char letter : text.toCharArray()){
            count.put(letter, count.getOrDefault(letter,0)+1);
        }
        int res = count.getOrDefault('b', 0);
        res = Math.min(res, count.getOrDefault('a', 0));
        res = Math.min(res, count.getOrDefault('l', 0) / 2); // Need 2 'l's
        res = Math.min(res, count.getOrDefault('o', 0) / 2); // Need 2 'o's
        res = Math.min(res, count.getOrDefault('n', 0));
        return res;

    }
}