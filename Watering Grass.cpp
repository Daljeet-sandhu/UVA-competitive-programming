//Daljeet Singh
//105165075

#include <iostream>
#include <cmath>                        //declaring libraries
#include <algorithm>
#include <utility>

#define EPS 1e-7
using namespace std;                               //global varibales
typedef pair<double, double> p2f;

int main() {                             //main function
    int n, l, w, p, d, cpt;
    vector<p2f> sprinklers;                       //declaring variables
    double covered;

    while(scanf("%d %d %d", &n, &l, &w) != EOF ) {                                          //while loop
        sprinklers.clear();
        for (int i = 0; i < n; ++i)
        {                                //for loop
            if(scanf("%d %d", &p, &d)){}
            if (2.0 * d < w) continue;                                                             //if condition
            double r = sqrt((double)d*d - (double)w*w/4.);
            if(p - r <= l && p + r >= 0) {
                sprinklers.push_back({p - r, p + r});
            }
        }
        sort(sprinklers.begin(), sprinklers.end());
        cpt = 0;
        covered = 0;
        for (int i = 0; i < sprinklers.size(); ++i)                                //for loop
        {
            if (covered + EPS >= l) break;
            if (covered >= sprinklers[i].second + EPS) continue;                                                             //if condition
            if (covered < sprinklers[i].first - EPS) {cpt = -1; break;}
            int j = i , u = i;
            while (j < sprinklers.size() && sprinklers[j].first - EPS <= covered) {                                          //while loop
                if(sprinklers[j].second > sprinklers[u].second) u = j;
                j++;
            }
            covered = sprinklers[u].second;
            i = u;
            cpt++;
        }
        printf("%d\n", covered + EPS >= l ? cpt : -1);                                                          //printing results
    }
    return 0;
}