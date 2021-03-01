//Daljeet Singh
//105165075

#include <stdio.h>                     //declaring libraries

int main() {                                             //main function
	int K, cases = 0;
	while(scanf("%d", &K) == 1) {
		if(cases++)	puts("");                                       //using while loop
		int m = K-1;
		for(int i = 0; i < K; i++) {
			printf("%d", 1);
			for(int j = 1; j < K; j++)
				printf(" %d", i * m + j + 1);                                 //using for loop
			puts("");
		}
		
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				printf("%d", i+2);
				for(int s = 0; s < m; s++)
					printf(" %d", (j + s * i)%m + s*m + K + 1);                     //printing result
				puts("");
			}
		}
	}
	return 0;
}