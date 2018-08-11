class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (set.add(n)) {
            int m = 0;
            while (n != 0) {
                m += (int)Math.pow(n % 10, 2);
                n /= 10;
            }
            n = m;
        }
        return n == 1;
    }
}