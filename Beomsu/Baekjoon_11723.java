import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입력을 빠르게 읽기 위한 BufferedReader
        StringBuilder sb = new StringBuilder(); // 출력을 빠르게 하기 위한 StringBuilder
        int S = 0; // 집합을 표현할 변수
        int M = Integer.parseInt(br.readLine()); // 연산의 개수
        StringTokenizer st; // 입력 분리를 위한 StringTokenizer
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine()); // 한 줄을 읽어 토큰으로 분리
            String str = st.nextToken(); // 연산 종류
            if(str.equals("all")) S = (1 << 21) - 1; // 모든 수 추가
            else if(str.equals("empty")) S = 0; // 집합 비우기
            else {
                int num = Integer.parseInt(st.nextToken()); // 수행할 숫자
                if(str.equals("add")) 
                    S |= (1 << num); // 숫자 추가
                else if(str.equals("remove"))
                    S &= ~(1 << num); // 숫자 제거
                else if(str.equals("check"))
                    sb.append((S & (1 << num)) != 0 ? 1 : 0).append("\n"); // 숫자 확인
                else if(str.equals("toggle"))
                    S ^= (1 << num); // 숫자 토글
            }
        }
        System.out.println(sb); // 결과 출력
    }
}