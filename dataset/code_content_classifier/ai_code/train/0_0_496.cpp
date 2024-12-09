#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(m);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    ll total_area = 0;

    ll sum_x = 0;
    for (int i = 0; i < n-1; i++) {
        sum_x = (sum_x + (ll)(x[i+1] - x[i])*(i+1)*(n-i-1)) % MOD;
    }

    ll sum_y = 0;
    for (int i = 0; i < m-1; i++) {
        sum_y = (sum_y + (ll)(y[i+1] - y[i])*(i+1)*(m-i-1)) % MOD;
    }

    total_area = (sum_x * sum_y) % MOD;

    cout << total_area << endl;

    return 0;
}