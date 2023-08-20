import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class JosephusProblem {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String[] input = reader.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int K = Integer.parseInt(input[1]);

            Queue<Integer> queue = new LinkedList<>();
            for (int i = 1; i <= N; i++) {
                queue.add(i);
            }

            String result = "<";
            while (queue.size() > 1) {
                for (int i = 0; i < K - 1; i++) {
                    queue.add(queue.poll());
                }
                result += queue.poll() + ", ";
            }

            result += queue.poll() + ">";
            System.out.println(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
