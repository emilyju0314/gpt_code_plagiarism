#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;

/* typedef */
typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;

/* global variables */

/* function */

/* main */
int main(){

    int n, m, x;
    cin >> n >> m;
    bitset<18> mask(0);
    for (int i = 0; i < m; i++) {
        cin >> x;
        mask.set(x);
    }
    // Print bit if binary(i) includes mask bits
    /*
    // 1 ============================
    for (int i = 0; i < (1 << n); i++) {
        bitset<18> bs(i);
        if ((bs & mask) == mask) {
            printf("%d:", i);
            for (int j = 0; j < n; j++) {
                if ((bs >> j)[0]) printf(" %d", j);
            } 
            printf("\n");
        }
    }
    */

    int mask_int = mask.to_ulong();
    // 2 ===========================
    for (int b = 0; b < (1 << n); b++) {
        if ((b & mask_int) == mask_int) {
            printf("%d:", b);
            for (int i = 0; i < n;i++)
                if( (b >> i) & 1)
                    printf(" %d", i);
            printf("\n");
        }
    }
}

