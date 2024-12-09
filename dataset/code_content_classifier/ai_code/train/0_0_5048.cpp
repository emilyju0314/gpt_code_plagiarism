#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> t(n), T(n), x(n), cost(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> T[i] >> x[i] >> cost[i];
    }

    long long total_cost = 0;
    int max_temp = 0;

    for (int i = 0; i < n; i++) {
        max_temp = max(max_temp, t[i]);
        if (max_temp <= T[i]) {
            total_cost += x[i];
        } else {
            max_temp = T[i];
            total_cost += cost[i];
        }
    }

    cout << total_cost << endl;

    return 0;
}