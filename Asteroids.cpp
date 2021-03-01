//Daljeet Singh
//105165075

#include <iostream>
#include <iomanip> 
#include <math.h>                        //declaring libraries
#include <vector>
#include <algorithm>


int main() {           //main function
    int i,j,k;
    long double na,nb,a,b,va,vb,frst,lst,maxw;                        //declaring variables

    freopen("1710.in","r",stdin);
    for(unit.x[0]=1;1==scanf("%d",n) && 0[n];) {        
        for ( i = 0; i < n[0]; ++i ) 
            scanf("%Lf %Lf",c[0][i].x,c[0][i].x+1), sc[0][i] = c[0][i];                                //for loop
        scanf("%Lf %Lf",v[0].x,v[0].x+1);
        for ( scanf("%d",n+1), i = 0; i < n[1]; ++i ) 
            scanf("%Lf %Lf",c[1][i].x,c[1][i].x+1);
        scanf("%Lf %Lf",v[1].x,v[1].x+1);
        for ( k = 0; k <= 1; ++k )
            for ( i = 0; i < n[k]; d[k][i] = c[k][(i+1)%n[k]]-c[k][i], ++i );
        for ( i = 0; i <= 1; ++i )
            dir[i] = v[i^1]-v[i];
        if ( !first_encounter(a) ) {                                                              //if condition
            puts("never");
            continue ;
        }
        for ( last_encounter(b), frst = a, lst = b; b-a >= 1e-12; ) {
            na = (2*a+b)/3.00, nb = (2*b+a)/3.00;
            shift_by(na), construct_polygon(), va = area(poly,m);                                //for loop
            shift_by(nb), construct_polygon(), vb = area(poly,m);
            if ( va < vb-tol ) 
                a = na;
            else b = nb;                                                                              //else condition
        }
        assert( lst >= frst );
        shift_by((a+b)/2.00), construct_polygon(), va = area(poly,m);
        printf("%Lf\n",(a+b)/2);                                                            //printing results
    }
    return 0;
};