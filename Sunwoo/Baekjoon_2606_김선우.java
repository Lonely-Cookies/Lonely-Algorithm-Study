package packaged;

import java.util.*;

public class Main {
	static int VirusComputerNum = 0;
	
	public static void getVirusComputerNum(ArrayList<ArrayList<Integer>> graph, boolean[] checked, int virusComputer) {
		if(checked[virusComputer] == true)
			return;
		else {
			checked[virusComputer] = true;
			VirusComputerNum++;
		}
		
		for(int j=0; j<graph.get(virusComputer).size(); j++) {
			getVirusComputerNum(graph, checked, graph.get(virusComputer).get(j));
		}
	}
	
	public static void addEdge(ArrayList<ArrayList<Integer>> graph, int v1, int v2) {
		graph.get(v1).add(v2);
		graph.get(v2).add(v1);
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int vertex, edge;
		vertex = sc.nextInt();
		edge = sc.nextInt();
	
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
		boolean[] checked = new boolean[vertex+1];
		
		for(int i=0; i<=vertex; i++) {
			graph.add(new ArrayList<Integer>());
		}
		
		int v1,v2;
		for(int i=0; i<edge; i++) {
			v1 = sc.nextInt();
			v2 = sc.nextInt();
			addEdge(graph, v1, v2);
		}
		
		getVirusComputerNum(graph, checked, 1);
		VirusComputerNum-=1; //1번 컴퓨터는 제외
		System.out.print(VirusComputerNum);
	
	}
}
	
