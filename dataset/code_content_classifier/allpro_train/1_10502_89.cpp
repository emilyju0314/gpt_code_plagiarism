#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

using namespace std;

#define inc(a)           a.begin(), a.end()
#define dec(a)           a.rbegin(), a.rend()
#define Unique(a)        a.erase(unique(inc(a)), a.end())
#define what_is(x)       cerr << #x << " is " << x << '\n';

using ll = long long;
using ld = long double;

int dx[] = {0,  0, -1, -1, -1,  1, 1, 1};
int dy[] = {1, -1, -1,  0,  1, -1, 0, 1};

const int N = 101, M = 1E6+5, MOD = 1E9+7;
int t;
ll p, a, b, c, mini;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--){
        cin >> p >> a >> b >> c;

        mini = LLONG_MAX;
        mini = min(mini, a - p%a);
        mini = min(mini, b - p%b);
        mini = min(mini, c - p%c);

        cout << (p%a && p%b && p%c ? mini : 0) << '\n';
    }

    return 0;
}