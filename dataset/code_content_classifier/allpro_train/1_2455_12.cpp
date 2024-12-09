#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
#define int long long int
void fun()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

const int N = 2e5 + 7;
const int INF = 3e18+7;
const int mod = 1e9 + 7;


signed main() 
{
    fun();
    int tests = 1; cin>>tests;
    while(tests--)
    {
        int n; cin >> n;
        string s; cin >> s;
        map<pair<int, int>, int> mapp;
        int d = 0, k = 0;

        for(char ch: s) {
            if(ch == 'D') d++;
            else k++;

            int x = d, y = k;
            int g = gcd(x, y);
            x /= g; y /= g;
            mapp[make_pair(x, y)]++;

            cout << mapp[make_pair(x, y)] << ' ';
        }
        cout << '\n';

    }       
    //cerr << "time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " second \n";
    return 0;
}