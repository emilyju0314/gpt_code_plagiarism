#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;
using ll = long long;

const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<string> table(8);
    for(int i = 0; i < 8; i++) cin >> table[i];
    cout << 90 << endl;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 7; i >= 0; i--) cout << table[i][j]; cout << endl;
    }
    cout << 180 << endl;
    for(int i = 7; i >= 0; i--)
    {
        for(int j = 7; j >= 0; j--) cout << table[i][j]; cout << endl;
    }
    cout << 270 << endl;
    for(int j = 7; j >= 0; j--)
    {
        for(int i = 0; i < 8; i++) cout << table[i][j]; cout << endl;
    }
    return 0;
}


