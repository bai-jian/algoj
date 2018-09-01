import java.util.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            System.out.println(Pattern.compile("marshtomp", Pattern.CASE_INSENSITIVE).matcher(in.nextLine()).replaceAll("fjxmlhx"));
        }
    }
}
