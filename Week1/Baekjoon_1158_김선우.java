package packaged;
import java.util.*;

public class Main {
  public static void main(String args[]){
	  ArrayList<Integer> List = new ArrayList<Integer>();
	  int N, K;
	  Scanner sc = new Scanner(System.in);
	  N = sc.nextInt();
	  K =sc.nextInt();
	  int curIndex = 0;
	 
	  for(int i=1; i<=N; i++) {
		  List.add(i);
	  }
	  
	  System.out.print('<');
	  while(!List.isEmpty()) {
		  curIndex += K-1;
		  curIndex %= List.size();
		  System.out.print(List.get(curIndex));
		  List.remove(curIndex); 
		  if(!List.isEmpty())
			  System.out.print(", ");
	  }
	  System.out.print('>');
	  
  }
}
	
