#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<bool> is_in_S(n, false);
    int min_cost = 0;
    vector<int> min_costs(n);
    for (int i = 1; i < n; i++) {
        int jump_cost = a[i] - a[i-1];
        min_cost += jump_cost;
        min_costs[i] = min_cost;
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;

        is_in_S[x] = !is_in_S[x];

        for (int j = x + 1; j < n; j++) {
            if (is_in_S[j]) {
                min_cost += b[j] - a[j-1];
            } else {
                min_cost -= b[j] - a[j-1];
            }
        }

        for (int j = x; j < n - 1; j++) {
            min_costs[j + 1] = min(min_costs[j+1], min_cost);
        }

        cout << min_cost << endl;
    }

    return 0;
}