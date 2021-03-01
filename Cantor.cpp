//Daljeet Singh
//105165075

#include <iostream>                        //declaring libraries
#include <cmath>
#define EPS 1e-7

using namespace std;                     //global varibale

int main(){                             //main function
    double x, a, b;                       //declaring variables
    while(scanf("%lf", &x)) {
        a = 0; 
        b = 1e6;
        x *= 1e6;
        while(true) {                                          //while loop
            if(fabs(x - a) < EPS || fabs(x - b) < EPS) {
                printf("MEMBER\n");                                                             //if condition
                break;
            }
            else if(x > a && x < a + (b - a)/3) {
                b = a + (b - a)/3;
            }
            else if(x < b && x > b - (b - a)/3) {                                                                              //else condition
                a = b - (b - a)/3;
            }
            else {
                printf("NON-MEMBER\n");                                                          //printing results
                break;
            }
        }
    }
    return 0;
}