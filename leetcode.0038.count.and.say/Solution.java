class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder("1");
        for (int i = 2; i <= n; i++) {
            String str = sb.toString();
            sb.setLength(0);

            char last = str.charAt(0);
            int count = 1;
            for (int j = 1; j < str.length(); j++) {
                if (str.charAt(j) == last) {
                    ++count;
                } else {
                    sb.append(count).append(last);
                    count = 1;
                }
                last = str.charAt(j);
            }
            sb.append(count).append(last);
        }
        return sb.toString();
    }
}
