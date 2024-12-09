#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<long long> prefix_sum(n+1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + w[i-1];
    }

    long long min_energy = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        long long energy = i*l + (n-i)*r;
        energy += prefix_sum[i]*Ql + (prefix_sum[n]-prefix_sum[i])*Qr;
        min_energy = min(min_energy, energy);
    }

    cout << min_energy << endl;

    return 0;
}