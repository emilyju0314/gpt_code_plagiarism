#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
T gcd(const T a, const T b)
{
    return (b != 0) ? gcd(b, a % b) : a;
}

template <typename T>
T lcm(const T a, const T b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int N;
    cin >> N;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;

    return 0;
}

