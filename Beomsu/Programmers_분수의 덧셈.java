class Solution {
    public int[] solution(int numer1, int denom1, int numer2, int denom2) { 
        int commonDenom = denom1*denom2;
        int commonNumber = (numer1*denom2) + (numer2 * denom1);
        
        int gcd = gcd(commonDenom,commonNumber);
        
        int[] answer = {commonNumber/gcd,commonDenom/gcd};
        return answer;
    }
    public int gcd(int a,int b){
        while(b!=0){
            int temp = a%b;
            a=b;
            b=temp;
        }
        return a;
    }
}
