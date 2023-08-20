import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))){
			int t = Integer.parseInt(reader.readLine());
			int[] input = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			int h = input[0];
			int m = input[1];
			for (int i =0; i<t;i++){
				m+=Integer.parseInt(reader.readLine());
			}
			solution(h,m);
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	
	static void solution(int h, int m) {
		h += m / 60;
		m = m % 60;
		h = h % 24; // 시간이 24를 넘어가면 0부터 다시 시작
		System.out.println(h + " " + m); // 시간과 분을 공백으로 구분하여 출력
	}
}