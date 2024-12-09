#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll y = 1;
    while (y * (y + 1) / 2 <= n) y++;
    ll avoid = y * (y + 1) / 2 - n;
    for (int i = 1; i <= y; ++i) if (i != avoid) cout << i << endl;
}
