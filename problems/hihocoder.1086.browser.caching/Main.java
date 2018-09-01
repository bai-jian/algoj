import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int M = in.nextInt();
        in.nextLine();

        Set<String> cache = Collections.newSetFromMap(new LinkedHashMap<String, Boolean>(1024, 0.75f, true){
            @Override
            protected boolean removeEldestEntry(Map.Entry eldest) {
                return size() > M;
            }
        });

        while (in.hasNextLine()) {
            String url = in.nextLine();
            System.out.println(cache.contains(url) ? "Cache" : "Internet");
            cache.add(url);
        }
    }
}
