
//Daljeet Singh
//105165075

#include <cstdio>
#include <cstring>                             //declaring libraries
 
const int N = 1005;
 
int t, n, a, sum, cnt, dp[55][55 * N];
 
int solve(int cnt, int sum) {                     //function to solve the ans
    if (sum == 1) {
	cnt++;
	sum--;
    }
    if (dp[cnt][sum] != -1) return dp[cnt][sum];
    int &ans = dp[cnt][sum];
    ans = 0; 
    if (cnt == 0 && sum == 0) return ans;
    if (cnt >= 1 && !solve(cnt - 1, sum)) ans = 1;                         //if else conditions
    if (sum >= 1 && !solve(cnt, sum - 1)) ans = 1;              
    if (cnt >= 2 && sum > 0 && !solve(cnt - 2, sum + 3)) ans = 1;
    if (cnt >= 2 && sum == 0 && !solve(cnt - 2, sum + 2)) ans = 1;
    if (cnt >= 1 && sum > 0 && !solve(cnt - 1, sum + 1)) ans = 1;
    return ans;
}
 
int main() {                                                                                  //main function
    int cas = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while (t--) {
	cnt = sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {                                 //using while n for loops
	    scanf("%d", &a);
	    if (a == 1) cnt++;
	    else sum += a;
	}
	if (cnt != n)
	    sum += n - cnt - 1;
	printf("Case #%d: %s\n", ++cas, solve(cnt, sum) ? "Alice" : "Bob");                       //printing result
    }
    return 0;
}
