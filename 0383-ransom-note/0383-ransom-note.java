class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> freq = new HashMap<>();
        // Check for obvious fail case.
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        for (char letter : magazine.toCharArray()){
            freq.put(letter, freq.getOrDefault(letter,0)+1);
        }
        for (char letter : ransomNote.toCharArray()){
            if (freq.containsKey(letter)){
                freq.put(letter, freq.getOrDefault(letter,0)-1);
                if (freq.get(letter) == 0){
                    freq.remove(letter);
                }
            } else {
                return false;
            }
        }
        return true;
    }
}