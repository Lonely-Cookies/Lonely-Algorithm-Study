package packaged;
import java.util.*;

public class Main {
  public static void main(String args[]){
	  Scanner sc = new Scanner(System.in);
	  String N = sc.next();
	  int[] arr = new int[11];
	  
	  for(int i=0; i<11; i++) {
		  arr[i] = 0;
	  }
	  
	  for(int i=0; i< N.length(); i++) {
		  arr[N.charAt(i)-'0'] ++;
	  }

	  arr[10] = (int) Math.ceil(((double)arr[6] + arr[9])/2);
	  arr[6] = 1;
	  arr[9] = 1;
	  
	  if(arr[6]>0)
		  arr[6] = 1;
	  if(arr[9]>0)
		  arr[9] = 1;
	  
	  int max = 0;
	  for(int i=0; i<11;i++) {
		  if(max < arr[i])
			  max = arr[i];
	  }
	  System.out.print(max);
  }
}
	
