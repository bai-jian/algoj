/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int i = 1, j = n;
        while (i != j) {
            int k = (int)(((long)i + j) / 2);
            if (isBadVersion(k))
                j = k;
            else
                i = k + 1;
        }
        return i;
    }
}