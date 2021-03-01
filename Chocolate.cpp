//Daljeet Singh
//105165075

#include <cstdio>
#include <iostream>
#include <vector>                               //declaring libraries

using namespace std;
inline int readint(){                            //to read an int
	int a = 0; char c = getchar(), f = 1;
	for(; c<'0' or c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c and c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
inline void writeint(int x){                      //to write an int
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) writeint(x/10);
	putchar(x%10+'0');
}
inline double qkpow(double base,int q){
	double ans = 1;                                                                                      // this is REAL pow
	for(; q; q>>=1,base=base*base)
		if(q&1) ans *= base;
	return ans;
}
# define sgn(x) (((x)&1) ? -1 : 1) // (-1)^x

const int MaxC = 101;                         //declaring global variables
double comb[MaxC][MaxC];
int c, n, m;

int main(){                                                  //main function
	for(int i=0; i<MaxC; ++i)
		for(int j=int(comb[i][0]=1); j<=i; ++j)                                                // Number of preprocessing combinations
			comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
	while(~scanf("%d",&c)){
		if(c == 0) break;
		n = readint(), m = readint();
		if(c < m){ puts("0"); continue ; }                                                                // impossible
		double ans = 0;
		for(int i=0; i<=c-m; ++i) for(int j=0; j<=m; ++j)
			ans += sgn(m-j)*qkpow(2*i+2*j-c,n)*comb[c-m][i]*comb[m][j];
		ans /= qkpow(2,c), ans /= qkpow(c,n), ans *= comb[c][m];
		printf("%.6f\n",ans);                                                                          // It is said that double must also be output with %f?
	}
	return 0;
}
