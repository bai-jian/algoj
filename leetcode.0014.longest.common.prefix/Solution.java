import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0)
            return "";

        String shortestString = Collections.min(Arrays.asList(strs), Comparator.comparingInt(String::length));
        for (int i = 0; i < shortestString.length(); i++)
            for (String str: strs)
                if (shortestString.charAt(i) != str.charAt(i))
                    return shortestString.substring(0, i);
        return shortestString;
    }
}
