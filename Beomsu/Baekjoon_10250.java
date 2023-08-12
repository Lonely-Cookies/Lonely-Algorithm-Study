import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int[] results = new int[t];

        for (int i = 0; i < t; i++) {
            int H = scanner.nextInt();
            int W = scanner.nextInt();
            int N = scanner.nextInt();

            int floor = N % H == 0 ? H : N % H;
            int side = N % H == 0 ? N / H : N / H + 1;

            String sideText = side < 10 ? "0" + side : Integer.toString(side);

            results[i] = Integer.parseInt(floor + sideText);
        }

        for (int result : results) {
            System.out.println(result);
        }

        scanner.close();
    }
}
