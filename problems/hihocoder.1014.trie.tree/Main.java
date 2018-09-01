import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Map<String, Integer> dictionary = new HashMap<>();

        int N = in.nextInt();
        for (int i = 0; i < N; i++) {
            String word = in.next();
            for (int j = 0; j < word.length(); j++) {
                String prefix = word.substring(0, j + 1);
                dictionary.put(prefix, dictionary.getOrDefault(prefix, 0) + 1);
            }
        }

        int M = in.nextInt();
        for (int i = 0; i < M; i++) {
            String prefix = in.next();
            System.out.println(dictionary.getOrDefault(prefix, 0));
        }
    }
}
