import java.util.*;

class Vertex {
    int label;
    List<Map.Entry<Vertex, Integer>> neighbours;
    Vertex(int x) {
        label = x;
        neighbours = new ArrayList<>();
    }
}

public class Main {

    static Map<Vertex, Integer> dijkstra(Vertex s) {
        Map<Vertex, Integer> distances = new HashMap<>();
        distances.put(s, 0);

        Set<Vertex> set = new HashSet<>();

        do {
            Map.Entry<Vertex, Integer> vertex = null;
            for (Map.Entry<Vertex, Integer> e : distances.entrySet()) {
                if (set.contains(e.getKey()))
                    continue;
                if (vertex == null || e.getValue() < vertex.getValue())
                    vertex = e;
            }

            set.add(vertex.getKey());

            for (Map.Entry<Vertex, Integer> e : vertex.getKey().neighbours) {
                if (set.contains(e.getKey()))
                    continue;
                if (!distances.containsKey(e.getKey()) || vertex.getValue() + e.getValue() < distances.get(e.getKey()))
                    distances.put(e.getKey(), vertex.getValue() + e.getValue());
            }

        } while (set.size() < distances.size());

        return distances;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int S = scanner.nextInt();
        int T = scanner.nextInt();

        Map<Integer, Vertex> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            map.put(i + 1, new Vertex(i + 1));
        }

        for (int i = 0; i < M; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int w = scanner.nextInt();

            Vertex vertex0 = map.get(a);
            Vertex vertex1 = map.get(b);

            vertex0.neighbours.add(new AbstractMap.SimpleEntry<>(vertex1, w));
            vertex1.neighbours.add(new AbstractMap.SimpleEntry<>(vertex0, w));
        }

        System.out.println((dijkstra(map.get(S))).get(map.get(T)));
    }
}