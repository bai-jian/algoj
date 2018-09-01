import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());

        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        for (int i = 0; i < N; i++) {
            String operation = in.next();
            if (operation.equals("A"))
                heap.offer(in.nextInt());
            else
                System.out.println(heap.poll());
        }
    }
}
