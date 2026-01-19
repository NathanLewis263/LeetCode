class Solution {
    public String makeGood(String s) {
        StringBuilder stack = new StringBuilder();
        for (char letter : s.toCharArray()){
             if (!stack.isEmpty() && differentCaseSameLetter(stack.charAt(stack.length()-1), letter))
                stack.deleteCharAt(stack.length()-1);
            else
                stack.append(letter);
        }
        return stack.toString();
    }

    private boolean differentCaseSameLetter(char a, char b){
        return Character.toLowerCase(a) == Character.toLowerCase(b) && a != b;
    }
}