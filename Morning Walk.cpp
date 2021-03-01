//	Daljeet Singh
//  105165075


#include <stdio.h>
#include <string.h>                    //declaring libraries
int deg[205];
int visited[205];                        //declaring
int g[205][205];
int n, m, x, y;
void dfs(int u) {                //dfs function
	visited[u] = 1;
	for(int i = 0; i < n; i++) {
		if(g[u][i] && visited[i] == 0)
			dfs(i);
	}
}
int main() {                                              //main function
    while(scanf("%d %d", &n, &m) == 2) {
    	memset(g, 0, sizeof(g));            //while loop
        int i, j;
        for(i = 0; i < n; i++) {
            deg[i] = 0;
            visited[i] = 1;
        }
        while(m--) {                      //while loop
            scanf("%d %d", &x, &y);
            deg[x]++, deg[y]++;
            g[x][y] = g[y][x] = 1;
            visited[x] = visited[y] = 0;
        }
        int flag = 0;
        for(i = 0; i < n; i++) {                       //for loop
            if(deg[i]%2 == 1) {
                flag = 1;
            }
        }
        if(flag)                       //if condition
            puts("Not Possible");
        else {
        	int cc = 0;
        	for(int i = 0; i < n && cc <= 1; i++)                       //for loop
        		if(visited[i] == 0)
        			dfs(i), cc++;
        	if(cc == 1)
            	puts("Possible");
            else
            	puts("Not Possible");                                                    //printing result
        }
    }
    return 0;
}