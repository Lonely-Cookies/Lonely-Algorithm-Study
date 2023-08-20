package packaged;

import java.util.*;

public class Main {
	static int vertex;
	static int houseNum = 0;
	static int eachHouseNumber = 0;
	static ArrayList<Integer> eachHouseNumberArrayList = new ArrayList<Integer>();
	
	public static void dfs(int[][] graph, boolean[][] checked, int currentX, int currentY) {
		if(currentX<1 || vertex < currentX)
			return;
		if(currentY<1 || vertex < currentY)
			return;
		
		if(checked[currentX][currentY] == true)
			return;
		else if(graph[currentX][currentY] == 0){
			checked[currentX][currentY] = true;
			return;
		}
		else {
			checked[currentX][currentY] = true;
			eachHouseNumber++;
			dfs(graph, checked, currentX-1, currentY);
			dfs(graph, checked, currentX, currentY-1);
			dfs(graph, checked, currentX+1, currentY);
			dfs(graph, checked, currentX, currentY+1);
		}
	}
	
	public static void getHouseNum(int[][] graph, boolean[][] checked) {
		for(int i=1; i<graph.length; i++) {
			for(int j=1; j<graph[i].length; j++) {
				eachHouseNumber = 0;
				if(checked[i][j] == false && graph[i][j] == 1) {
					dfs(graph, checked, i, j);
					eachHouseNumberArrayList.add(eachHouseNumber);
					houseNum++;
				}
			}
		}
	}
	
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		vertex = sc.nextInt();
		sc.nextLine();
	
		int[][] graph = new int[vertex+1][vertex+1];
		boolean[][] checked = new boolean[vertex+1][vertex+1];
		
		String temp;
		
		for(int i=1; i<=vertex; i++) {
			temp = sc.nextLine();
			for(int j=1; j<=vertex; j++) {
				graph[i][j] = temp.charAt(j-1)-48;
			}
		}
		
		getHouseNum(graph, checked);
		
		System.out.println(houseNum);
		eachHouseNumberArrayList.sort(Comparator.naturalOrder());
		for(int i=0; i<eachHouseNumberArrayList.size(); i++) {
			System.out.println(eachHouseNumberArrayList.get(i));
		}
	}
}
	
