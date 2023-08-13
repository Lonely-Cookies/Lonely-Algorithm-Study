import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over

        for (int t = 0; t < testCases; t++) {
            String quizResult = scanner.nextLine();
            int score = 0;
            int consecutiveOs = 0;

            for (char c : quizResult.toCharArray()) {
                if (c == 'O') {
                    consecutiveOs++;
                    score += consecutiveOs;
                } else {
                    consecutiveOs = 0;
                }
            }

            System.out.println(score);
        }

        scanner.close();
    }
}
