//Daljeet Singh
//105165075

import java.util.*;             //importing

class Main{                                        //main class
	
	static int class1(long i) {
		int num = 0;
		while (i != 1) {
			if (i % 2 == 0)              //using while loop
			       {i = i/ 2;}
			else 
			       {i = 3 * i + 1;}
			num++;}
		return num+1;}
	
	public static void main(String[] args) { //main
		int i, j, k, answer;
		Scanner scanner = new Scanner(System.in);          //using scanner          
		
		while (scanner.hasNext()) {                   
			i = scanner.nextInt(); j = scanner.nextInt();           //getting input
			answer = 0;
			for (k = Math.min(i, j); k <= Math.max(i, j); k++) {
				answer = Math.max(class1(k), answer);}                                   //for loop
			System.out.println(String.format("%d %d %d",i, j, answer));                     //printing result
		}
	}
   
}