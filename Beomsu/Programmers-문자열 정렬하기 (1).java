import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(String my_string) {
        ArrayList<Integer> numbers = new ArrayList();
        
        // 숫자를 찾아 리스트에 추가
        for (char ch : my_string.toCharArray()) {
            if (Character.isDigit(ch)) {
                numbers.add(Character.getNumericValue(ch));
            }
        }
        
        // 리스트를 오름차순으로 정렬
        Collections.sort(numbers);

        // 정렬된 리스트를 배열로 변환
        int[] answer = new int[numbers.size()];
        for (int i = 0; i < numbers.size(); i++) {
            answer[i] = numbers.get(i);
        }

        return answer;
    }
}
