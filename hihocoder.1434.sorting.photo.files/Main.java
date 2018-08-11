import java.util.*;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
        List<String> filenames = new ArrayList<>();

        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            filenames.add(in.nextLine());
        }

        filenames.stream().skip(1).sorted((filename1, filename2) -> {
            Pattern pattern = Pattern.compile("(\\D+)(\\d+)");
            Matcher matcher1 = pattern.matcher(filename1);
            matcher1.matches();
            Matcher matcher2 = pattern.matcher(filename2);
            matcher2.matches();

            String stringPart1 = matcher1.group(1);
            String stringPart2 = matcher2.group(1);
            if (stringPart1.compareTo(stringPart2) != 0)
                return stringPart1.compareTo(stringPart2);
            else {
                int numberPart1 = Integer.valueOf(matcher1.group(2));
                int numberPart2 = Integer.valueOf(matcher2.group(2));
                return numberPart1 - numberPart2;
            }
        }).forEach(System.out::println);
    }
}
