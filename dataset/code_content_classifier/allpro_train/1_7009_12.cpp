#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    bool f = false;
    if (a % 2 && b % 2)
        f = true;
    if (b % 2 && c % 2)
        f = true;
    if (c % 2 && a % 2)
        f = true;
    cout << (f ? "Hom" : "Tem") << endl;
}

