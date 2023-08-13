package packaged;
import java.util.*;

public class Main {
  public static void main(String args[]){
	  Scanner sc = new Scanner(System.in);
	  HashMap<Character, ArrayList<Integer>> peopleSize = new HashMap();
	  int N = sc.nextInt();
	  
	  for(int i=0; i<N; i++) {
		  int weight = sc.nextInt();
		  int height = sc.nextInt();
		  ArrayList<Integer> overAll = new ArrayList();
		  overAll.add(weight);
		  overAll.add(height);
		  peopleSize.put((char) (i + 65), overAll);
	  }
	  
	  Set<Character> keys = peopleSize.keySet();
	  
	  for(Character key : keys) {
		  int ranking = 1;
		  for(Character key2 : keys) {
			  if(peopleSize.get(key) == peopleSize.get(key2)) {
				  continue;  
			  }
			  if(peopleSize.get(key).get(0) < peopleSize.get(key2).get(0) && peopleSize.get(key).get(1) < peopleSize.get(key2).get(1)) {
				  ranking ++;
			  } 
		  }
		  peopleSize.get(key).add(ranking);
	  }
	  
	  peopleSize.forEach((key, value) -> {
		  System.out.print(value.get(2)+" ");
	  });
	  
  }
}
	
