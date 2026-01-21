class Solution {
    public int maximum69Number (int num) {
        if (num == 9999){
            return num;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(num);
        for (int i = 0; i < sb.length(); ++i) {
            // If we find the first '6', replace it with '9' and break the loop.
            if (sb.charAt(i) == '6') {
                sb.setCharAt(i, '9');
                break;
            }
        }
        return Integer.parseInt(sb.toString());
    }
}