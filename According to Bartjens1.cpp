#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

char inter = 'A';
//define operator
char operation [3] = {'+', '-', '*'};
char s [30];
int n;//How many positions can be filled
int md;//How many positions have symbols inserted
set <string> ans;//Set the result set
vector <int> pos;//Store the filling position in the current situation

bool isnumber (char ch)
{
    return ch> = '0' && ch <= '9';
}

//Get the number --- if it is * connected, it needs to be calculated here-knowing that it encounters a + or minus sign
int getnum (int * p)
{
    char num [10];
    int j = 0;
    while (* p <2 * n + 1 && s [* p]! = '+' && s [* p]! = '-') {
        if (isnumber (s [* p])) {
            num [j ++] = s [* p];
        }
        else {
            if (s [* p] == '*') {
                if (num [0] == '0' && j> 1) {
                    return -1;
                }
                else {
                    num [j] = '\0';
                    ++ (* p);
                    int t = getnum (p);
                    if (t! =-1) {
                        return atoi (num) * t;
                    }
                    return -1;
                }
            }
        }
        (* p) ++;
    }
    num [j] = '\0';
    if (num [0] == '0' && j> 1) {
        return -1;
    }
    
    return atoi (num);
}



//Operation function
int run (int a, int b, char operation)
{
    switch (operation) {
        case '+':
            return a + b;
            break;
        case '-':
            return a-b;
        default:
            return a * b;
            break;
    }
}

//judge whether it is equal to 2000
bool equal2000 ()
{
    int a = 0, b, ope = '+';
    for (int i = 0; i <2 * n + 1; i ++) {
        if (isnumber (s [i])) {
            b = getnum (& i);
            if (b ==-1)
            {
                return false;
            }
            i--;
            a = run (a, b, ope);
        }
        else if (s [i] == '+' || s [i] == '-')
        {
            ope = s [i];
        }
    }
    return a == 2000? true: false;
}



void dfs (int d)
{
    if (d == md) {
        if (equal2000 ()) {
            string result;
            for (int i = 0; i <2 * n + 1; i ++) {
                if (isnumber (s [i]) || s [i] == '*' || s [i] == '+' || s [i] == '-')
                {
                    result.operator + = (s [i]);
                }
            }
            
            ans.insert (result);
        }
    }
    else
    {
        for (int i = 0; i <3; i ++) {
            s [pos [d] * 2 + 1] = operation [i];
            dfs (d + 1);
        }
    }
}


void solved ()
{
    int end = 1 << n;
    for (int i = 1; i <end; i ++)
    {
        pos.clear ();
        for (int j = 0; j <n; j ++) {
            if (i & (1 << j)) {
                pos.push_back (j);
            }
        }
        md = (int) pos.size ();
        dfs (0);
//int len ​​= (int) pos.size ();
        for (int j = 0; j <md; j ++) {
            s [2 * pos [j] +1] = inter;
        }
    }
}

int main () {
    char temp [15];
    int casenum = 0;
    while (scanf ("% s", temp) == 1 && temp [0]! = '=') {
        int len ​​= (int) strlen (temp);
        s [len-1] = '\0';
        for (int i = 0; i <len-1; i ++) {
            s [i * 2] = temp [i]; s [i * 2 + 1] = inter;
        }
        s [2 * (len-2) +1] = '\0';
        n = len -2;
        ans.clear ();
        solved ();
        len = (int) ans.size ();
        cout << "Problem" << ++ casenum << endl;
        if (len == 0) {
            printf ("IMPOSSIBLE\n");
        }
        else {
            for (set <string> :: iterator it = ans.begin (); it! = ans.end (); it ++) {
                cout << "" << * it << "=" << endl;
            }
        }
    }
    
    return 0;
}






