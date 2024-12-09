#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

const int MOD = 1000000007;

int main()
{
    long long l, r;
    cin >> l >> r;

    vector<int> dp(8, 0);
    dp[0] = 1;
    for(int i=0; i<63; ++i){
        int l2 = (l >> i) & 1;
        int r2 = (r >> i) & 1;
        vector<int> nextDp(8, 0);
        for(int j=0; j<8; ++j){
            for(int a=0; a<2; ++a){
                for(int b=0; b<2; ++b){
                    if(a < b)
                        continue;

                    int k = j;
                    if(a > r2)
                        k |= 1;
                    else if(a < r2)
                        k &= ~1;
                    if(b < l2)
                        k |= 2;
                    else if(b > l2)
                        k &= ~2;
                    if(a == 1 && b == 1)
                        k |= 4;
                    else if(a != b)
                        k &= ~4;

                    nextDp[k] += dp[j];
                    nextDp[k] %= MOD;
                }
            }
        }
        dp = move(nextDp);
    }
    cout << dp[4] << endl;

    return 0;
}
