import java.util.Scanner;

publi class Main{
    public void main(){
        Scanner scanner = new Scanner(System.in):
        int number=1;

        for (int i=0:i<3;i++){
            number*=scanner.nextInt()
        }
        String numberStr = Integer.toString(number);
        int[] countDigits = new int[10];
        for (char digitChar : numberStr.toCharArray()) {
            int digit = Character.getNumericValue(digitChar);
            countDigits[digit]++;
        }

        for (int count : countDigits) {
            System.out.println(count);
        }

        scanner.close();
    }
}