//	Daljeet Singh
//  105165075


#include <iostream>
#include <cstring>                     //declaring libraries
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int N;
int W[100 + 5];                              //declaring
long long dp[450 * 100 + 5];

void solve()                                   //solve function
{
    int sum = accumulate(W + 1, W + N + 1, 0);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1 << 0;
        
    for (int i = 1; i <= N; ++i)                        //for loop
        for (int j = sum; j >= 0; --j)
            if (dp[j])
                dp[j + W[i]] |= dp[j] << 1;
    
    int minDiff = 450 * 100;
    int teamOneWeight = 0, teamTwoWeight = 0;
    for (int i = 0; i <= sum; ++i)
        if (dp[i] & (1ll << (N / 2)))                                                     //for loop
        {
            int diff = abs(i - (sum - i));
            if (diff < minDiff)
            {
                minDiff = diff;
                teamOneWeight = min(i, sum - i);
                teamTwoWeight = max(i, sum - i);
            }
        }
    cout << teamOneWeight << " " << teamTwoWeight << endl;                                                     //printing result
}

int main()                                                  //main function
{
    int T, Case = 0;
    cin >> T;
    while ( T-- )                                             //while loop
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)                                    //for loop
            cin >> W[i];
        
        if (++Case > 1)                 //if condition
            cout << endl;
        solve();
    }
}